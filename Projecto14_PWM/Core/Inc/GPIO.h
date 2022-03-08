/*
 * GPIO.h
 *
 *  Created on: 18 feb. 2022
 *      Author: LENOVO
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f401xe.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>


//Definimos la direccion del Clock de los Puertos
#define RCC_AHB1ENR     (*((volatile unsigned long *) 0x40023830))

#define GPIO_A          (*((volatile unsigned long *) 0x40020000))
#define GPIO_B          (*((volatile unsigned long *) 0x40020400))
#define GPIO_C          (*((volatile unsigned long *) 0x40020800))


// Definimos los Puertos
#define PA 1
#define PB 2
#define PC 3


//Velocidad del Clock
typedef enum{
 OUT2,
 OUT25,
 OUT50,
 OUT100
}GPIO_OSPEEDR;


//Configuracion del Puerto
typedef enum{
	Input=0b00,
	Output,
	Alternate,
	Analog
}GPIO_MODER;


//Configuracion de la Salida
typedef enum{
	Push_Pull,
	Open_Drain
}GPIO_OTYPER;


//Configuracion de las resitencia Salida

typedef enum{
	No_pull_up_pull_down,
	Pull_up,
	Pull_down
}GPIO_PUPDR;


//Estados de la Salida

typedef enum{
	HIGH,
	LOW
}State_GPIO;



void GPIO_Init(uint8_t port,uint8_t pin,uint8_t dir,uint8_t speed,uint8_t opt);

int Read_GPIO(uint8_t port,uint8_t pin);

void Write_GPIO(uint8_t port,uint8_t pin,uint8_t state);

void Toggle_GPIO(uint8_t port,uint8_t pin);



#endif /* INC_GPIO_H_ */
