/*
 * crc.c
 *
 *  Created on: 27 de ago. de 2021
 *      Author: giuli
 */

#include "crc.h"

uint16_t prot_crc(uint8_t* buffer, uint16_t size)
{
  unsigned short tmp;
  uint16_t crc = 0xffff;

  for (uint16_t i=0; i < size ; i++)
  {
    tmp = (crc >> 8) ^ buffer[i];
    crc = (crc << 8) ^ CRC_CCITT_TABLE[tmp];
  }

  return crc;
}
