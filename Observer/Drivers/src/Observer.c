/*
 * Observer.c
 *
 *  Created on: Jun 8, 2022
 *      Author: Heba Elbeshbeshy
 */

#include "Observer.h"
#include "Observer_cfg.h"
#include <stddef.h>

void (*NotifyCallbackPtr[MAX_NUM_CLIENTS])(void);

unsigned char Subscribe(CallbackType CallbackPtr)
{
	unsigned char index;
	for(index = 0; index < MAX_NUM_CLIENTS; index++)
	{
		if(NotifyCallbackPtr[index] == NULL)
		{
			NotifyCallbackPtr[index] = CallbackPtr;
			return index;
		}
	}
	return -1;
}

void DataNotifyAllClients(void)
{
	unsigned char i;
	for(i = 0; i < MAX_NUM_CLIENTS; i++)
	{
		if(NotifyCallbackPtr[i] != NULL)
		{
			NotifyCallbackPtr[i]();
		}
	}
}

void unsubscribe(unsigned char ClientIndex)
{

	NotifyCallbackPtr[ClientIndex] = NULL;
}


