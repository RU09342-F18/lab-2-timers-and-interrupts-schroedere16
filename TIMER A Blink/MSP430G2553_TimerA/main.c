#include <msp430.h>


volatile unsigned int timerCount = 0;
volatile unsigned int timerCount1 = 0;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    BCSCTL3 = LFXT1S_2;         //THIS LINE IS REQUIRED IF USING A CLOCK
	P1OUT |= (BIT0);            //sets the LED at p1.0 to on
    P1OUT &= ~BIT6;             //sets the LED at p1.6 to be off
	P1DIR |= (BIT0 + BIT6);     //sets pin 1.0 and 1.6 to output
    CCTL0 = CCIE;               //
    CCR0 = 999;
    TACTL = TASSEL_1 + MC_1;
    __enable_interrupt();       //enables the interrupt
    while(1);
}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
	{
    timerCount = (timerCount + 1);
    if(timerCount ==8){
	  P1OUT ^= BIT0;
	  timerCount = 0;
    }
    timerCount1 = (timerCount1 + 1);
    if(timerCount1 ==32){
      P1OUT ^= BIT6;
      timerCount1 = 0;
    }
	}
