# TIMER A Blink
These codes will blink two LEDs on a board at two different speeds. These codes utilize timer interrupts which have a set value in they will count up to and when they reach that value the interrupt will begin and the code inside will be performed. These codes are dependent on the <msp430.h> library. 

## MSP430G2553 
The code for this processor will toggle two different LEDs at two different speeds. The red LED will be toggled on roughly twice as fast as the green LED. The user can change the speed at which the LEDs will blink by changing the value the timerCount values are compared equal with in the if statements of the interrupt. Although if the user is going to change this number it must be a power of 2. 

## MSP430FR2311
The code for this processor will also toggle two different LEDs at two different speeds. The red LED blinks at roughly 10 Hz and the green LED blinks at roughly 5 Hz. Although this code does not use a timer A interrupt due to this processor not containing a timer A peripheral. Instead this processor used the timer B peripheral the two timers do have their differences but for this code they function identically. If the user wishes to change the speed at which the LEDs blink for this code they can change the number next to TB0CCR0(red LED) or TB0CCR1(Green LED). These two numbers are put into registers and when the timer counts up to that number it will start the timer interrupt which will toggle that LED. Once the interrupt code commpletes the timer resets and the timer starts again.

* Author: Eric Schroeder
* Written: September 27, 2018
* Last updated: September 27, 2018
