# Button Based Delay
These codes are able to blink an LED at a rate decided by the user. Both of these codes initially blink an LED at roughly 10Hz until the button is pressed. Once the button is pressed a timer will start and when released the LED will begin to blink at the rate of how long the button was held. These codes use both the timer interrupts and port interrupts shown in previous codes. These codes are dependent on the <msp430.h> library. 

## MSP430G2553
This code uses a port vector to determine when the button was pressed and begins a count once the button is pressed. When the button is released this time in the counter is transfered to a register. This then intiates a timer interrupt which will blink the LED at the rate the button was held. The user can then repeat this by changing how long they held the button.
## MSP430F5529
This code works nearly identically to the code for the other micrcontroller but changes the ports to match the button and LED on this board. Although this code does not account for button debouncing so the button may not always respond to someone pressing the button. While the previous mentioned error can occur it was found not to be that common. 

* Author: Eric Schroeder
* Written: September 27, 2018
* Last Updated: September 27, 2018
