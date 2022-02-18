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


		  if(!(GPIOC->IDR & (1<<13))) GPIO_Write(HIGH);	//	PA5 -> HIGH

		  else  GPIO_Write(LOW);						//	PA5 -> LOW

}

	return 0;
}



void GPIO_Init(void){

/*->>>>>>>>>>> Configuracion Salida <<<<<<<<<<<<<<<<<<<<<<-*/

	 //------	CONFIGURACION COMO SALIDA DEL PIN A5
	  RCC->AHB1ENR |= (1<<0);				 			//	Habilitamos el clock GPIOA
	  GPIOA->MODER |= (1<<10);			  			//	Configuración del PIN A5 como salida
	  GPIOA->MODER &= ~(1<<11);
	  GPIOA->OTYPER &= ~(1<<5);			 			//	0: Configuracion Output push-pull (reset state)
	  GPIOA->OSPEEDR &= ~(1<<10) & ~(1<<11);		//	00: Configuración de la velocidad 2 MHz High speed
	  GPIOA->PUPDR &= ~(1<<10) & ~(1<<11);		    //	00: Configuración de resistencias  No pull-up, pull-down

   /*->>>>>>>>>>> Configuracion Entradas <<<<<<<<<<<<<<<<<<<<<<-*/

	  //------	CONFIGURACION COMO ENTRADA DEL PIN C13
	    RCC->AHB1ENR |= (1<<2);								//	Habilitamos el clock GPIOC
	    GPIOC->MODER &= ~(1<<26) & ~(1<<27);			    //	00: Configuracion Modo Input
	    GPIOC->PUPDR &= ~(1<<26) & ~(1<<27);			    //	00: Configuración de resistencias No pull-up, pull-down

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
