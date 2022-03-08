/*
 * SysTick.h
 *
 *  Created on: 22 feb. 2022
 *      Author: LENOVO
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "main.h"


void SysTickConfig(uint32_t SysTick_Val);
void msIncTicks(void);
uint32_t msGetTicks(void);
void __delay_ms(uint32_t delay);

#endif /* INC_SYSTICK_H_ */
