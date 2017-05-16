// TITLE: "Lab 6 - ECE 3436"
// Authors: Roberto Duenez & Aaron Holloway
// Details: Enter command from keyboard to 
// display voltage on TeraTerm.

#include <hidef.h>        /* common defines and macros */
#include "derivative.h"   /* derivative-specific definitions */
#include "SCI.h"
#include "main_asm.h"     /* interface to the assembly module */
#include <string.h>
#include "Pot.h"


void main(void) {

  char prompt[]= "Waiting for user command";
  char signal;
  unsigned short output = 0;
  // Initialization
  Pot_init();
  SCI_Init(9600);
  
  while(1){ 
      SCI_OutString(prompt);
      SCI_OutChar(10);
      SCI_OutChar(13);
      signal = SCI_InChar();
      if(signal){
        output = Read_Pot();
        SCI_OutUHex(output);
        SCI_OutChar(10);
        SCI_OutChar(13);
      }
      signal = 0;
  }
 
}

