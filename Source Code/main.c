#include <reg51.h>  
#include <stdlib.h>
#include "keypad.h"
#include "timer0.h"
#include "quad_7segment.h"
sbit LED = P3^0;           
        
void main (void) {
	  init_7segment();
		
    while(1)                
    {
			show_7segment(1234);
    }
}
