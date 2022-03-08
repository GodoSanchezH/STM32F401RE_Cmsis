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
#include "Timer.h"

Display7Seg Display_1={9,8,10,4,5,3,10};
uint8_t unidades,decenas,centenas,mil=0;
uint32_t i=0;
int main(void){

Init_Clock_HSI();
Display7Seg_Init(&Display_1);
Timer_delay_Init(1600);

for(;;){

          mil =i/1000 ;
          centenas = (i-mil*1000)/100;
          decenas = (i-centenas*100)/10;
          unidades = i%10;

    	  Write_Display7Seg(&Display_1, Display1, unidades);
    	  Write_Display7Seg(&Display_1, Display2,decenas);
    	  Write_Display7Seg(&Display_1, Display3,centenas);
    	  Write_Display7Seg(&Display_1, Display4,mil);
    	  i++;
    	  if(i==10000) i=0;

}

	return 0;
}




