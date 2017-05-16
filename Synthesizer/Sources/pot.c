#include <mc9s12c32.h>
#define AN5     0x05        // channel 5, INPUT



void Pot_init(void) {
   /* Analog input allowed on ADC channel 5 */
    DDRAD &= ~0x20;
    ATDDIEN &= ~0x20;
    
    ATDCTL3 = 0x08;		      //sequence length = 1
    ATDCTL4_SRES8 = 0;      //10 bits resolution
	  ATDCTL2_ADPU = 1;       //power up    

}


//This function starts a conversion on the
//channel to which the pot is connected, waits for it, and returns the 10-bit value.
unsigned short Read_Pot(void) {

     unsigned char convert;
    /* Right justified result, channel 5 */
    convert = ATDCTL5_DJM_MASK| AN5;
    /* Start conversion */
    ATDCTL5 = convert;
    /* Wait for and retrieve sample */
    while (ATDSTAT0_SCF == 0) {
    }
    return ATDDR0;         //return 10 bits

}