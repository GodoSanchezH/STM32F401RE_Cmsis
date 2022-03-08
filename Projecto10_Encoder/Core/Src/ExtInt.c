/*
 * ExtInt.c
 *
 *  Created on: 24 feb. 2022
 *      Author: LENOVO
 */

#include "ExtInt.h"

extern bool flag;
extern int __IO valor_inicial, valor_actual, contador;

void External_Interrupt_Init(void){
	// HABILITAMOS EL RELOJ
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	// INTTERRUPCION PC13
	SYSCFG->EXTICR[3] &= ~(SYSCFG_EXTICR4_EXTI13);
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
	// NO ENMASCARAR
	EXTI->IMR |= EXTI_IMR_IM13;
	EXTI->EMR |= EXTI_EMR_EM13;
	// DESCENDENT
	EXTI->FTSR |= EXTI_FTSR_TR13;
	// ASCENDETE DESHABILITADO
	EXTI->RTSR &= ~(EXTI_RTSR_TR13);
	// PRIORIDAD
	NVIC_SetPriority(EXTI15_10_IRQn, 1);
	// ENABLE
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(EXTI15_10_IRQn);

	               // 00000100
		valor_actual = ( (GPIOC->IDR & (1 << 2)) >> 2 );

		if( valor_actual != valor_inicial )
		{        // 00001000
			if(  ((GPIOC->IDR & (1 << 3)) >> 3) != valor_actual   )
			{
				// horario
				if(contador < 100)
					contador+=10;
			}else
			{
				//antihorario
				if(contador > 0)
					contador-=10;
			}
			valor_inicial = valor_actual;
		}

		EXTI->PR |= EXTI_PR_PR13;	//	This bit is cleared by writing a 1

}



