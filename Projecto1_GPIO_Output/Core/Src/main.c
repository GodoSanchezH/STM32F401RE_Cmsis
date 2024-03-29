/*
 * main.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Godo Sanchez
 */
#include "main.h"
#include "Clock_Config.h"

typedef enum{
	HIGH,
	LOW
}State_GPIO;

void GPIO_Init(void);
void GPIO_Write(bool State_GPIO);
void GPIO_Toggle(void);

int main(void){

Init_Clock();
GPIO_Init();

for(;;){

	GPIO_Write(HIGH);
	for (uint32_t var = 0; var <=100000; var++);
	GPIO_Write(LOW);
	for (uint32_t var = 0; var <=100000; var++);
	}

	return 0;
}



void GPIO_Init(void){
	  RCC->AHB1ENR |= (1 << 0);				 			//	Habilitamos el clock GPIOA
	  GPIOA->MODER |=  (1 << 10);			  			//	Configuración del PIN A5 como salida
	  GPIOA->MODER &= ~(1 << 11);
	  GPIOA->OTYPER &= ~(1 << 5);			 			//	0: Configuracion Output push-pull (reset state)
	  GPIOA->OSPEEDR &= ~(1 << 10)  & ~(1 << 11);			//	00: Configuración de la velocidad 2 MHz High speed
	  GPIOA->PUPDR &= ~(1 << 10) & ~(1 << 11);		    //	00: Configuración de resistencias  No pull-up, pull-down
}


void GPIO_Write(bool State_GPIO){

	switch(State_GPIO){
	case HIGH:
		GPIOA->ODR |= GPIO_ODR_OD5;
		break;
	case LOW:
		GPIOA->ODR &= ~(GPIO_ODR_OD5);
		break;
	}
}

void GPIO_Toggle(void){

GPIOA->ODR ^= GPIO_ODR_OD5;

}
