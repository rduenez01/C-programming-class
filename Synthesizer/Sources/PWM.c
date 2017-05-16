#include <mc9s12c32.h>
#include "derivative.h"   /* derivative-specific definitions */
#include "main_asm.h"     /* interface to the assembly module */
#include <hidef.h>        /* common defines and macros */
#define MS_20 20000 // Number of clocks for 20ms on a 2MHz clock
static int stopflag = 0;
/*
This function is the initator that starts a Time Output
Compare thread to generate a pulse out for every 20 ms (or 50 Hz). This function
need only get the interrupt started so the preliminary interrupt should not stay at a
50 Hz signal. Setting the frequency should be done by the ISR */

void start_PWM(void){
TC0 = TCNT + MS_20;
TFLG1 = 1;          // Clear C0F Flag
TIE_C0I = 1;        // Enable local interrupt for timer channel 0
EnableInterrupts;        
}



/*: This function stops the timer and the thread at the end of
the interval using a software flag, leaving the output low. DO NOT prematurely
force the pulse output low.*/

void stop_PWM(void){
stopflag =1;

}



/*: Initializes appropriate pins, variables, whatever is
necessary for this thread to use Timer Output Compare. This is not the same as
starting your interrupts*/

void init_PWM(void){
  TCTL2_OL0 = 0;
  TCTL2_OM0 = 1;   // Toggle mode
  TIOS_IOS0 = 1;   // Enable Output Compare 0 
}



/*The ISR responds to the timer output compare
interrupts. The ISR should immediately call Read_Pot() to obtain the new
interrupt time scale, Hz. The value of Hz is in the range of 0-1023, so it must be
scales to obtain a true interval in microseconds. To do this, please refer to the
tables below. You are required to be able to generate a sound of C5 to C6. This
ISR insures the overall shape of the output by making the output the opposite
value it is currently outputting for the appropriate number of seconds. Remember
that each portion of the pulse is half the required time for the frequency being
generated.*/

void interrupt PWM_ISR(void){
	unsigned short output;

	output = ReadPot();
	  if(output >= 0 && output <= 92){
	  TC0 = TCNT + 1912;
	  }
	  else if(output >= 93 && output <=185){
	  TC0 = TCNT + 1704;
	  }
	  else if(output >= 186 && output <=278){
	  TC0 = TCNT + 1518;  
	  }
	  else if(output >= 279 && output <=371){
	  TC0 = TCNT + 1430;
	  }
	  else if(output >= 372 && output <=464){
	  TC0 = TCNT + 1276;
	  }
	  else if(output >= 465 && output <=557){
	  TC0 = TCNT + 1136;
	  }
	  else if(output >= 558 && output <=650){
	  TC0 = TCNT + 1012;
	  }
	  else if(output >= 651 && output <=743){
	  TC0 = TCNT + 956;
	  }
	  if( stopflag == 0)
	    TIE = 0X00;
	  else
	    TFLG1 = 1;          // Clear C0F Flag  


}

