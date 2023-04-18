<<<<<<< HEAD
#include <reg51.h>  
#include <stdlib.h>
#include "keypad.h"
#include "timer0.h"
#include "quad_7segment.h"
sbit LED = P3^0;           
        
void main (void) {
=======
#include<reg51.h>           // special function register declarations
                            // for the intended 8051 derivative
														
#include"quad_7segment.h"
sbit LED = P3^0;            // Defining LED pin

void Delay(void);           // Function prototype declaration

void main (void)
{
	int nu=0;
>>>>>>> b503ed1979fa9e1f1cb63ba7d93ef457c90def69
	  init_7segment();
		
    while(1)                
    {
<<<<<<< HEAD
			show_7segment(1234);
=======
			nu++;
			show_7segment(nu);
>>>>>>> b503ed1979fa9e1f1cb63ba7d93ef457c90def69
    }
}
