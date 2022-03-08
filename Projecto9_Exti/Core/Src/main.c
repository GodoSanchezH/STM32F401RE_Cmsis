/*
 * main.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Godo Sanchez
 */
#include "main.h"
#include "Clock_Config.h"
#include "GPIO.h"
#include  "ExtInt.h"


uint32_t flag = 0;

int main(void){

Init_Clock_HSI();
External_Interrupt_Init();

GPIO_Init(PA, 5,Output,OUT2,No_pull_up_pull_down);
GPIO_Init(PC, 13,Input, OUT2, No_pull_up_pull_down);

for(;;){

		if(flag==1){
			Toggle_GPIO(PA, 5);
			for (uint32_t var = 0; var <=100000; var++);
			Toggle_GPIO(PA, 5);
			flag=0;
		}


}

	return 0;
}




