/*
 * Pwm.h
 *
 *  Created on: 5 mar. 2022
 *      Author: LENOVO
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "main.h"


#define PERIODO_PWM		19999
#define VALOR_MAX_ADC	4095

void PWM_Init(void);

void PWM_Gpio(void);

#endif /* INC_PWM_H_ */
