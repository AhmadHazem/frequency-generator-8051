#include <reg51.h>  
#include <stdlib.h>
#include "keypad.h"
#include "timer0.h"
#include "Interrupt0.h"
#include "quad_7segment.h"        
        
void main (void)
{
	// Zeyad !!!!!
	// ro7 3la interrupt0.c w mtnshash t5li el frequency b zero henak b3d el interupt
	// Your assignment is to generate el frequecny in the num
	unsigned int num = 0;
	// Intialize 7-Segment
	init_7segment();
  // Intialize keypad
	keypad_init();
	// Intialize Interrupts 0
	Ext_int_Init();
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
			}
			//print on 7 segment
			show_7segment(num);
    }
}
