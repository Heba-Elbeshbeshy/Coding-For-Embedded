#include "NVIC.h"
#include "GPTIM.h"
#include "GPIO.h"
#include "main.h"

uint32_t Peripheral_REG(uint32_t PORT_ID, uint32_t REG_ID) { return (PORT_ID + REG_ID); }

int32_t main(void)
{
    GPIO_EnableClock((uint8_t)0);  /* Enable GPIOA */
    TIM_EnableClock((uint8_t)2);  /* Enable TIM2 */

    GPIO_Init((uint8_t)0, (uint8_t)1, OUTPUT, PUSH_PULL);  /* Led */
    TIM_Init((uint8_t)2, DOWNCOUNTER, (uint32_t)1000,  (uint16_t)15999);

    NVIC_EnableTimerInterrupt((uint8_t)2);
	TIM_Start((uint8_t)2);

    while (1)
    {

    }

    return 0;
}

void TIM2_Callout(void)
{
	if(TIM_CheckFlag((uint8_t)2, UIF))
	{
		*GPIOA_ODR ^= (uint32_t)1u << 1;  /* Toggle Led */
	}
}



