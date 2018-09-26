#include <msp430.h>

void main(void)
{
WDTCTL = WDTPW + WDTHOLD;   // Stop watchdog timer
P1OUT |= BIT3;              //sets button to output allowing it to trigger LED
P1REN |= BIT3;              //enables pull up resistor to allow button toggle
P1DIR |= BIT0;              // Set P1.0 to output direction
P1IE |= BIT3;               // P1.3 interrupt enabled
P1IFG &= ~BIT3;             // P1.3 IFG cleared interrupt flag register
__enable_interrupt();
}

#pragma vector=PORT1_VECTOR             //two lines used for interrupt of PORT1
__interrupt void Port_1(void)
{
P1OUT ^= BIT0;                          // P1.0 = toggle the LED
P1IFG &= ~BIT3;                         // P1.3 IFG cleared
}
