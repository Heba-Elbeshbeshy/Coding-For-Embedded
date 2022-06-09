/*
 * NVIC.h
 *
 *  Created on: May 28, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_NVIC_H_
#define INC_NVIC_H_

#include "main.h"


/* NVIC */

uint32_t *NVIC_ISER0(void);

void NVIC_EnableTimerInterrupt(uint8_t TIM);

#endif /* INC_NVIC_H_ */
