/*
 * adc.c
 *
 *  Created on: 1 mar. 2022
 *      Author: LENOVO
 */

#include "adc.h"
#include "SysTick.h"

void Adc_Stm32_Init(void){


	//habilitamos el clock el adc
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//gpio A0
	RCC-> AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODE0;


	ADC1->CR2 &= ~(ADC_CR2_ALIGN);//ALINEADO A LA DERECHA
	ADC1->CR2 &= ~(ADC_CR2_CONT);//MANERA SINGLE


	ADC1->CR1 &= ~(ADC_CR1_RES);//RESOLUCION A 12 BITS

	//FLCL = 16/2 = 8Mhz
	ADC->CCR &= ~(ADC_CCR_ADCPRE);

	//tiempo muestreo
	ADC1->SMPR2 &= ~(ADC_SMPR2_SMP0);//3 cycles
	// CONVERSIONES 1
	ADC1->SQR1 &= ~(ADC_SQR1_L);
	ADC1->SQR3=0 ;

	//SWSTAR
	ADC1->CR2 |= ADC_CR2_SWSTART;
	//ADC_ON
	ADC1->CR2 |= ADC_CR2_ADON;
	Timer_delay(10);
}

void ADC_START(void){
	    ADC1->SR = 0;// limpiar flag
		ADC1->CR2 |= ADC_CR2_ADON;
		ADC1->CR2 |= ADC_CR2_SWSTART;

}

void ADC_STOP(void){

ADC1 -> SR = 0;
ADC1->CR2 &= ~(ADC_CR2_SWSTART);
}

uint16_t AnalogRead(void){

	return ((ADC1->DR) & 0x0FFF);// 12 bits

}


bool ADC_PollEndConversion(uint32_t timeout){

	uint32_t starTime = msGetTicks();
	while((ADC1->SR & ADC_SR_EOC) == 0)
	{
		if((msGetTicks() - starTime)  > timeout)
		{
			return false;
		}
	}
	return true;

}

void ADC_EnableNVIC(void)
{
	ADC1->CR1 |= ADC_CR1_EOCIE;// INT EOC
	NVIC_SetPriority(ADC_IRQn,5);
	NVIC_EnableIRQ(ADC_IRQn);
}

void ADC_DisableNVIC(void)
{
	ADC1->CR1 &= ~ADC_CR1_EOCIE;// INT EOC
	NVIC_DisableIRQ(ADC_IRQn);
}
