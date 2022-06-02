#include "stm32f4xx.h"
#include "DIO_Cfg.h"
#include "DIO.h"

unsigned char ChannelGroupData[DIO_NUM_OF_GROUP_CHANNELS] = {1, 0, 1};
unsigned char *ChannelGroupDataptr;
			
int main(void)
{
	DIO_Init();
	while(1)
	{

		delay(1000000);
		DIO_ChannelGroupWrite(DIO_ChannelGroup, ChannelGroupData);

		delay(1000000);
		for(unsigned char i = 0; i < DIO_NUM_OF_GROUP_CHANNELS; i++)
		{
			ChannelGroupData[i] = !ChannelGroupData[i] ;
		}
		DIO_ChannelGroupWrite(DIO_ChannelGroup, ChannelGroupData);

		delay(1000000);
		ChannelGroupDataptr = DIO_ChannelGroupRead(DIO_ChannelGroup);
		for(unsigned char i = 0; i < DIO_NUM_OF_GROUP_CHANNELS; i++)
		{
			ChannelGroupData[i] = *(ChannelGroupDataptr + i) ;
		}
		DIO_ChannelGroupWrite(DIO_ChannelGroup, ChannelGroupData);
	}

}


