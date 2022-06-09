/*
 * GPTIM.h
 *
 *  Created on: May 27, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_GPTIM_H_
#define INC_GPTIM_H_

#include "main.h"

//#define TIM_2 ((unsigned char)0)
//#define TIM_3 ((unsigned char)1)
//#define TIM_4 ((unsigned char)2)

#define UIF ((unsigned char)0)
#define TIF ((unsigned char)6)

#define UPCOUNTER ((unsigned char)0)
#define DOWNCOUNTER ((unsigned char)1)

#define RCC_APB1ENR Peripheral_REG(0x40023800,0x40)

#define TIM2_CR1  Peripheral_REG(0x40000000, 0x00)
#define TIM2_DIER Peripheral_REG(0x40000000, 0x0C)
#define TIM2_SR   Peripheral_REG(0x40000000, 0x10)
#define TIM2_EGR  Peripheral_REG(0x40000000, 0x14)
#define TIM2_CNT  Peripheral_REG(0x40000000, 0x24)
#define TIM2_PSC  Peripheral_REG(0x40000000, 0x28)
#define TIM2_ARR  Peripheral_REG(0x40000000, 0x2C)

#define TIM3_CR1  Peripheral_REG(0x40000400, 0x00)
#define TIM3_DIER Peripheral_REG(0x40000400, 0x0C)
#define TIM3_SR   Peripheral_REG(0x40000400, 0x10)
#define TIM3_EGR  Peripheral_REG(0x40000400, 0x14)
#define TIM3_CNT  Peripheral_REG(0x40000400, 0x24)
#define TIM3_PSC  Peripheral_REG(0x40000400, 0x28)
#define TIM3_ARR  Peripheral_REG(0x40000400, 0x2C)

#define TIM4_CR1  Peripheral_REG(0x40000800, 0x00)
#define TIM4_DIER Peripheral_REG(0x40000800, 0x0C)
#define TIM4_SR   Peripheral_REG(0x40000800, 0x10)
#define TIM4_EGR  Peripheral_REG(0x40000800, 0x14)
#define TIM4_CNT  Peripheral_REG(0x40000800, 0x24)
#define TIM4_PSC  Peripheral_REG(0x40000800, 0x28)
#define TIM4_ARR  Peripheral_REG(0x40000800, 0x2C)

#define TIM5_CR1  Peripheral_REG(0x40000C00, 0x00)
#define TIM5_DIER Peripheral_REG(0x40000C00, 0x0C)
#define TIM5_SR   Peripheral_REG(0x40000C00, 0x10)
#define TIM5_EGR  Peripheral_REG(0x40000C00, 0x14)
#define TIM5_CNT  Peripheral_REG(0x40000C00, 0x24)
#define TIM5_PSC  Peripheral_REG(0x40000C00, 0x28)
#define TIM5_ARR  Peripheral_REG(0x40000C00, 0x2C)


void TIM_EnableClock(unsigned char Id);
void TIM_Init(unsigned char Id, unsigned char CounterMode, unsigned int CounterValue, unsigned short Prescaler);
void TIM_Start(unsigned char Id);
void TIM_Stop(unsigned char Id);
unsigned char TIM_CheckFlag(unsigned char Id, unsigned char Flag);
//void TIM2_IRQHandler(void);
void TIM2_Callout(void);

#endif /* INC_GPTIM_H_ */
