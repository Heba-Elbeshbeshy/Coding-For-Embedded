#include "i2c.h"
#include "ds1307.h"

char sAddres = 0x44;
char *Time_DataReadBuffer;
char ReadStartAddress;
char ReadDataLength;
unsigned char Time_IsReadRequested;
unsigned char ReadIsDone;

void Time_ReadData(char memoryAddress,char data[],char Length)
{
	Time_DataReadBuffer = &data;
	ReadStartAddress = memoryAddress;
	ReadDataLength = Length;
	Time_IsReadRequested = (unsigned char)1;
	State = ReadRequested;
}

void Time_ManageDataRead(void)
{
	switch(State)
	{
		case IDLE:
			if(Time_IsReadRequested)
			{
				State = ReadRequested;
			}
			break;

		case ReadRequested:
			I2C1_READ(sAddres, ReadStartAddress, Time_DataReadBuffer, ReadDataLength);
			State = ReadDone;
		    break;

		case ReadDone:
			Client_ReadDone();
			State = IDLE;
			break;
	}
}

void Client_ReadDone(void)
{
	/* Done */
}
