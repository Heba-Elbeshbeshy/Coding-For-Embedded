/*
 * GPTIM.c
 *
 *  Created on: May 27, 2022
 *      Author: Heba Elbeshbeshy
 */

#include "GPTIM.h"
#include "main.h"


uint32_t *RCC_APB1ENR(void) { return (uint32_t *)Peripheral_REG((uint32_t)0x40023800, (uint32_t)0x40);}

uint32_t *TIMx_CR1(uint8_t x)  { return (uint32_t *)Peripheral_REG( ( (uint32_t)0x40000000 + ((uint32_t)0x400 * (uint32_t)(x)) ) , (uint32_t)(0x00) ); }
uint32_t *TIMx_DIER(uint8_t x) { return (uint32_t *)Peripheral_REG( ( (uint32_t)0x40000000 + ((uint32_t)0x400 * (uint32_t)(x)) ) , (uint32_t)(0x0C) ); }
uint32_t *TIMx_SR(uint8_t x)   { return (uint32_t *)Peripheral_REG( ( (uint32_t)0x40000000 + ((uint32_t)0x400 * (uint32_t)(x)) ) , (uint32_t)(0x10) ); }
uint32_t *TIMx_EGR(uint8_t x)  { return (uint32_t *)Peripheral_REG( ( (uint32_t)0x40000000 + ((uint32_t)0x400 * (uint32_t)(x)) ) , (uint32_t)(0x14) ); }
uint32_t *TIMx_CNT(uint8_t x)  { return (uint32_t *)Peripheral_REG( ( (uint32_t)0x40000000 + ((uint32_t)0x400 * (uint32_t)(x)) ) , (uint32_t)(0x24) ); }
uint32_t *TIMx_PSC(uint8_t x)  { return (uint32_t *)Peripheral_REG( ( (uint32_t)0x40000000 + ((uint32_t)0x400 * (uint32_t)(x)) ) , (uint32_t)(0x28) ); }
uint32_t *TIMx_ARR(uint8_t x)  { return (uint32_t *)Peripheral_REG( ( (uint32_t)0x40000000 + ((uint32_t)0x400 * (uint32_t)(x)) ) , (uint32_t)(0x2C) ); }

void TIM_EnableClock(uint8_t Id)
{
	*RCC_APB1ENR() |= ((uint32_t)0x01 << (Id - (uint8_t)2));
}

void TIM_Init(uint8_t Id, uint8_t CounterMode, uint32_t CounterValue, uint16_t Prescaler)
{
    *TIMx_CR1(Id - (uint8_t)2) |= ((uint32_t)1u << 7);
    *TIMx_CR1(Id - (uint8_t)2) |= ((uint32_t)CounterMode << 4);
    *TIMx_PSC(Id - (uint8_t)2)  = Prescaler;
    *TIMx_ARR(Id - (uint8_t)2)  = CounterValue;
}

void TIM_Start(uint8_t Id)
{
	*TIMx_DIER(Id - (uint8_t)2) |= ((uint32_t)0x01u << 0);
	*TIMx_CR1(Id - (uint8_t)2)  |= ((uint32_t)0x01u << 0);
}

void TIM_Stop(uint8_t Id)
{
	*TIMx_DIER(Id - (uint8_t)2) &= ~((uint32_t)0x01u << 0);

}

uint8_t TIM_CheckFlag(uint8_t Id, uint8_t Flag)
{
	return (uint8_t)(*TIMx_CR1(Id - (uint8_t)2) & ((uint32_t)1u << Flag));
}

void TIM2_IRQHandler(void)
{
	TIM2_Callout();
	*TIMx_CR1((uint8_t)0) = (uint32_t)0x0000u; /* TIM2 */
}
