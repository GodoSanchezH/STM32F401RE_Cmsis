/*
 * Timer.c
 *
 *  Created on: 24 feb. 2022
 *      Author: LENOVO
 */

#include "Timer.h"

//extern  __IO bool timer_flag;
void Timer_delay_Init(uint32_t aut){

// habilitamos el clock timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
/*Registros a configurar
 * cr1/cr5/psc/arr*/
//contador ascendete
	TIM2->CR1  &= ~(TIM_CR1_DIR); //0: ASCENDETE ; 1: DECENDENTE
//TRABJAMOS A UNICO PULSO
	TIM2->CR1 |= TIM_CR1_OPM;
// Modo Reset
	TIM2->CR2 &= ~(TIM_CR2_MMS);
//prescaldaor 0
	TIM2->PSC =0;
//cargamos el valor a contar
	TIM2->ARR = aut-1; //-> 1 ms
}


void Timer_delay(uint32_t delay){

//50ms-> temportizacion de 0.1 ms
//50*10 = 500*0.1 = 50 ms


	TIM2->PSC = (delay*10)-1;
	//contador habilitado
	TIM2->CR1 |= TIM_CR1_CEN;

	//ui 0
	while(!(TIM2->SR & TIM_SR_UIF));

	//apando el flag
	TIM2->SR &= ~(TIM_SR_UIF);
}




//Periodo

void Timer_Periodit_Init(uint32_t delay, uint32_t arr_load){

	// habilitamos el clock timer
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	/*Registros a configurar
	 * cr1/cr5/psc/arr*/
	//contador ascendete
		TIM2->CR1  &= ~(TIM_CR1_DIR); //0: ASCENDETE ; 1: DECENDENTE
	//TRABJAMOS A UNICO PULSO
		TIM2->CR1 &= ~(TIM_CR1_OPM);
	// Modo Reset
		TIM2->CR2 &= ~(TIM_CR2_MMS);
	//cargamos el valor a contar
		TIM2->ARR = arr_load-1; //-> 1 ms
		TIM2->PSC = (delay*10)-1;
	//apando el flag
		TIM2->SR &= ~(TIM_SR_UIF);
		TIM2->DIER |= TIM_DIER_UIE;
	//prioridad
		__NVIC_SetPriority(TIM2_IRQn, 2);
		__NVIC_EnableIRQ(TIM2_IRQn);
	//contador habilitado
		TIM2->CR1 |= TIM_CR1_CEN;

}



void TIM2_IRQHandler(void){

	__NVIC_ClearPendingIRQ(TIM2_IRQn);
	//apando el flag
	TIM2->SR &= ~(TIM_SR_UIF);
	//Estados = Suspendido;
	//timer_flag = 1;

}
