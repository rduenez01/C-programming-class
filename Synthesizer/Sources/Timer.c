#include <mc9s12c32.h>
#define PRESC_M 0x01
void MyTimerInit(void){
  
  TSCR2 |= PRESC_M; // Prescale to 2 MHz
  TSCR1_TEN = 1;    // Enable the timer
  
}

