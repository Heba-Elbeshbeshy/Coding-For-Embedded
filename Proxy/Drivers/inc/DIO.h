/*
 * DIO.h
 *
 *  Created on: Mar 23, 2022
 *      Author: moham
 */

#ifndef INC_DIO_H_
#define INC_DIO_H_

void delay(int secs);
void DIO_Init(void);
void DIO_ChannelWrite(unsigned char ChannelId, unsigned char Data);
unsigned char DIO_ChannelRead(unsigned char ChannelId);
void DIO_ChannelGroupWrite(DIO_ChannelGroupType ChannelGroup, unsigned char ChannelGroupData[]);
unsigned char* DIO_ChannelGroupRead(DIO_ChannelGroupType ChannelGroup);

#endif /* INC_DIO_H_ */
