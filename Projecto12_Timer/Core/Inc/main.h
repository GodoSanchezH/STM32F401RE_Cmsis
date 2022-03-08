/*
 * main.h
 *
 *  Created on: Feb 16, 2022
 *      Author: LENOVO
 */

#ifndef MAIN_H_
#define MAIN_H_


#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum{
	Apagado,
	Encendido,
    Suspendido,
	Standby,
}StateMachine;

StateMachine Estados;

#endif /* MAIN_H_ */
