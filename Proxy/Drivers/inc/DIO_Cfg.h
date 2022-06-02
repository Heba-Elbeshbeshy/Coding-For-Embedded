/*
 * DIO_Cfg.h
 *
 *  Created on: Mar 23, 2022
 *      Author: moham
 */

#ifndef INC_DIO_CFG_H_
#define INC_DIO_CFG_H_

#define DIO_NUM_OF_CHANNELS ((unsigned char)5)
#define DIO_NUM_OF_GROUP_CHANNELS ((unsigned char)3)

typedef struct
{
    unsigned char PortId;
    unsigned char PinNum;
    unsigned char PortDirection; /*0 = input, 1 = output*/
    unsigned char PuPd; /*0 = No pull-up, pull-down,1 up,2 down*/
    unsigned char OutputType; /*0 = push-pull,1 = open drain*/

}DIO_ChannelConfigType;

typedef struct
{
	unsigned char *ChannelGroupId;
	unsigned char NumOfGroupChannels;

}DIO_ChannelGroupType;

extern const DIO_ChannelConfigType DIO_ConfigParam[DIO_NUM_OF_CHANNELS];
extern const DIO_ChannelGroupType  DIO_ChannelGroup;

#endif /* INC_DIO_CFG_H_ */
