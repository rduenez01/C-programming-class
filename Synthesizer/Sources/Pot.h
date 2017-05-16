// Authors: Aaron Holloway & Roberto Duenez
// Lab 6
// Initialize the ADC to read from the Potentiometer
// on channel 5
// Input: none
// Output: none
void Pot_init(void);

// Starts conversion on channel 5, waits for results and then returns it 
// Input: none
// Output: Result register 0
unsigned short Read_Pot(void);