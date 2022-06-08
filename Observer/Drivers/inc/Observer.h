/*
 * Observer.h
 *
 *  Created on: Jun 8, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_OBSERVER_H_
#define INC_OBSERVER_H_

typedef void (*CallbackType)(void);

void DataNotifyAllClients(void);
unsigned char Subscribe(CallbackType CallbackPtr);
void unsubscribe(unsigned char ClientIndex);

#endif /* INC_OBSERVER_H_ */
