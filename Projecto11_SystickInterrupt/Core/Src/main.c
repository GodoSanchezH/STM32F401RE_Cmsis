/*
 * main.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Godo Sanchez
 */
#include "main.h"
#include "Clock_Config.h"
#include "GPIO.h"
#include "SysTick.h"

int main(void){

Init_Clock_HSI();
SysTickConfig(16000);

GPIO_Init(PA, 5, Output, OUT2, No_pull_up_pull_down);

for(;;){

Toggle_GPIO(PA, 5);
__delay_ms(100);

}

	return 0;
}




