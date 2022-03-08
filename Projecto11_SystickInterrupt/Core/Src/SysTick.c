/*
 * SysTick.c
 *
 *  Created on: 22 feb. 2022
 *      Author: LENOVO
 */

#include "SysTick.h"


static __IO uint32_t mstick;

void SysTickConfig(uint32_t SysTick_Val){

	//Limpiamos el buffer
	SysTick->CTRL = 0;

	//cargar el valor
	SysTick->LOAD = SysTick_Val-1;
	//0 a 83999

	SysTick->CTRL =  (1 << 2) | 		//	1 = processor clock.
	          	  	 (1 << 1) | 		//	1 = counting down to zero asserts the SysTick exception request
					 (1 << 0);			//	1 = counter enabled.

	__NVIC_SetPriority(SysTick_IRQn,0); //prioridad 0
}



void SysTick_Handler(void){
	__NVIC_ClearPendingIRQ(SysTick_IRQn);
	msIncTicks();


}

void msIncTicks(void){
	mstick++;
}

uint32_t msGetTicks(void){

	return mstick;
}

void __delay_ms(uint32_t delay){

	uint32_t starTime = msGetTicks();
	while((msGetTicks() - starTime) < delay);

}
