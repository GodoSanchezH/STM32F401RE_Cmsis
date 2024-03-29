/*
 * main.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Godo Sanchez
 */
#include "main.h"
#include "Clock_Config.h"
#include "GPIO.h"



int main(void){

//Init_Clock_HSE();
Init_Clock_HSI();
GPIO_Init(PA, 5,Output,OUT2,No_pull_up_pull_down);
GPIO_Init(PC, 13,Input, OUT2, No_pull_up_pull_down);

for(;;){
/*

		  if(!(GPIOC->IDR & (1<<13))) GPIO_Write(HIGH);	//	PA5 -> HIGH

		  else  GPIO_Write(LOW);						//	PA5 -> LOW
*/
	if(!Read_GPIO(PC,13)){
		Toggle_GPIO(PA, 5);
		for (uint32_t var = 0; var <=100000; var++);
	}
	else Write_GPIO(PA, 5, LOW);

}

	return 0;
}




