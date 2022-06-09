/*
 * ObserverClient.c
 *
 *  Created on: Jun 7, 2022
 *      Author: Heba Elbeshbeshy
 */
#include <ObserverClient1.h>
#include "Observer.h"
#include "stm32f4xx.h"

unsigned char Client2Index = -1;
unsigned char Notify_Client1 = 0;

void Client1Init(void)
{
	Client2Index = Subscribe(Client1Notify);
}
void Client1Notify(void)
{
	Notify_Client1 = 1;
}
void Client1Action(float data)
{
	if(Notify_Client1 == 1)
	{
		GPIOA->ODR ^=  (1 << 0);
	}
}
void Client1_Unsubscribe(void)
{
	if (Client2Index != -1)
	{
		unsubscribe(Client2Index);
	}
}

