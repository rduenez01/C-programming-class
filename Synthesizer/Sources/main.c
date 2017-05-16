// TITLE: "Lab 7 - ECE 3436"
// Authors: Roberto Duenez & Aaron Holloway
// Details: Enter command from keyboard to 
// display voltage on TeraTerm.

#include <hidef.h>        /* common defines and macros */
#include "derivative.h"   /* derivative-specific definitions */
#include "SCI.h"
#include "main_asm.h"     /* interface to the assembly module */
#include <string.h>
#include "Pot.h"
#include "Timer.h"
#include "PWM.h"

void main(void) {

  

  char prompt[]= "Waiting for user command (enter help for list of commands)";
  char command[100];
  
  unsigned short output = 0;
  // Initialization
  Pot_init();
  MyTimerInit();
  init_PWM();	  
  SCI_Init(9600);
  TIE_C0I = 1;        // Enable local interrupt for timer channel 0
  TC0 = TCNT;
  EnableInterrupts;
  
  
  while(1){
      TFLG1 = 1;
      SCI_OutString(prompt);
      SCI_OutChar(10);
      SCI_OutChar(13);
	    SCI_InString(command,100) ;
  	  SCI_OutChar(10);
	    SCI_OutChar(13);

  
	  switch(command[2])   {
	  	
	  
		case 'l':
			  SCI_OutChar(10);
	    	SCI_OutChar(13);	 
		    SCI_OutString("help - Display command" );
		    SCI_OutChar(10);
	    	SCI_OutChar(13);	
	    	SCI_OutString("strt - Starts buzzer");
	    	SCI_OutChar(10);
	    	SCI_OutChar(13);	
	    	SCI_OutString("stop - Stops buzzer");
	    	SCI_OutChar(10);
	    	SCI_OutChar(13);	
	    	SCI_OutString("read - Reads ADC and interprets note");
	    	SCI_OutChar(10);
	    	SCI_OutChar(13);
	    	
			break;
		case 'r':	
			start_PWM();
			TFLG1 = 1;
			break;
		case 'o':
			stop_PWM();
			break;
		case 'a':
			output = Read_Pot();       
	        if((output >= 0) && (output <= 92)){
		 	SCI_OutString("C5");
		  	}
		 	else if(output >= 93 && output <=185){
		  	SCI_OutString("D5");
		  	}
		 	else if(output >= 186 && output <=278){
		 	SCI_OutString("E5");  
		 	}
		 	else if(output >= 279 && output <=371){
		 	SCI_OutString("F5");
		 	}
			else if(output >= 372 && output <=464){
		 	SCI_OutString("G5");
		 	}
		 	else if(output >= 465 && output <=557){
		 	SCI_OutString("A5");
		 	}
		 	else if(output >= 558 && output <=650){
		 	SCI_OutString("B5");
		 	}
			else if(output >= 651 && output <=743){
		  	SCI_OutString("C6")	 ;
			}
		  	  SCI_OutChar(10);
	        SCI_OutChar(13);
	        break;
	  default:
	     	SCI_OutString("Enter correct command...");
	     	SCI_OutChar(10);
	    	SCI_OutChar(13);
	  }	 // end switch	 
  }// end while

  		
} // end main


  


