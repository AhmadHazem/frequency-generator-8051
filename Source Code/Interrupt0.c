#include "Interrupt0.h"
#include "quad_7segment.h"
sbit SWT = P3^2;


void Ext_int_Init(void)				
{
	EA  = 1;	/* Enable global interrupt */
	EX0 = 1;      	/* Enable Ext. interrupt0 */
	IT0 = 1;      	/* Select Ext. interrupt0 on falling edge */
}

void External0_ISR() interrupt 0
{
	show_7segment(0);
	//Here ya zoz
} 

