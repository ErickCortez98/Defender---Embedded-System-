//Provides implementation of button inputs 
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Buttons.h" 
#include <stdint.h>
#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"

//extern "C" void Buttons_Init(void);

//PE3 NOT CURRENTLY USED=======================
//PE0 = Fire
//PE1 = Hyperspace
//PE2 = Switch direction
void Buttons_Init(void){volatile int delay;
  SYSCTL_RCGCGPIO_R |= 0x10;   // enable clock to E
  delay = 0;
  GPIO_PORTE_DIR_R &= ~0xF;    // input PE3-0
  GPIO_PORTE_DEN_R |= 0x0F;     // enable digital on PE3-0
}

bool FireButton(void){
  return 0x01 & GPIO_PORTE_DATA_R; // return input from keys
}

bool HyperButton(void){
  return (0x02 & GPIO_PORTE_DATA_R) >> 1; // return input from keys
}

bool DirButton(void){
  return (0x04 & GPIO_PORTE_DATA_R) >> 2; // return input from keys
}

