/*
 * ds1307.h
 *
 *  Created on: Apr 22, 2022
 *      Author: moham
 */

#ifndef INC_DS1307_H_
#define INC_DS1307_H_

#define State   	  (unsigned char)0
#define IDLE    	  (unsigned char)0
#define ReadRequested (unsigned char)1
#define ReadDone      (unsigned char)2

void Time_ReadData(char memoryAddress,char data[],int n);
void Time_ManageDataRead(void);
void Client_ReadDone(void);

#endif /* INC_DS1307_H_ */
