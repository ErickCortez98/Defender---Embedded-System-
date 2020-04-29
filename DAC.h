// dac.h
// This software configures DAC output
// Lab 6 requires a minimum of 4 bits for the DAC, but you could have 5 or 6 bits
// Runs on LM4F120 or TM4C123
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
// Date Created: 3/6/17 
// Last Modified: 1/17/2020 
// Lab number: 6
// Hardware connections
// 4-bit DAC OUTPUTS TO PINS B0-B3 ----- 4 buttons INPUT TO PINS E0-E3
// Resistors OF DAC PB0 - 12K, PB1 - 6K, PB2 - 3K, PB3 - 1.5K

#ifndef DAC_H
#define DAC_H
#include <stdint.h>
// Header files contain the prototypes for public functions
// this file explains what the module does

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void);


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Input=n is converted to n*3.3V/15
// Output: none
void DAC_Out(uint8_t data);

#endif
