#include <reg51.h>
#include "timer0.h"
// Define the desired delay value in milliseconds
#define DELAY_MS 2

// Define the timer reload value
// The timer counts up from 0 to 255, then reloads with this value to start again
#define TIMER_RELOAD_VALUE (65536 - (DELAY_MS * 1000 / 12))


sbit LED = P3^1;            // Defining test pin
// Initialize Timer 0 with interrupt
void init_timer0()
{
  // Set the timer mode to 16-bit mode
  TMOD |= 0x01;

  // Set the timer reload value
  TH0 = TIMER_RELOAD_VALUE >> 8;
  TL0 = TIMER_RELOAD_VALUE & 0xFF;

  // Enable Timer 0 interrupt
  ET0 = 1;

  // Enable interrupts globally
  EA = 1;
}

// Create a delay function that uses Timer 0 with interrupt
void delay_timer0()
{
  // Start Timer 0
  TR0 = 1;

  // Wait for the Timer 0 interrupt to occur
  while (TF0 == 0);

  // Reset the Timer 0 interrupt flag
  TF0 = 0;

  // Stop Timer 0
  TR0 = 0;
}

// Declare the interrupt service routine for Timer 0
void Timer0_INT (void) interrupt 1
{   // timer 0 overflow every 50 msec
		LED^=1;
}
