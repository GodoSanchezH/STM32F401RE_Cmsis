/*
 * main.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Godo Sanchez
 */
#include "main.h"
#include "Clock_Config.h"
#include "GPIO.h"
#include "ExtInt.h"
#include "Timer.h"

 __IO bool timer_flag;
 __IO bool EXInt_flag;

int main(void){

Init_Clock_HSI();
GPIO_Init(PA, 5,Output,OUT2,No_pull_up_pull_down);
GPIO_Init(PC, 13,Input, OUT2, No_pull_up_pull_down);
External_Interrupt_Init();
//Timer_Periodit_Init(100, 1600);
Estados = Standby;
for(;;){

	switch (Estados) {
		case Apagado:
			Timer_Periodit_Init(300, 1600);
			Estados = Encendido;
			break;

		case Encendido:
			Write_GPIO(PA, 5, HIGH);
			break;

		case Suspendido:
			Write_GPIO(PA, 5, LOW);
			Estados = Standby;
			break;

		default:
			break;
	}

}

	return 0;
}




