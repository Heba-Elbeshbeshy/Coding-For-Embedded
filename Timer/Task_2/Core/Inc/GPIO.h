/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#ifndef GPIO_H
#define GPIO_H

#include "main.h"

/* Result Status */
#define OK ((uint8_t)0)
#define NOK ((uint8_t)1)

/* Mode Types */
#define INPUT ((uint8_t)0x00)
#define OUTPUT ((uint8_t)0x01)
#define ALTERNATE_FUN ((uint8_t)0x02)
#define ANALOG ((uint8_t)0x03)

/* Output modes */
#define PUSH_PULL ((uint8_t)0x00)
#define OPEN_DRAIN ((uint8_t)0x01)

/* Resistor modes */
#define NO_PULL_UP_DOWN ((uint8_t)0x00)
#define PULL_UP ((uint8_t)0x02)
#define PULL_DOWN ((uint8_t)0x04)

/* Generic macro */
#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))
/* RCC */
#define RCC_AHB1ENR GPIO_REG(0x40023800,0x30)

/* PortA */
#define GPIOA_MODER GPIO_REG(0x40020000,0x00)
#define GPIOA_OTYPER GPIO_REG(0x40020000,0x04)
#define GPIOA_PUPDR GPIO_REG(0x40020000,0x0C)
#define GPIOA_IDR GPIO_REG(0x40020000,0x10)
#define GPIOA_ODR GPIO_REG(0x40020000,0x14)
/* PortB */
#define GPIOB_MODER GPIO_REG(0x40020400,0x00)
#define GPIOB_OTYPER GPIO_REG(0x40020400,0x04)
#define GPIOB_PUPDR GPIO_REG(0x40020400,0x0C)
#define GPIOB_IDR GPIO_REG(0x40020400,0x10)
#define GPIOB_ODR GPIO_REG(0x40020400,0x14)

void GPIO_EnableClock(uint8_t PortID);
void GPIO_Init(uint8_t PortID, uint8_t PinNum, uint8_t PinDir, uint8_t DefaultState);
uint8_t GPIO_WritePin(uint8_t PortID, uint8_t PinNum, uint8_t Data);
uint8_t GPIO_ReadPin(uint8_t PortID, uint8_t PinNum);

#endif /* GPIO_H */
