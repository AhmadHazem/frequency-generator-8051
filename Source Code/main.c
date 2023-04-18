#include<reg51.h>           // special function register declarations
                            // for the intended 8051 derivative
														
#include"quad_7segment.h"
sbit LED = P3^0;            // Defining LED pin

void Delay(void);           // Function prototype declaration

void main (void)
{
	int nu=0;
	  init_7segment();
    while(1)                // infinite loop
    {
			nu++;
			show_7segment(nu);
    }
}
