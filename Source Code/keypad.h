#ifndef __KEYPAD_H__
#define __KEYPAD_H__
#include <reg51.h>

void keypad_init(void);
unsigned char read_char(void);
#endif