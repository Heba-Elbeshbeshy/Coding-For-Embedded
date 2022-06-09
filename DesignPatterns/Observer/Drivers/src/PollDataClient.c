
#include "stm32f4xx.h"
#include "PollingDataClient.h"
#include <ObserverClient1.h>
#include <ObserverClient2.h>

float temp;
unsigned char DataUpdated = 0;

unsigned char Update(float data)
{
	temp = data;
	DataUpdated = 1;
	return DataUpdated;
}

void Ecall_ManageClientAction(void)
{
	if(DataUpdated == 1)
	{
		Client1Action(temp);
		Client2Action(temp);
	}
}
