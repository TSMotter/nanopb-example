/*
 * main.c
 *
 *  Created on: 12 de ago. de 2021
 *      Author: Giuliano Motter
 */
/***************************************************************************************************
* Includes
***************************************************************************************************/
#include <stdbool.h>
#include <stdio.h>

#include "crc.h"
#include "ring_buffer.h"
#include "pb_encode.h"
#include "pb_decode.h"
#include "protocol.pb.h"

/***************************************************************************************************
* Defines
***************************************************************************************************/
#define RB_LEN 1024
#define TEST_STRING "AB"
#define TEST_HEX {0x44, 0x3a, 0xdc, 0x0a, 0x69, 0xd2, 0x6d, 0x00, 0x61, 0x72, 0x00, 0x5f, 0x67, \
									0x0d, 0x75, 0x6c, 0x69, 0xf1, 0x6e, 0x6f, 0xfc, 0x6e, 0x61, 0xee, 0x6f, 0x70, 0xe2};

#define VAL_SOF 0x02
#define VAL_EOF 0x03
#define VAL_CRC_NONE 0xffff

/***************************************************************************************************
* Private Prototypes
***************************************************************************************************/
static bool my_complete_encoding_func(pb_ostream_t *stream, const pb_msgdesc_t *fields, uart_frame *src_struct, size_t *sz);
static bool custom_decode_cb(pb_istream_t *stream, pb_byte_t *buf, size_t count);
static bool custom_encode_cb(pb_ostream_t *stream, const pb_byte_t *buf, size_t count);
static bool custom_field_decoding_cb(pb_istream_t *stream, const pb_field_iter_t *field, void **arg);
static bool custom_field_encoding_cb(pb_ostream_t *stream, const pb_field_iter_t *field, void *const *arg);

/***************************************************************************************************
* Vars
***************************************************************************************************/
static RINGBUFF_T RbEncode, RbDecode;
static uint8_t RbEncodeBuffer[RB_LEN] = {0}, RbDecodeBuffer[RB_LEN] = {0};

/***************************************************************************************************
* Types
***************************************************************************************************/
typedef struct
{
	RINGBUFF_T *RB;
	bool sof_ok;
	bool eof_ok;
	uint32_t crc_val;
} my_custom_cb_st;

/***************************************************************************************************
* @brief
***************************************************************************************************/
int main(void)
{
	// ENCODING PROCESS
	size_t message_length = 0;
	uart_frame message_encode = uart_frame_init_zero;
	RingBuffer_Init(&RbEncode, RbEncodeBuffer, sizeof(uint8_t), RB_LEN);
	my_custom_cb_st oCbData = {.RB = &RbEncode, .sof_ok = false, .eof_ok = false, .crc_val = VAL_CRC_NONE};
	pb_ostream_t oStream = {&custom_encode_cb, (void *)&oCbData, SIZE_MAX, 0};

	message_encode.has_my_cmd = true;
	message_encode.my_cmd.has_Id = true;
	message_encode.my_cmd.Id = Id_en_RTC_MSG_Id;
	message_encode.my_cmd.which_SubId = uart_frame_uart_command_SubId_led_tag;
	message_encode.my_cmd.SubId.SubId_led = LED_SubId_en_LED_PWM_SubId;
	message_encode.my_cmd.Data.size = strlen(TEST_STRING);
	memcpy(message_encode.my_cmd.Data.bytes, TEST_STRING, message_encode.my_cmd.Data.size);

	my_complete_encoding_func(&oStream, uart_frame_fields, &message_encode, &message_length);

	// DECODING PROCESS
	bool status_decode = false;
	uart_frame message_decode = uart_frame_init_zero;
	RingBuffer_Init(&RbDecode, RbDecodeBuffer, sizeof(uint8_t), RB_LEN);
	my_custom_cb_st iCbData = {.RB = &RbDecode, .sof_ok = false, .eof_ok = false, .crc_val = VAL_CRC_NONE};
	pb_istream_t iStream = {&custom_decode_cb, (void *)&iCbData, SIZE_MAX};

	message_decode.my_sof.funcs.decode = &custom_field_decoding_cb;
	message_decode.my_eof.funcs.decode = &custom_field_decoding_cb;
	message_decode.my_crc.funcs.decode = &custom_field_decoding_cb;

	uint8_t dummy[40] = {0};
	RingBuffer_PopMult(&RbEncode, dummy, message_length);
	RingBuffer_InsertMult(&RbDecode, dummy, message_length);
	printf("Decoding all bytes at once...\n");
	while (1)
	{
		iStream.bytes_left = SIZE_MAX;
		status_decode = pb_decode(&iStream, uart_frame_fields, &message_decode);
		if (status_decode)
		{
			printf("Decoded! ID:%d // subID:%d // Data: %s\n",
						 message_decode.my_cmd.Id, message_decode.my_cmd.SubId.SubId_led, (char *)message_decode.my_cmd.Data.bytes);

			printf("Raw decoded: ");
			for (uint8_t k = 0; k < message_length; k++)
			{
				printf(" %02x", RbDecodeBuffer[k]);
			}
			printf("\n");

			status_decode = false;
			return 0;
		}
	}

	return 0;
}

/***************************************************************************************************
* @brief
***************************************************************************************************/
static bool my_complete_encoding_func(pb_ostream_t *stream, const pb_msgdesc_t *fields, uart_frame *src_struct, size_t *sz)
{
	bool rc = false;
	my_custom_cb_st *fd = (my_custom_cb_st *)stream->state;

	src_struct->my_sof.funcs.encode = NULL;
	src_struct->my_eof.funcs.encode = NULL;
	src_struct->my_crc.funcs.encode = NULL;
	src_struct->my_crc.arg = 0;

	if (!pb_encode(stream, uart_frame_fields, src_struct))
	{
		return false;
	}
	*sz = stream->bytes_written;

	uint32_t local_crc = prot_crc((uint8_t *)fd->RB->data, *sz);

	printf("Encoded Parcial! [%d] ID:%d // subID:%d // Data:%s\n",
				 *sz, src_struct->my_cmd.Id, src_struct->my_cmd.SubId.SubId_led, (char *)src_struct->my_cmd.Data.bytes);
	printf("Raw encoded: ");
	for (uint8_t k = 0; k < *sz; k++)
	{
		printf(" %02x", RbEncodeBuffer[k]);
	}
	printf("\n");
	printf("CRC:%08x\n", local_crc);

	stream->bytes_written = 0;
	RingBuffer_Flush(fd->RB);

	src_struct->my_sof.funcs.encode = &custom_field_encoding_cb;
	src_struct->my_eof.funcs.encode = &custom_field_encoding_cb;
	src_struct->my_crc.funcs.encode = &custom_field_encoding_cb;
	src_struct->my_crc.arg = (void *)local_crc;

	rc = pb_encode(stream, uart_frame_fields, src_struct);
	*sz = stream->bytes_written;

	printf("Encoded Final! [%d] ID:%d // subID:%d // Data:%s\n",
				 *sz, src_struct->my_cmd.Id, src_struct->my_cmd.SubId.SubId_led, (char *)src_struct->my_cmd.Data.bytes);
	printf("Raw encoded: ");
	for (uint8_t k = 0; k < *sz; k++)
	{
		printf(" %02x", RbEncodeBuffer[k]);
	}
	printf("\n");

	return rc;
}

/***************************************************************************************************
* @brief
***************************************************************************************************/
static bool custom_decode_cb(pb_istream_t *stream, pb_byte_t *buf, size_t count)
{
	my_custom_cb_st *fd = (my_custom_cb_st *)stream->state;

	if (count == 0)
	{
		return true;
	}

	// Condição de EOF
	if ((fd->sof_ok == true) && (fd->eof_ok == true))
	{
		printf("EOF!!!\n");
		stream->bytes_left = 0;
		fd->sof_ok = false;
		fd->eof_ok = false;
		fd->crc_val = VAL_CRC_NONE;
		return false;
	}

	RingBuffer_PopMult(fd->RB, buf, count);

	printf("decode_cb!-> count:%d, *buf:%02x\n", count, *buf);

	return true;
}

/***************************************************************************************************
* @brief
***************************************************************************************************/
static bool custom_encode_cb(pb_ostream_t *stream, const pb_byte_t *buf, size_t count)
{
	my_custom_cb_st *fd = (my_custom_cb_st *)stream->state;

	printf("encode_cb!-> count:%d, *buf:%02x\n", count, *buf);

	return RingBuffer_InsertMult(fd->RB, buf, count) == count;
}

/***************************************************************************************************
* @brief In decoding mode, the callback is called repeatedly for every data item.
***************************************************************************************************/
static bool custom_field_decoding_cb(pb_istream_t *stream, const pb_field_iter_t *field, void **arg)
{
	printf("custom_field_decoding_cb!-> Start\n");

	my_custom_cb_st *fd = (my_custom_cb_st *)stream->state;

	bool rc = true;
	uint32_t dummy = 0;

	// Decoda o dado do campo
	if (field->tag == uart_frame_my_sof_tag)
	{
		//printf("(1)-> tag:%d, left:%d\n", field->tag, stream->bytes_left);
		rc = pb_decode_varint32(stream, &dummy);
		//printf("(2)-> tag:%d, left:%d, dummy:%02x\n", field->tag, stream->bytes_left, dummy);
		if (rc)
		{
			fd->sof_ok = true;
		}
	}
	else if (field->tag == uart_frame_my_eof_tag)
	{
		//printf("(1)-> tag:%d, left:%d\n", field->tag, stream->bytes_left);
		rc = pb_decode_varint32(stream, &dummy);
		//printf("(2)-> tag:%d, left:%d, dummy:%02x\n", field->tag, stream->bytes_left, dummy);
		if (rc)
		{
			fd->eof_ok = true;
		}
	}
	else if (field->tag == uart_frame_my_crc_tag)
	{
		//printf("(1)-> tag:%d, left:%d\n", field->tag, stream->bytes_left);
		rc = pb_decode_varint32(stream, &dummy);
		//printf("(2)-> tag:%d, left:%d, dummy:%02x\n", field->tag, stream->bytes_left, dummy);
		rc = true;
	}

	printf("custom_field_decoding_cb!-> End\n");
	return rc;
}

/***************************************************************************************************
* @brief In encoding mode, the callback is called once and should write out everything including field tags.
***************************************************************************************************/
static bool custom_field_encoding_cb(pb_ostream_t *stream, const pb_field_iter_t *field, void *const *arg)
{
	printf("custom_field_encoding_cb!-> tag:%d // arg:%08x\n", field->tag, *(uint32_t *)arg);

	// Encoda a tag do campo
	if (!pb_encode_tag_for_field(stream, field))
	{
		return false;
	}

	// Encoda o dado do campo
	if (field->tag == uart_frame_my_sof_tag)
	{
		uint8_t sof = VAL_SOF;
		return pb_encode_string(stream, &sof, 1);
	}
	else if (field->tag == uart_frame_my_eof_tag)
	{
		uint8_t eof = VAL_EOF;
		return pb_encode_string(stream, &eof, 1);
	}
	else if (field->tag == uart_frame_my_crc_tag)
	{
		uint32_t *local_crc = (uint32_t *)arg;
		return pb_encode_string(stream, (uint8_t *)local_crc, 2);
	}

	// Erro...
	return false;
}
