#include <reg51.h>  
#include <stdlib.h>
#include "keypad.h"
#include "timer0.h"
#include "Interrupt0.h"
#include "quad_7segment.h"        
sbit flag = P3^0;


void main (void)
{
	// Zeyad !!!!!
	// ro7 3la interrupt0.c w mtnshash t5li el frequency b zero henak b3d el interupt
	// Your assignment is to generate el frequecny in the num
	unsigned int num = 0;
	short counter = 0;
	// Intialize 7-Segment
	init_7segment();
  // Intialize keypad
	keypad_init();
	// Intialize Interrupts 0
	Ext_int0_Init();
    while(1)                
    {
			// read character from keypad
			unsigned char temp = read_char();
			// if it is k skip otherwise enter if condition
			if (temp != 'k')
			{
				// multiply num by 10
				num = num * 10;
				// Add newly read character to the 7 segment
				num += (temp - '0');
				//Counter to check if limit reached
				counter ++;
			}
			//print on 7 segment
			//Global Flag
			if (flag == 0 || counter == 5)
			{
				num = 0;
				counter = 0;
				flag = 1;
			}
			/*
			PUT YOUR FUNCTION HERE YA ZIKO
			Ex : setFreq(num)
			*/
			show_7segment(num);
    }
}
