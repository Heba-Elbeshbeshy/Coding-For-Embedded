/*
 * GPTIM.c
 *
 *  Created on: May 27, 2022
 *      Author: Heba Elbeshbeshy
 */

#include "GPTIM.h"

unsigned int *LOOKUPTIM[4][7] =
{
 {TIM2_CR1, TIM2_DIER, TIM2_SR, TIM2_EGR, TIM2_CNT, TIM2_PSC, TIM2_ARR},
 {TIM3_CR1, TIM3_DIER, TIM3_SR, TIM3_EGR, TIM3_CNT, TIM3_PSC, TIM3_ARR},
 {TIM4_CR1, TIM4_DIER, TIM4_SR, TIM4_EGR, TIM4_CNT, TIM4_PSC, TIM4_ARR},
 {TIM5_CR1, TIM5_DIER, TIM5_SR, TIM5_EGR, TIM5_CNT, TIM5_PSC, TIM5_ARR}
};

void TIM_EnableClock(unsigned char Id)
{
	*RCC_APB1ENR |= (0x01 << (Id-2));
}

void TIM_Init(unsigned char Id, unsigned char CounterMode, unsigned int CounterValue, unsigned short Prescaler)
{
	*LOOKUPTIM[Id-2][0] |= (0x01 << 7);
    *LOOKUPTIM[Id-2][0] |= (CounterMode << 4);
    *LOOKUPTIM[Id-2][5]  = Prescaler;
	*LOOKUPTIM[Id-2][6]  = CounterValue;
}

void TIM_Start(unsigned char Id)
{
	*LOOKUPTIM[Id-2][1] |= (0x01 << 0);
	*LOOKUPTIM[Id-2][0] |= (0x01 << 0);

}

void TIM_Stop(unsigned char Id)
{
	*LOOKUPTIM[Id-2][1] &= ~(0x01 << 0);

}

unsigned char TIM_CheckFlag(unsigned char Id, unsigned char Flag)
{
	return ((*LOOKUPTIM[Id-2][2]) & (0x01 << Flag));
}

void TIM2_IRQHandler(void)
{
	TIM2_Callout();
	*LOOKUPTIM[0][2] = 0x0000; //TIM2
}
