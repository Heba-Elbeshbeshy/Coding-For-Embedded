/*
 * DIO_Cfg.c
 *
 *  Created on: Mar 23, 2022
 *      Author: moham
 */

#include "DIO_Cfg.h"

const DIO_ChannelConfigType DIO_ConfigParam[DIO_NUM_OF_CHANNELS] =
{
    {/*Channel-0*/
     0,
     1,
     1,
     0,
	 0
    },
    {/*channel -1*/
     0,
     2,
     0,
     0,
	 0
    },
    {/*channel -2*/
     0,
     3,
     0,
     0,
	 0
    },
    {/*channel -3*/
     0,
     4,
     1,
     0,
	 0
    },
    {/*channel -4*/
     0,
     5,
     1,
     0,
	 0
    },
};

unsigned char ChannelGroupIds[DIO_NUM_OF_GROUP_CHANNELS] = { 0 , 3 , 4};
const DIO_ChannelGroupType DIO_ChannelGroup = {ChannelGroupIds , DIO_NUM_OF_GROUP_CHANNELS};


