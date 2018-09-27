/*Author: Eric Schroeder
 * Written: September 27, 2018
 * Last Updated: September 27, 2018
 */
#include <msp430.h>


void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           //Stop Watch Dog Timer
    PM5CTL0 &= ~LOCKLPM5;               //Stop Default High-Impedance Mode
    P1DIR |= BIT0;                      //LED output on P1.0 (red LED)
    P2DIR |= BIT0;                      //LED output on P2.0 (green LED)
    TB0CCTL0 = CCIE;
    TB0CTL = TBSSEL_2 + MC_1 + ID_3;    // sets SMCLK, Up mode, divided by 8
    TB0CCR0= 12500;                     //10Hz (red LED speed)

    TB1CCTL0 = CCIE;
    TB1CTL = TBSSEL_2 + MC_1 + ID_3;    //sets SMCLK, Up mode
    TB1CCR0 = 25000;                    //5Hz  (green LED speed)

    __enable_interrupt();
    while(1);
}
#pragma vector = TIMER0_B0_VECTOR
__interrupt void TB0_ISR(void)
{
P2OUT ^= BIT0;                          //toggles red LED
}

#pragma vector = TIMER1_B0_VECTOR
__interrupt void TB1_ISR(void)
{
P1OUT ^= BIT0;                          //toggles green LED
}
