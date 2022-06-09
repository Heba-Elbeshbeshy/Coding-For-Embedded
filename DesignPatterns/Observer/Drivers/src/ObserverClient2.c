/*
 * ObserverClient2.c
 *
 *  Created on: Jun 8, 2022
 *      Author: Heba Elbeshbeshy
 */
#include "stm32f4xx.h"
#include "Observer.h"
#include <ObserverClient2.h>

unsigned char Client1Index = -1;
unsigned char Notify_Client2 = 0;

void Client2Init(void)
{
	Client1Index = Subscribe(Client2Notify);
}
void Client2Notify(void)
{
	Notify_Client2 = 1;
}
void Client2Action(float data)
{
	if(Notify_Client2 == 1)
	{
		GPIOA->ODR ^=  (1 << 1);
	}
}
void Client2_Unsubscribe(void)
{
	if (Client1Index != -1)
	{
		unsubscribe(Client1Index);
	}
}
