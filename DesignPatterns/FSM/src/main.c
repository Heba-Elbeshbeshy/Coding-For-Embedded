#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"
#include "i2c.h"
#include "ds1307.h"


int main(void)
{
	StartTimer();
	EnableInterrupt();
	SetPollingTime(500);
	StartPolling();
	I2C1_INIt(); /* Initialize I2C1 */

	while(1)
	{
//		Time_ReadData(0xD0, Data, n);
	}

}

void TIM2_IRQHandler(void)
{
	TIM2->SR &= ~(1 << 0);
	CallPollingFunction();
}


