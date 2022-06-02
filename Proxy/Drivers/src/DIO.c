#include "DIO_Cfg.h"
#include "stm32f4xx.h"
#include <stdint.h>


#define NUM_OF_PORTS ((unsigned char)4)

GPIO_TypeDef * Ports[NUM_OF_PORTS] = {GPIOA, GPIOB, GPIOC, GPIOD};

void delay(int secs)
{
	for(int i = 0; i < secs; i++)
	{

	}
}

void DIO_Init(void)
 {
     unsigned char i;

     for(i = (unsigned char)0; i < DIO_NUM_OF_CHANNELS; i++)
     {
         unsigned char PortId;
         /*read the port Id from link time configuration*/
         PortId = DIO_ConfigParam[i].PortId;

         /*verify Port Id*/
         if(PortId < NUM_OF_PORTS)
         {
        	 /*Enable clock*/
        	 RCC->AHB1ENR |= (1 << PortId);

        	 GPIO_TypeDef * GPIOx = Ports[PortId];

        	 unsigned char PinNumber = DIO_ConfigParam[i].PinNum;

             /*this  bit always = 0 in input or output mode */
        	 GPIOx->MODER &= ~(1 << (PinNumber * 2 + 1));

        	 /*if output*/
             if(DIO_ConfigParam[i].PortDirection)
             {
            	 GPIOx->MODER |= ( 1 << (PinNumber * 2) );

            	 /*if output type open drain*/
            	 if(DIO_ConfigParam[i].OutputType)
            	 {
            		 GPIOx->OTYPER |= (1 << (PinNumber) );
            	 }
            	 /*if output type push-pull*/
            	 else
            	 {
            		 GPIOx->OTYPER &= ~(1 << (PinNumber) );
            	 }

             }
             /*if input*/
             else
             {
            	 GPIOx->MODER &= ~( 1 << (PinNumber * 2) );

            	 /*pull up */
            	 if(DIO_ConfigParam[i].PuPd == 1u)
            	 {
            		 GPIOx->PUPDR |= ( 1 << (PinNumber * 2) );
            		 GPIOx->PUPDR &= ~( 1 << (PinNumber * 2 + 1) );
            	 }
            	 /*pull down */
            	 else if(DIO_ConfigParam[i].PuPd == 2u)
				 {
            		 GPIOx->PUPDR |= ( 1 << (PinNumber * 2 + 1) );
            		 GPIOx->PUPDR &= ~( 1 << (PinNumber * 2) );
				 }
            	 /* No pull-up, pull-down */
            	 else
            	 {
            		 GPIOx->PUPDR &= ~( 1 << (PinNumber * 2) );
            		 GPIOx->PUPDR &= ~( 1 << (PinNumber * 2 + 1) );

            	 }
             }

         }
         else
         {
             /*invalid port*/
             break;
         }
     }
 }

/*Function shall do the following:
1- To Validate Channel ID
2- To get the port ID from configuration based on the Channel ID
3- To write port for the masked pins with the passed data value
4- Data shall be written only for the output pins*/
void DIO_ChannelWrite(unsigned char ChannelId, unsigned char Data)
{
   /*Add your code*/
	if (ChannelId < DIO_NUM_OF_CHANNELS)
	{
		unsigned char PortId;
		PortId = DIO_ConfigParam[ChannelId].PortId;

		if(DIO_ConfigParam[ChannelId].PortDirection)
		{
			GPIO_TypeDef * GPIOx = Ports[PortId];
			if(Data)
			{
				GPIOx->ODR |= (1 << (DIO_ConfigParam[ChannelId].PinNum) );
			}
			else
			{
				GPIOx->ODR &= ~( 1 << (DIO_ConfigParam[ChannelId].PinNum) );
			}

		}
		else
		{

		}
	}
}

void DIO_ChannelGroupWrite(DIO_ChannelGroupType ChannelGroup, unsigned char ChannelGroupData[])
{
   /*Add your code*/
	for(unsigned char i; i < ChannelGroup.NumOfGroupChannels; i++)
	{
		unsigned char ChannelId;
		unsigned char Data;

		ChannelId = ChannelGroup.ChannelGroupId[i];
		Data = ChannelGroupData[i];

		DIO_ChannelWrite(ChannelId, Data);
	}

}
/*Function shall do the following:
1- To Validate Channel ID
2- To get the port ID from configuration based on the Channel ID
3- To read port for the masked pins and other pins shall be returned by 0
4- Data shall be read only for the input pins*/

unsigned char DIO_ChannelRead(unsigned char ChannelId)
{
	unsigned char Data = 0;
	/*Add your code*/
	if (ChannelId < DIO_NUM_OF_CHANNELS)
	{
		unsigned char PortId;

		PortId = DIO_ConfigParam[ChannelId].PortId;

		if(!DIO_ConfigParam[ChannelId].PortDirection)
		{
			GPIO_TypeDef * GPIOx = Ports[PortId];

			Data = ( (1 << ( DIO_ConfigParam[ChannelId].PinNum ) ) & GPIOx->IDR ) ? 1 : 0 ;
		}

	}
	return Data;
}

unsigned char* DIO_ChannelGroupRead(DIO_ChannelGroupType ChannelGroup)
{
	unsigned char ChannelGroupData[ChannelGroup.NumOfGroupChannels];
   /*Add your code*/
	for(unsigned char i; i < ChannelGroup.NumOfGroupChannels; i++)
	{
		unsigned char ChannelId;
		ChannelId = ChannelGroup.ChannelGroupId[i];

		ChannelGroupData[i] = DIO_ChannelRead(ChannelId);
	}

	return ChannelGroupData;
}
