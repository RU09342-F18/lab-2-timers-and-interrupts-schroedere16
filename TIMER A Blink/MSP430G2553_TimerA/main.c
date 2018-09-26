/* 
  Author Eric Schroeder
  Written: September 24, 2018
  Last Updated:September 26, 2018 */

#include <msp430.h>

volatile unsigned int timerCount = 0;		//creates a variable and sets the intial value to 0
volatile unsigned int timerCount1 = 0;		//creates a variable and sets the intial value to 0
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    	BCSCTL3 = LFXT1S_2;         //THIS LINE IS REQUIRED IF USING ACLK due to TI board design
	P1OUT |= (BIT0);            //sets the LED at p1.0 to on
    	P1OUT &= ~BIT6;             //sets the LED at p1.6 to be off
	P1DIR |= (BIT0 + BIT6);     //sets pin 1.0 and 1.6 to output
    	CCTL0 = CCIE;               
    	CCR0 = 999;		    
    	TACTL = TASSEL_1 + MC_1;    // sets the ACLK to be active clock used with TASSEL_1
    	__enable_interrupt();       //enables the interrupt
    	while(1);
}
#pragma vector=TIMER0_A0_VECTOR		//these two lines set up the timer 1 interrupt
__interrupt void Timer_A (void)
	{
    timerCount = (timerCount + 1);	//this increments the first variable by 1
    if(timerCount ==8){			//if statement checks if the timer has counted enough to turn LED on or off
	  P1OUT ^= BIT0;		//toggles the LED on or off
	  timerCount = 0;		//resets the timer to allow the loop to begin again
    }
    timerCount1 = (timerCount1 + 1);	//this increments the second variable by 1 
    if(timerCount1 ==32){		//if statement checks if the timer has counted enough to turn LED on or off
      P1OUT ^= BIT6;			//toggles the LED on or off
      timerCount1 = 0;			//resets the timer to allow the loop to begin again
    }
	}
