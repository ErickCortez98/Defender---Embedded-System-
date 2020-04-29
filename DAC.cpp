// dac.c
// This software configures DAC output
// Lab 6 requires a minimum of 4 bits for the DAC, but you could have 5 or 6 bits
// Runs on LM4F120 or TM4C123
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
// Date Created: 3/6/17 
// Last Modified: 4/2/2020 
// Lab number: 6
// Hardware connections
// 4-bit DAC OUTPUTS TO PINS B0-B3 ----- 4 buttons INPUT TO PINS E0-E3
// Resistors OF DAC PB0 - 12K, PB1 - 6K, PB2 - 3K, PB3 - 1.5K

#include <stdint.h>
#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){volatile int delay;
  SYSCTL_RCGCGPIO_R |= 0x02;   // enable clock to B
  delay = 0;
  GPIO_PORTB_DIR_R |= 0x0F;     // output on PB3-0
  GPIO_PORTB_DEN_R |= 0x0F;     // enable digital on PB3-0
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Input=n is converted to n*3.3V/15
// Output: none
void DAC_Out(uint32_t data){
  GPIO_PORTB_DATA_R &= ~0x0F;
  GPIO_PORTB_DATA_R |= data;
}
