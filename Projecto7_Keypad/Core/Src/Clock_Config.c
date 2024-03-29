/*
 * Clock_Config.c
 *
 *  Created on: 17 feb. 2022
 *      Author: LENOVO
 */

#include "Clock_Config.h"



void Init_Clock_HSE(void){

	/*
	 *   --------- 8MHZ to
	 *   --------- 84MHZ
	 *   --------- AHB = 1
     *   --------- APB1_PRE = 2
     *   --------- APB2_PRE = 1
	 */


RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN |RCC_PLLCFGR_PLLP); //Limpiamos el Registro del Clock en eL pll
RCC->PLLCFGR  |= PLL_M | (PLL_N<<6) | (PLL_P<<16);//Cargamos los valores de nuestro PLL


//HSE
RCC->CR |=RCC_CR_HSEON;				//  1: HSE Encendido
while( !(RCC->CR & (1 << 17)));	//	1: HSE esperamos que active

RCC->PLLCFGR |= (1 << 22); //HS->PLL

RCC->CR |= RCC_CR_PLLON ;			// 1: Habilitamos el PLL
while(!(RCC->CR & RCC_CR_PLLRDY));	//1: Esperamos la activacion del PLL


//Flash


 FLASH->ACR &= ~(FLASH_ACR_LATENCY);							//Limpiamos el Flash Latency
 FLASH->ACR &= ~(1 << 2) & ~(1 << 0);							//	010: Two wait states
 FLASH->ACR |=  (1 << 1);
 FLASH->ACR |=  (1 << 11) | (1 << 10) | (1 << 9) | (1 << 8);	//  ART Accelerator


 //Seleccion del Mux DEL Clock

 RCC->CFGR &= ~(RCC_CFGR_SW);		//Limpiamos el Selector de Clock
 RCC->CFGR |=  (1 << 1);
 RCC->CFGR &= ~(1 << 0);			//Seleccionamos PLL
 while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));	//Esperamos q lo seleccione

 //AHB

 RCC->CFGR &= ~(RCC_CFGR_HPRE);

 //APB1

 RCC->CFGR &= ~(RCC_CFGR_PPRE1);
 RCC->CFGR |= RCC_CFGR_PPRE1_2;

 //APB2

 RCC->CFGR &= ~(RCC_CFGR_PPRE2);


}

void Init_Clock_HSI(void){

	  FLASH->ACR &= ~(FLASH_ACR_LATENCY);
	  FLASH->ACR |= FLASH_ACR_LATENCY_0WS; //~(1 << 2) & ~(1 << 1) & ~(1 << 0);//	000: Zero wait state
	  FLASH->ACR |=  (1 << 11) | (1 << 10) | (1 << 9) | (1 << 8);	//  ART Accelerator
	  RCC->CR |= RCC_CR_HSION;				//	1: HSI oscillator ON
	  while( !(RCC->CR & RCC_CR_HSION) );	//	1: HSI oscillator ready


}
