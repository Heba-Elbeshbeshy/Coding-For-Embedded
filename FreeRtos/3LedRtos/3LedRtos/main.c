/*
 * 3LedRtos.c
 *
 * Created: 6/8/2022 2:27:44 PM
 * Author : Heba Elbeshbeshy
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"


void Task1_Func(void *parameters);
TaskHandle_t task1ptr;

void Task2_Func(void *parameters);
TaskHandle_t task2ptr;

void Task3_Func(void *parameters);
TaskHandle_t task3ptr;


int main(void)
{
	DDRC  = 0xFF;	// Configure all PORTC pins as output pins

	xTaskCreate(Task1_Func,"first",configMINIMAL_STACK_SIZE,NULL,1,&task1ptr);
	xTaskCreate(Task2_Func,"second",configMINIMAL_STACK_SIZE,NULL,1,&task2ptr);
	xTaskCreate(Task3_Func,"third",configMINIMAL_STACK_SIZE,NULL,1,&task3ptr);	

	vTaskStartScheduler();
	while(1)
	{
		
	}
}

void Task1_Func(void *parameters)
{
	while(1)
	{
		PORTC ^= (1u<<3);
		vTaskDelay(100);
	}
}

void Task2_Func(void *parameters)
{
	while(1)
	{
		PORTC ^= (1u<<5);
		vTaskDelay(30);
	}
}

void Task3_Func(void *parameters)
{
	while(1)
	{
		PORTC ^= (1u<<1);
		vTaskDelay(50);
	}
}