/*
 * LCD_16x2_H_file.h
 *
 * Created: 4/22/2023 6:23:36 PM
 *  Author: BLU-RAY
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
void LCD_Command(unsigned char cmnd);
void LCD_Char (unsigned char char_data);
void LCD_Init (void);
void LCD_String (char *str);
void LCD_Clear();