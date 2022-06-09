/*
 * NVIC.c
 *
 *  Created on: May 28, 2022
 *      Author: Heba Elbeshbeshy
 */

#include "NVIC.h"

void NVIC_EnableTimerInterrupt(unsigned char TIM)
{
	*NVIC_ISER0 |= (0x01 << (28 + (TIM - 2)));
}
