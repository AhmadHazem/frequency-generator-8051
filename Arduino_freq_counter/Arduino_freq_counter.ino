#include <FreqCounter.h>
#include <LiquidCrystal.h>
#include <stdlib.h>

#define countdelay 1 // measurement delay
#define calibration 0 // adjusts frequency for variation in Arduino
#define gatetime 100 // gate time in milliseconds
#define onems 1000 // alias for 1000 milliseconds

LiquidCrystal lcd(12, 11, 9, 8, 7, 6); // setup the LCD interface pins
char units[][5] = {"Hz", "KHz", "MHz"};  //units of frequency to be used later

void setup(){
  lcd.begin(16,2); // initialize the LCD
  lcd.print("** Frequency **"); //initial message
  lcd.setCursor(0,1);
  lcd.print("**  Counter  **");
  delay(100); //100ms startup delay
}

void loop() {
  char Freq[16];  //to store frequency
  unsigned long Fcalc=0;
  float Fval;
  FreqCounter::f_comp=calibration; // calibrate with known source
  FreqCounter::start(gatetime); // count pulses for specified gating period
  while (FreqCounter::f_ready == 0)
    Fcalc = FreqCounter::f_freq;
    delay(countdelay);
    Fval = (float) Fcalc * (onems / gatetime); // scale the input
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Freq.:");
  
    //check and display in frequency correct units
    if(0 <= Fval && Fval < 1000){
      dtostrf(Fval, 3, 2, Freq);
      strcat(Freq, units[0]);
                        lcd.setCursor(0,1);
      lcd.print(Fval);
      lcd.print(units[0]);
    }
                else if(1000 <= Fval && Fval < 1000000){
      Fval = Fval/1000;
                        dtostrf(Fval, 3, 2, Freq);
                        strcat(Freq, units[1]);
                        lcd.setCursor(0,1);
                        lcd.print(Freq);
    }
    else if(1000000 <= Fval){
      Fval = Fval/1000000;
                        dtostrf(Fval, 3, 2, Freq);
                        strcat(Freq, units[2]);
                        lcd.setCursor(0,1);
                        lcd.print(Freq); 
    }
    else{
      lcd.setCursor(0,1);
      lcd.print("Out of Range");
    }
}
