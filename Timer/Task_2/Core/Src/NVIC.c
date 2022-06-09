/*
 * NVIC.c
 *
 *  Created on: May 28, 2022
 *      Author: Heba Elbeshbeshy
 */

#include "NVIC.h"

uint32_t *NVIC_ISER0() {return (uint32_t *)Peripheral_REG((uint32_t)0xE000E100u, (uint32_t)0x00u);}

void NVIC_EnableTimerInterrupt(uint8_t TIM)
{
	*NVIC_ISER0() |= ((uint32_t)0x01 << ((uint32_t)26 + (uint32_t)TIM));
}
