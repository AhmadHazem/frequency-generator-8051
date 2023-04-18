#include<reg51.h>           // special function register declarations
                            // for the intended 8051 derivative
														
#include"quad_7segment.h"
sbit LED = P3^0;            // Defining LED pin

void Delay(void);           // Function prototype declaration

void main (void)
{
	  init_7segment();
    while(1)                // infinite loop
    {
		show_7segment(1234);
    }
}

void Delay(void)
{
    int j;
    int i;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10000;j++)
        {
        }
    }
}