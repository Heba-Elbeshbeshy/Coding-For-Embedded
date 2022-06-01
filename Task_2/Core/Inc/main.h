/*
 * main.h
 *
 *  Created on: May 28, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

typedef          char   char_t;
typedef signed   char   int8_t;
typedef signed   short  int16_t;
typedef signed   int    int32_t;
typedef signed   long   int64_t;
typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;
typedef unsigned long   uint64_t;
typedef          float  float32_t;
typedef          double float64_t;
typedef long     double float128_t;

/* Generic macro */
uint32_t Peripheral_REG( uint32_t PORT_ID, uint32_t REG_ID);

#endif /* INC_MAIN_H_ */
