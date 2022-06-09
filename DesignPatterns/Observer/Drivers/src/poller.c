/*
 * poller.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "poller.h"
#include "device.h"
#include "Observer.h"
#include "PollingDataClient.h"

int polling_enabled= 1;
int pollingData_counter= 1;
int pollingManageClient_counter= 1;
int DataCounter = 0 ;
int ManageClientCounter = 0 ;

void Poll(void)
{
	if(polling_enabled)
	{
		if(!DataCounter)
		{
			float data ;
			unsigned char dataUpdated;

			data = Get_Data();
			dataUpdated = Update(data);

			if(dataUpdated)
			{
				DataNotifyAllClients();
			}
		}
		if (!ManageClientCounter)
		{
			Ecall_ManageClientAction();
		}
	}

	DataCounter++;
	ManageClientCounter++;

	DataCounter = DataCounter % pollingData_counter;
	ManageClientCounter = ManageClientCounter % pollingManageClient_counter;
}

void StartPolling(void)
{
	polling_enabled=1;
}

void StopPolling(void)
{
	polling_enabled=0;
}

void SetPollingTime(int pollingData_time, int pollingManageClient_time )
{
	pollingData_counter = pollingData_time/100;
	pollingManageClient_counter = pollingManageClient_time/100;
}
