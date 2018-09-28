# Button Interrupt
These codes are button based interrupts. These codes simply turn a specific LED on when a button is pressed then turn back off once the button is pressed again. Although these are done using interrupts rather than using simple polling. An interrupt waits for an input or ouput and once it recieves it the interrupt will begin to run its set of code. For this case the interrupt is waiting for the button to be pressed to turn on the LED and once it is pressed again the interrupt will begin again turning the LED back off. These codes rely on the <msp430.h> library and the <msp432.h> library. 

## MSP430G2553
The code for this processor follows the processor previously mentioned. When the button is pressed the green LED will be lit and once pressed again the LED will turn off. The reset is also enabled for this code; however it will only reset the power source. For example initially the LED is off and if the button is pressed the LED will become lit then if the reset is pressed the LED will be off until the reset is released. At which point the LED will turn on and remain on until the button is pressed again. 

## MSP432P401R


* Author: Eric Schroeder
* Written September 27, 2018
* Last Updated: September 27, 2018
