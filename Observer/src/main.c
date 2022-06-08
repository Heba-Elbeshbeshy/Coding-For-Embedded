#include <stm32f4xx.h>
#include <ObserverClient1.h>
#include <ObserverClient2.h>
#include "PollerTimer.h"
#include "poller.h"

int main(void)
{
	/*initialize pin 0,1 portA as output*/
	RCC->AHB1ENR |=  (1 << 0);

	GPIOA->MODER |=  (1 << 0);
	GPIOA->MODER &= ~(1 << 1);
	GPIOA->MODER |=  (1 << 2);
	GPIOA->MODER &= ~(1 << 3);

	Client1Init();
	Client2Init();
	StartTimer();
	EnableInterrupt();
	SetPollingTime(500 , 800);
	StartPolling();

	while(1)
	{
	}
}

void TIM2_IRQHandler(void)
{
	TIM2->SR &=~(1<<0);
	CallPollingFunction();
}


