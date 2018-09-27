/* Author: Eric Schroeder
 * Written: September 26, 2018
 * Last updated: September 26, 2018
 */

#include <msp430.h>
volatile unsigned int timerCounter1 = 0;          // Timer Counter 1 initialized to 0 (Counter for P1.0)
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Disable the watchdog timer
    P1DIR |= BIT0;                      // Set P1.0 (Red LED) to output
    P1REN |= BIT1;                      // Enable internal resistor
    P1OUT |= BIT1;                      // Connects internal resistor to power (making it a pull-up)
    P1IE |= BIT1;                       // Set P1.1 as interrupt pin (interrupts are triggered w/ changes to this pin)
    P1IES |= BIT1;                      // Set P1.1 to interrupt on falling edge high to low transition
    TA0CCTL0 = CCIE;
    TA0CCR0 = 100;                      // sets the counter period to 100 (pulse width modulation) 10Hz
    TA0CTL = TASSEL_1 + MC_1 + ID_3;    // sets ACLK, up mode, and divides it by 8
    __enable_interrupt();               // Enables interrupt algorithm
    while(1){};                         // infinite loop for instructions
}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0(void)
{
    P1OUT ^= BIT0;                      // toggles P1.0 (red LED)
}
// Interrupt service routine for P1
#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
{
    if(P1IES & BIT1){                       //checks if interrupt flag is set and if button is pressed
        TA0CTL = TACLR;                     //clears the clock
        TA0CTL = TASSEL_1 + MC_2 + ID_3;    //sets ACLK to continuous and divides by 8
        P1IES &= ~BIT1;                     //clears interrupt flag for P1.1
    }
    else{
        TA0CCR0 = TA0R;
        TA0CTL = TASSEL_1 + MC_1 +ID_3;     //sets ACLK to up mode and divides by 8
        P1IES |= BIT1;                      //sets flag for P1.1 interrupt
    }
    P1IFG &= ~BIT1;                         //clears interrupt flag for P1.1
}
