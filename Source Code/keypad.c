#include "keypad.h"

sbit ROW1 = P1^0;
sbit ROW2 = P1^1;
sbit ROW3 = P1^2;
sbit ROW4 = P1^3;
sbit COL1 = P1^4;
sbit COL2 = P1^5;
sbit COL3 = P1^6;
sbit COL4 = P1^7;

void keypad_init(void)
{
		P1 = 0xFF;
}

unsigned char read_char(void)
{
	unsigned char key = 'k';
  ROW1 = 0; ROW2 = 1; ROW3 = 1; ROW4 = 1;
  while (COL1 == 0) key = '1';
  while (COL2 == 0) key = '2';
  while (COL3 == 0) key = '3';
  while (COL4 == 0) key = 'C';
  ROW1 = 1; ROW2 = 0; ROW3 = 1; ROW4 = 1;
  while (COL1 == 0) key = '4';
  while (COL2 == 0) key = '5';
  while (COL3 == 0) key = '6';
  while (COL4 == 0) key = 'B';
  ROW1 = 1; ROW2 = 1; ROW3 = 0; ROW4 = 1;
  while (COL1 == 0) key = '7';
  while (COL2 == 0) key = '8';
  while (COL3 == 0) key = '9';
  while (COL4 == 0) key = 'A';
  ROW1 = 1; ROW2 = 1; ROW3 = 1; ROW4 = 0;
  while (COL1 == 0) key = '*';
  while (COL2 == 0) key = '0';
  while (COL3 == 0) key = '#';
  while (COL4 == 0) key = 'D';
  return key;
}