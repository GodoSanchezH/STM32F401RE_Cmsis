/*
 * GPIO.c
 *
 *  Created on: 18 feb. 2022
 *      Author: LENOVO
 */


#include "GPIO.h"

void GPIO_Init(uint8_t port,uint8_t pin,uint8_t dir,uint8_t speed,uint8_t opt)
{

	switch (port) {
		case PA:
			  RCC_AHB1ENR |= (1<<0);			//	Habilitamos el clock GPIOA
			  GPIOA->MODER |= ( dir << (2*pin)); //Habilitamos el Modo de Salida
			  if(dir==1){
				  GPIOA->MODER &= ~( dir << (2*pin+1));
				  GPIOA->OTYPER &= ~(1<<pin);	 //Push Pull
				  GPIOA->OSPEEDR |= (speed<<(2*pin));//Velocidad Output
			  }
			  GPIOA->PUPDR |= (opt<<(2*pin));

			break;
		case PB:
			  RCC_AHB1ENR |= (1<<1);			//	Habilitamos el clock GPIOB
			  GPIOB->MODER |= ( dir << (2*pin)); //Habilitamos el Modo de Salida o entrada
			  if(dir==1){
				  GPIOB->MODER &= ~( dir << (2*pin+1));
			 			GPIOB->OTYPER &= ~(1<<pin);	 //Push Pull
			 			GPIOB->OSPEEDR |= (speed<<(2*pin));//Velocidad Output
			 		    }
			  GPIOB->PUPDR |= (opt<<(2*pin));
			  break;
		case PC:
			 RCC_AHB1ENR |= (1<<2);			    //	Habilitamos el clock GPIOC
			 GPIOC->MODER |= ( dir << (2*pin)); //Habilitamos el Modo de Salida o entrada
			 if(dir==1){
				 	 	GPIOC->MODER &= ~( dir << (2*pin+1));
						GPIOC->OTYPER &= ~(1<<pin);	 //Push Pull
						GPIOC->OSPEEDR |= (speed<<(2*pin));//Velocidad Output
					    }
			 GPIOC->PUPDR |= (opt<<(2*pin));
		break;

	}
}

int Read_GPIO(uint8_t port,uint8_t pin)
{
	int state;

	switch (port){

		case PA:

			state = (GPIOA->IDR & (1<<pin));
			break;

		case PB:

			state = (GPIOC->IDR & (1<<pin));
			break;

		case PC:

			state = (GPIOC->IDR & (1<<pin));
			break;

				}

return state;
}

void Write_GPIO(uint8_t port,uint8_t pin,uint8_t state)
{

	switch (port){

		case PA:
			switch(state){
				case HIGH:
					GPIOA->ODR |= (1<<pin);
					break;
				case LOW:
					GPIOA->ODR &= ~(1<<pin);
					break;
					}
			break;

		case PB:
			switch(state){
				case HIGH:
					GPIOB->ODR |= (1<<pin);
					break;
				case LOW:
					GPIOB->ODR &= ~(1<<pin);
					break;
						}
			break;

		case PC:
			switch(state){
				 case HIGH:
					 GPIOC->ODR |= (1<<pin);
					 break;
				 case LOW:
					 GPIOC->ODR &= ~(1<<pin);
					 break;
						}
			break;

			}
}

void Toggle_GPIO(uint8_t port,uint8_t pin)
{
	switch (port) {
		case PA:
			GPIOA->ODR ^= (1<<pin);
			break;
		case PB:
			GPIOB->ODR ^= (1<<pin);
			break;
		case PC:
			GPIOC->ODR ^= (1<<pin);
			break;

	}
}


