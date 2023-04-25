#include <reg51.h>  
#include <stdlib.h>
#include "keypad.h"
#include "timer0.h"
#include "Interrupt0.h"
#include "quad_7segment.h"  
#include "timer1.h"

sbit flag = P3^6;


void main (void)
{
	// Intialize frequency "num"
	unsigned int num = 0;
	// Intialize counter 
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
		// Frequency generator
		show_7segment(num);
		if (flag == 0)
		{
			set_sq_wave(num);
		}
	}
}
