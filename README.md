# Frequency Generator 8051 Project README

## Project Description
This project is a frequency generator that uses a keypad to input a frequency value, which is then displayed on a 7-segment display. The frequency value is used to generate a square wave, which is output through a pin on the microcontroller. The program uses interrupts to detect when the square wave should be toggled on or off. The program runs continuously, waiting for input from the keypad and updating the frequency value and 7-segment display accordingly.
Bonus extra project:
this project is an Arduino frequency counter that uses a library called FreqCounter to measure the frequency of an input signal. The frequency is displayed on a 16x2 LCD screen in either Hz, KHz, or MHz, depending on the magnitude of the frequency. The program initializes the LCD screen and sets up the FreqCounter library with calibration and gating parameters. It then enters a while loop that measures the frequency of the input signal using the FreqCounter library and displays the frequency on the LCD screen in the appropriate units. The program uses delay functions to control the timing of the measurements and display updates. this project was used to verify the previous Freqencty generator project. 
Also, Proteus Simulation is Provided. 
## Table of Contents
- [Frequency Generator 8051 Project README](#frequency-generator-8051-project-readme)
  - [Project Description](#project-description)
  - [Table of Contents](#table-of-contents)
  - [Project Overview](#project-overview)
  - [Hardware Requirements](#hardware-requirements)
  - [Software Requirements](#software-requirements)
    - [Frequency Generator :](#frequency-generator-)
    - [Frequency Counter :](#frequency-counter-)
  - [Installation and Setup](#installation-and-setup)
    - [Frequency Generator :](#frequency-generator--1)
    - [Frequency Counter :](#frequency-counter--1)
  - [Usage](#usage)
  - [Contributing](#contributing)
  - [License](#license)
  - [Troubleshooting](#troubleshooting)
  - [Contact Information](#contact-information)
  - [Acknowledgments](#acknowledgments)
  - [References](#references)

## Project Overview
The purpose of this project is to develop an embedded system that generates a square wave of a specific frequency using a keypad and a 7-segment display. The goals of the project are to allow the user to input a frequency value using the keypad, display the frequency value on the 7-segment display, and generate a square wave of the specified frequency. The key features of the system include the use of interrupts to toggle the square wave on and off, the ability to update the frequency value and display it on the 7-segment display, and the use of a keypad for user input.

## Hardware Requirements
8051 microcontroller, Keypad, output signal, LCD, Arduino 

## Software Requirements
the following software tools and frameworks are needed to develop the embedded system:

### Frequency Generator :

- Keil uVision IDE: This is the integrated development environment used to write, compile, and debug the code for the 8051 microcontroller.
- C programming language: This is the programming language used to write the code for the 8051 microcontroller.
- reg51.h header file: This is a header file used to define the register addresses and bit-level access for the 8051 microcontroller.
- Interrupt0.h header file: This is a header file used to define the interrupt service routine for Interrupt 0.
- keypad.h header file: This is a header file used to define the functions for interfacing with the keypad.
- quad_7segment.h header file: This is a header file used to define the functions for interfacing with the 7-segment display.
- timer0.h header file: This is a header file used to define the functions for setting up and using Timer 0.
- timer1.h header file: This is a header file used to define the functions for setting up and using Timer 1.

In addition to these tools and frameworks, the following hardware components are also needed:

- 8051 microcontroller: This is the microcontroller that runs the code.
- 7-segment display: This is the display used to show the frequency value.
- Keypad: This is the input device used to enter the frequency value.
- External interrupt source: This is the signal used to trigger Interrupt 0.
### Frequency Counter :

- Arduino IDE: This is the integrated development environment used to write, compile, and upload the code to the Arduino board.
- FreqCounter library: This is a library used to measure the frequency of an input signal.
- LiquidCrystal library: This is a library used to interface with the 16x2 LCD screen.
- C++ programming language: This is the programming language used to write the code for the Arduino board.
- AVR-GCC compiler: This is the compiler used to compile the C++ code for the Arduino board.

In addition to these tools and frameworks, the following hardware components are also needed:

- Arduino board: This is the microcontroller board that runs the code.
- 16x2 LCD screen: This is the display used to show the frequency measurement.
- Input signal source: This is the signal whose frequency is being measured.
## Installation and Setup
### Frequency Generator :
Install Kiel , Keil uVision ID.
### Frequency Counter :
Install Arduino IDE, FreqCounter library, LiquidCrystal library
## Usage
- Use Proteus Simulation.
- Run Keil uVision IDE Simulator.
- Burn Code on 8051 Microcontroller.

## Contributing
Team 33 used Moduled layered programming  in Building Project 

## License
open-source license, Not responsible for any Bad usage of the code.

## Troubleshooting
- Use Proteus Simulation
- Run Keil uVision IDE Simulator.
- Use Code on 8051 Microcontroller, then trace by Avometer - Contact US 

## Contact Information
Team 33

## Acknowledgments
 project relies on external Arduino libraries: FreqCounter library, LiquidCrystal library

## References
Mazidi 8051 Microcontroller Book

---

Good luck with your embedded systems project