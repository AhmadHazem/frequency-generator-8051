#include "timer1.h"
#include "quad_7segment.h"

unsigned int num;
unsigned long int_loop;
unsigned int ext_loop;
unsigned int act_loop;

sbit mybit = P3 ^ 7;

void init_timer1()
{
	// Set the timer mode to 16-bit mode
	TMOD |= 0x10;

	// Enable Timer 1 interrupt
	ET1 = 1;

	// Enable interrupts globally
	EA = 1;
}

void start_timer1()
{
	// Set the timer reload value
	TH1 = (65536 - int_loop) / 256;
	TL1 = (65536 - int_loop) % 256;

	// Start Timer 1
	TR1 = 1;
}

void stop_timer1()	
{
	// Reset the Timer 1 interrupt flag
	TF1 = 0;

	// Stop Timer 0
	TR1 = 0;
}



void delay_timer1(void) interrupt 3
{
	// Toggle bit to produce square wave
	if (--act_loop == 0)
	{
		mybit = ~mybit;
		// Reset the external loop index
		act_loop = ext_loop;
	}

	stop_timer1();

	start_timer1();
}

void set_sq_wave(unsigned int freq)
{
	if (num != freq)
	{
		// Enable timer1
		init_timer1();
		
		// Set the frequency
		num = freq;
		
		// Calculating time needed for each high/low portion
		int_loop = 460800 / (num * 1.0);
		ext_loop = 1;

		// Consider the case where the loop count is greater than 65536
		if (int_loop > 65536)
		{
			ext_loop = 10;
			int_loop = int_loop / 10;
		}
		
		// Set the external loop index
		act_loop = ext_loop;

		// Start generating square wave
		start_timer1();
	}
	else if (freq == 0)
	{
		// Stop generating square wave when freq=0
		mybit = 0;
		stop_timer1();
	}
}
