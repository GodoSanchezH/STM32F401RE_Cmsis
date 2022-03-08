/*
 * Clock_Config.h
 *
 *  Created on: 17 feb. 2022
 *      Author: LENOVO
 */

#ifndef INC_CLOCK_CONFIG_H_
#define INC_CLOCK_CONFIG_H_


#include "stm32f401xe.h"

//definimos las macros para los pll

#define PLL_M	84
#define PLL_N	4
#define PLL_P	0// Valor 2


/*
 * f(Vco Clock) = f(clock input)*(PLL_N/PLL_M)
 * f(clock output pll) = f(Vco Clock)/PLL_P
 */

//definimos Funcion

void Init_Clock_HSE(void);  //Oscilador Externo
void Init_Clock_HSI(void);  //Oscilador Interno
#endif /* INC_CLOCK_CONFIG_H_ */
