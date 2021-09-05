/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.5 */

#ifndef PB_PROTOCOL_PB_H_INCLUDED
#define PB_PROTOCOL_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _Id_en { 
    Id_en_LED_MSG_Id = 0, 
    Id_en_RTC_MSG_Id = 1 
} Id_en;

typedef enum _LED_SubId_en { 
    LED_SubId_en_LED_OFF_SubId = 0, 
    LED_SubId_en_LED_ON_SubId = 1, 
    LED_SubId_en_LED_PWM_SubId = 2 
} LED_SubId_en;

typedef enum _RTC_SubId_en { 
    RTC_SubId_en_RTC_SET_ALARM_SubId = 0 
} RTC_SubId_en;

/* Struct definitions */
typedef PB_BYTES_ARRAY_T(50) uart_frame_uart_command_Data_t;
typedef struct _uart_frame_uart_command { 
    bool has_Id;
    Id_en Id; 
    pb_size_t which_SubId;
    union {
        LED_SubId_en SubId_led;
        RTC_SubId_en SubId_rtc;
    } SubId; 
    bool has_Action;
    uint32_t Action; 
    uart_frame_uart_command_Data_t Data; 
} uart_frame_uart_command;

typedef struct _uart_frame { 
    pb_callback_t my_sof; 
    bool has_my_cmd;
    uart_frame_uart_command my_cmd; 
    pb_callback_t my_crc; 
    pb_callback_t my_eof; 
} uart_frame;


/* Helper constants for enums */
#define _Id_en_MIN Id_en_LED_MSG_Id
#define _Id_en_MAX Id_en_RTC_MSG_Id
#define _Id_en_ARRAYSIZE ((Id_en)(Id_en_RTC_MSG_Id+1))

#define _LED_SubId_en_MIN LED_SubId_en_LED_OFF_SubId
#define _LED_SubId_en_MAX LED_SubId_en_LED_PWM_SubId
#define _LED_SubId_en_ARRAYSIZE ((LED_SubId_en)(LED_SubId_en_LED_PWM_SubId+1))

#define _RTC_SubId_en_MIN RTC_SubId_en_RTC_SET_ALARM_SubId
#define _RTC_SubId_en_MAX RTC_SubId_en_RTC_SET_ALARM_SubId
#define _RTC_SubId_en_ARRAYSIZE ((RTC_SubId_en)(RTC_SubId_en_RTC_SET_ALARM_SubId+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define uart_frame_init_default                  {{{NULL}, NULL}, false, uart_frame_uart_command_init_default, {{NULL}, NULL}, {{NULL}, NULL}}
#define uart_frame_uart_command_init_default     {false, _Id_en_MIN, 0, {_LED_SubId_en_MIN}, false, 0, {0, {0}}}
#define uart_frame_init_zero                     {{{NULL}, NULL}, false, uart_frame_uart_command_init_zero, {{NULL}, NULL}, {{NULL}, NULL}}
#define uart_frame_uart_command_init_zero        {false, _Id_en_MIN, 0, {_LED_SubId_en_MIN}, false, 0, {0, {0}}}

/* Field tags (for use in manual encoding/decoding) */
#define uart_frame_uart_command_Id_tag           11
#define uart_frame_uart_command_SubId_led_tag    12
#define uart_frame_uart_command_SubId_rtc_tag    13
#define uart_frame_uart_command_Action_tag       14
#define uart_frame_uart_command_Data_tag         15
#define uart_frame_my_sof_tag                    1
#define uart_frame_my_cmd_tag                    2
#define uart_frame_my_crc_tag                    3
#define uart_frame_my_eof_tag                    4

/* Struct field encoding specification for nanopb */
#define uart_frame_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, BYTES,    my_sof,            1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  my_cmd,            2) \
X(a, CALLBACK, OPTIONAL, BYTES,    my_crc,            3) \
X(a, CALLBACK, OPTIONAL, BYTES,    my_eof,            4)
#define uart_frame_CALLBACK pb_default_field_callback
#define uart_frame_DEFAULT NULL
#define uart_frame_my_cmd_MSGTYPE uart_frame_uart_command

#define uart_frame_uart_command_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UENUM,    Id,               11) \
X(a, STATIC,   ONEOF,    UENUM,    (SubId,SubId_led,SubId.SubId_led),  12) \
X(a, STATIC,   ONEOF,    UENUM,    (SubId,SubId_rtc,SubId.SubId_rtc),  13) \
X(a, STATIC,   OPTIONAL, UINT32,   Action,           14) \
X(a, STATIC,   SINGULAR, BYTES,    Data,             15)
#define uart_frame_uart_command_CALLBACK NULL
#define uart_frame_uart_command_DEFAULT NULL

extern const pb_msgdesc_t uart_frame_msg;
extern const pb_msgdesc_t uart_frame_uart_command_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define uart_frame_fields &uart_frame_msg
#define uart_frame_uart_command_fields &uart_frame_uart_command_msg

/* Maximum encoded size of messages (where known) */
/* uart_frame_size depends on runtime parameters */
#define uart_frame_uart_command_size             62

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
