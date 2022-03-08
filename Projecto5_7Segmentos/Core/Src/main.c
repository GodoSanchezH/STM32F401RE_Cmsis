/*
 * main.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Godo Sanchez
 */
#include "main.h"
#include "Clock_Config.h"
#include "GPIO.h"
#include "Display.h"


Display7Seg Display1={9,8,10,4,5,3,10};

int main(void){

Init_Clock();
Display7Seg_Init(&Display1);

for(;;){

	for(uint8_t i = 0;i<=9;i++){

		Write_Display7Seg(&Display1, i);
		for (uint32_t var = 0; var <=200000; var++);
	}


}

	return 0;
}




