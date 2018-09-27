/*  Author: Eric Schroeder
 *  Written: September 26, 2018
 *  Last updated: September 26, 2018
 */

#include <msp430.h>
volatile unsigned int timerCount1 = 0;          // Timer Counter 1 initialized to 0 this is the Counter for P1.0
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Disable the watchdog timer
    BCSCTL3 = LFXT1S_2;                 // Makes ACLK use crystal as opposed to internal oscillator
    P1OUT |= BIT3;                      // Connects internal resistor to power (making it a pull-up)
    P1DIR |= BIT0;                      // Set P1.0 (Green LED) to output
    P1REN |= BIT3;                      // Enable internal resistor
    P1IE |= BIT3;                       // Set P1.3 as interrupt pin (interrupts are triggered w/ changes to this pin)
    P1IES |= BIT3;                      // Set P1.3 to interrupt on falling edge high to low transition
    TACCTL0 = CCIE;
    TACCR0 = 100;                       // sets the counter period to 100 (Pulse width modulation period)
    TACTL = TASSEL_1 + MC_1 + ID_3;     // sets the clock to be used to ACLK, up mode, divides it by 8
    __enable_interrupt();               // Enables interrupt
    while(1){};                         //creates infinite loop for instructions
}
#pragma vector=TIMER0_A0_VECTOR         //Interrupt service routine for Timer A0
__interrupt void Timer_A(void)
{
    P1OUT ^= BIT0;                      // toggle P1.0 which toggles the LED
}
// Interrupt service routine for P1
#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
{
    if(P1IES & BIT3){
        TACTL = TACLR;                  //clears the clock
        TACTL = TASSEL_1 + MC_2 + ID_3; //sets ACLK to continuous mode and divided by 8
        P1IES &= ~BIT3;                 //clears interrupt flag for P1.3
    }
    else{
        TACCR0 = TA0R;
        TACTL = TASSEL_1 + MC_1 +ID_3;  //sets ACLK to up mode and divided by 8
        P1IES |= BIT3;
    }
    P1IFG &= ~BIT3;                     //clears interrupt flag for P1.3
}
