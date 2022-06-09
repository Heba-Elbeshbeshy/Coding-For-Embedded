/*
 * GPTIM.h
 *
 *  Created on: May 27, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_GPTIM_H_
#define INC_GPTIM_H_

#include "main.h"

#define UIF ((unsigned char)0)
#define TIF ((unsigned char)6)

#define UPCOUNTER ((unsigned char)0)
#define DOWNCOUNTER ((unsigned char)1)

uint32_t *RCC_APB1ENR(void);

uint32_t *TIMx_CR1(uint8_t x);
uint32_t *TIMx_DIER(uint8_t x);
uint32_t *TIMx_SR(uint8_t x);
uint32_t *TIMx_EGR(uint8_t x);
uint32_t *TIMx_CNT(uint8_t x);
uint32_t *TIMx_PSC(uint8_t x);
uint32_t *TIMx_ARR(uint8_t x);


void TIM_EnableClock(uint8_t Id);
void TIM_Init(uint8_t Id, uint8_t CounterMode, uint32_t CounterValue, uint16_t Prescaler);
void TIM_Start(uint8_t Id);
void TIM_Stop(uint8_t Id);
uint8_t TIM_CheckFlag(uint8_t Id, uint8_t Flag);
void TIM2_Callout(void);
void TIM2_IRQHandler(void);

#endif /* INC_GPTIM_H_ */
