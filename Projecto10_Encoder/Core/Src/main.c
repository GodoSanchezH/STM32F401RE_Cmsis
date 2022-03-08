/*
 * main.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Godo Sanchez
 */
#include "main.h"
#include "Clock_Config.h"
#include "GPIO.h"
#include "Timer.h"
#include "LCD_STM32.h"
#include "ExtInt.h"
char dato[5] = "";
bool flag;
__IO int valor_inicial = 0, valor_actual = 0, contador = 0;
char strcount[15];
int  count = 0;

int main(void){

 Init_Clock_HSI();
 Timer_delay_Init(1600);
 GPIO_Init(PC, 13,Input, OUT2, Pull_up);
 External_Interrupt_Init();
 LCD_STM32_Init();
 LCD_STM32_New_Char(1,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00,0x00);//Corazon
 LCD_STM32_New_Char(2,0x0E,0x1F,0x15,0x1F,0x0E,0x0E,0x00,0x00);//Skull
 LCD_STM32_SetCursor(1,FILA1);
 LCD_STM32_Print_String("STM32F401");
 LCD_STM32_Write_New_Char(1);


for(;;){


	LCD_STM32_SetCursor(1,FILA2);
	sprintf(strcount,"contar:%u", contador);
	LCD_STM32_Print_String(strcount);
	LCD_STM32_Write_New_Char(2);
	Timer_delay(200);


}

	return 0;
}

