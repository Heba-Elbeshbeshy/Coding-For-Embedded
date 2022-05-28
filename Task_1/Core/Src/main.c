#include "NVIC.h"
#include "GPTIM.h"
#include "GPIO.h"

void TIM2_Callout(void)
{
	if(TIM_CheckFlag(2, UIF))
	{
		*GPIOA_ODR ^= 1 << 1;  // Toggle Led
	}
}

int main(void)
{
    GPIO_EnableClock(0);  // Enable GPIOA
    TIM_EnableClock(2); // Enable TIM2

    GPIO_Init(0, 1, OUTPUT, PUSH_PULL);  // Led
    TIM_Init(2, DOWNCOUNTER, 1000, 15999);

    NVIC_EnableTimerInterrupt(2);

	TIM_Start(2);

    while (1)
    {

    }

    return 0;
}


