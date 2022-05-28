/*
 * NVIC.h
 *
 *  Created on: May 28, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_NVIC_H_
#define INC_NVIC_H_

#include "main.h"
// NVIC
#define NVIC_ISER0      Peripheral_REG(0xE000E100, 0x00)

void NVIC_EnableTimerInterrupt(unsigned char TIM);

#endif /* INC_NVIC_H_ */
