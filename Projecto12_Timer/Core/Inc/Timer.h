/*
 * Timer.h
 *
 *  Created on: 24 feb. 2022
 *      Author: LENOVO
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


#include "main.h"

void Timer_delay_Init(uint32_t aut);

void Timer_delay(uint32_t delay);
void Timer_Periodit_Init(uint32_t delay, uint32_t arr_load);
#endif /* INC_TIMER_H_ */
