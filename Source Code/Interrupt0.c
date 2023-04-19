#include "Interrupt0.h"

sbit flag = P3^0;

void Ext_int0_Init(void)				
{
	flag = 1;
	EA  = 1;	
	EX0 = 1;      	/* Enable Ext. interrupt0 */
	IT0 = 1;      	/* Select Ext. interrupt0 on falling edge */
}

void External0_ISR(void) interrupt 0
{
	
	flag = 0;
	// Mtgeesh hna ya zoz 5lif fe el if in the main.c
} 

