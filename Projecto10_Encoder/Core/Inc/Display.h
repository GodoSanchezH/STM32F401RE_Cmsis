/*
 * Display.h
 *
 *  Created on: 18 feb. 2022
 *      Author: LENOVO
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_


#include "stm32f401xe.h"
#include "GPIO.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct{

	uint8_t a;  //PA9
	uint8_t b;  //PA8
	uint8_t c;  //PB10
	uint8_t d;  //PB4
	uint8_t e;  //PB5
	uint8_t f;	//PB3
	uint8_t g;	//PA10

}Display7Seg;


void Display7Seg_Init(Display7Seg *Display); //Inicializacion de un solo Display
void Write_Display7Seg(Display7Seg *Display,uint8_t val);
void Reset_Display7Seg(void);





#endif /* INC_DISPLAY_H_ */
