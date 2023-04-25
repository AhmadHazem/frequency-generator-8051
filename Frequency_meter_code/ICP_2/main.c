/*
  Measuring ATmega16 frequency and duty cycle using input capture
  http://www.electronicwings.com
 */


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "LCD.h"

int main ( )
{
	unsigned int a,b,c,high,period;
	char frequency[14],duty_cy[7];
	
	LCD_Init();
	PORTD = 0xFF;			/* Turn ON pull-up resistor */
	
	while(1)
	{
		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag) flag */

		TCCR1B = 0x41;  	/* Rising edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		a = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
		TCCR1B = 0x01;  	/* Falling edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		b = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
		TCCR1B = 0x41;  	/* Rising edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		c = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */

		TCCR1B = 0;  		/* Stop the timer */
		
		if(a<b && b<c)  	/* Check for valid condition, 
					to avoid timer overflow reading */
		{
			high=b-a;
			period=c-a;
			
			long freq= F_CPU/period;/* Calculate frequency */

						/* Calculate duty cycle */
            		float duty_cycle =((float) high /(float)period)*100;			
			ltoa(freq,frequency,10);
			
			itoa((int)duty_cycle,duty_cy,10);
			
			LCD_Command(0x80);
			LCD_String("Freq: ");
			LCD_String(frequency);
			LCD_String(" Hz    ");
			
			LCD_Command(0xC0);
			LCD_String("Duty: ");
			LCD_String(duty_cy);
			LCD_String(" %      ");
			
		}
		
		else
		{
			LCD_Clear();
			LCD_String("OUT OF RANGE!!");
		}
		_delay_ms(50);
	}

}
