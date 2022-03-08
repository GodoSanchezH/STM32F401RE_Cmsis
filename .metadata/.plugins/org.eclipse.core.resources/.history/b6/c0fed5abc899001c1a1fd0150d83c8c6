/*
 * LCD_STM32.h
 *
 *  Created on: 27 feb. 2022
 *      Author: LENOVO
 */

#ifndef INC_LCD_STM32_H_
#define INC_LCD_STM32_H_

#include "main.h"
#include "GPIO.h"
#include "Timer.h"

#define E_ON  GPIOA->ODR|=(1<<0);
#define E_OFF GPIOA->ODR &= ~(1<<0);

#define RS_ON GPIOA->ODR|=(1<<1);
#define RS_OFF GPIOA->ODR &= ~(1<<1);

#define D4_ON GPIOA->ODR|=(1<<4);
#define D4_OFF GPIOA->ODR &= ~(1<<4);

#define D5_ON GPIOB->ODR|=(1<<0);
#define D5_OFF GPIOB->ODR &= ~(1<<0);

#define D6_ON GPIOC->ODR|=(1<<0);
#define D6_OFF GPIOC->ODR &= ~(1<<0);

#define D7_ON GPIOC->ODR|=(1<<1);
#define D7_OFF GPIOC->ODR &= ~(1<<1);

typedef enum{
    FILA1 = 1,
    FILA2,
    FILA3 ,
    FILA4
}Ubicacion;

void LCD_STM32_Cmd(uint8_t a);
void LCD_STM32_DataBus(uint8_t a);
void LCD_STM32_Init(void);
void LCD_STM32_SetCursor(uint8_t x , uint8_t y);
void LCD_STM32_Print_Char(char a);
void LCD_STM32_Print_String(char *a);
void LCD_STM32_New_Char(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t h,uint8_t i);
void LCD_STM32_Write_New_Char(uint8_t a);
void LCD_STM32_Clear(void);
void LCD_STM32_Home(void);


#endif /* INC_LCD_STM32_H_ */
