#include <reg51.h>
#include "timer0.h"
// Define the desired delay value in milliseconds
//#define DELAY_MS 2
// Define the timer reload value
// The timer counts up from 0 to 255, then reloads with this value to start again
//#define TIMER_RELOAD_VALUE (65536 - (DELAY_MS * 1000 / 1))
 int global_variable;  /* Declaration of the variable */


// Initialize Timer 0 with interrupt
void init_timer0(	)
{
  // Set the timer mode to 16-bit mode
  TMOD |= 0x01;

  // Set the timer reload value
  //TH0 = TIMER_RELOAD_VALUE >> 8;
  //TL0 = TIMER_RELOAD_VALUE & 0xFF;
  // Enable Timer 0 interrupt
  ET0 = 1;

  // Enable interrupts globally
  EA = 1;
	
	  // Start Timer 0
  TR0 = 1;
}

int get_global_variable(){
	return global_variable;
}
unsigned char temp=0;
// Declare the interrupt service routine for Timer 0
void Timer0_INT (void) interrupt 1
{   
	// Reset the Timer 0 interrupt flag
  TF0 = 0;

  // Stop Timer 0
  TR0 = 0;
	
	TH0 = 0xDF;
  TL0 = 0x00;
	if(temp==0){
		global_variable=0;
	}else if (temp==1){
		global_variable=1;
	}
	else if (temp==2){
		global_variable=2;
	}
	else if (temp==3){
		global_variable=3;
	}
	else if (temp==4){
		global_variable=4;
	}
	temp++;if (temp==5)temp=0;
	// Start Timer 0
  TR0 = 1;
}