/*
 * Display.c
 *
 *  Created on: 18 feb. 2022
 *      Author: LENOVO
 */

#include "Display.h"


void Display7Seg_Init(Display7Seg *Display) //Inicializacion de un solo Display
{
	//configuramos las salidas del display
	GPIO_Init(PA, Display->a,Output,OUT2,No_pull_up_pull_down);
	GPIO_Init(PA, Display->b,Output,OUT2,No_pull_up_pull_down);
	GPIO_Init(PB, Display->c,Output,OUT2,No_pull_up_pull_down);
	GPIO_Init(PB, Display->d,Output,OUT2,No_pull_up_pull_down);
	GPIO_Init(PB, Display->e,Output,OUT2,No_pull_up_pull_down);
	GPIO_Init(PB, Display->f,Output,OUT2,No_pull_up_pull_down);
	GPIO_Init(PA, Display->g,Output,OUT2,No_pull_up_pull_down);

}

void Write_Display7Seg(Display7Seg *Display,uint8_t val){

	const uint8_t Display_7Seg_C[] = {0X3F,0X06,0X5B,0X4,0X66,0X6D,0X7D,0X07,0X7F,0X67 };
//  const uint8_t Display_7Seg_A[] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

	uint8_t dato = Display_7Seg_C[val];

	// Limpiamos el display;
	Reset_Display7Seg();

	//Enviamos la data;

  if(dato & 0x1)             GPIOA->ODR |= 1<<Display->a;
  if(dato & 1<<1)            GPIOA->ODR |= 1<<Display->b;
  if(dato & 1<<2)            GPIOB->ODR |= 1<<Display->c;
  if(dato & 1<<3)            GPIOB->ODR |= 1<<Display->d;
  if(dato & 1<<4)            GPIOB->ODR |= 1<<Display->e;
  if(dato & 1<<5)            GPIOB->ODR |= 1<<Display->f;
  if(dato & 1<<6)            GPIOA->ODR |= 1<<Display->g;

  return;
}

void Reset_Display7Seg(void){
	 	 	Write_GPIO(PA, 9, LOW); ///PRENDIO
			Write_GPIO(PA, 8, LOW);//PRENDIO
			Write_GPIO(PA, 10, LOW);//PRENDIO
			Write_GPIO(PB, 3, LOW);//PRENDIO
			Write_GPIO(PB, 4, LOW);//PRENDIO
		    Write_GPIO(PB, 5, LOW);//PRENDIO
			Write_GPIO(PB, 10, LOW);//PRENDIO
}

