//Provides implementation of button inputs 
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Buttons.h"
#include <stdint.h>
#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"


//PE3 NOT CURRENTLY USED=======================
//PE0 = Fire
//PE1 = Hyperspace
//PE2 = Switch direction
void Buttons_Init(void){volatile int delay;
	SYSCTL_RCGCGPIO_R |= 0x10;   // enable clock to E
  delay = 0;
	GPIO_PORTE_AMSEL_R &= ~0xF; //disable analog function on PE3-0
	GPIO_PORTE_PCTL_R &= ~0x0000FFFF; //Configure PE3-0 as GPIO
  GPIO_PORTE_DIR_R &= ~0xF;    // input PE3-0
	GPIO_PORTE_AFSEL_R &= ~0xF; //disable alt function on PE3-0
  GPIO_PORTE_DEN_R |= 0x0F;     // enable digital on PE3-0
	GPIO_PORTE_PDR_R |= 0x0F;			//enable pull down resistors on PE3-0 (that way we don't need externa resistors)
	
	GPIO_PORTE_IS_R &= ~0xF; //PE3-0 are edge sensitive
	GPIO_PORTE_IBE_R &= ~0xF; //PE3-0 are not both edges
	GPIO_PORTE_IEV_R |= 0xF;	//PE3-0 rising edge event
	GPIO_PORTE_ICR_R = 0xF; //Clear flag of PE3-0
	GPIO_PORTE_IM_R |= 0xF; //enable interrupts on PE3-0
	NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF00) | 0x00000040; //Priority 2
	NVIC_EN0_R = 0x00000010;	//Enable interrupt 4 (Port E) in NVIC

}

bool FireButton(void){
  return GPIO_PORTE_RIS_R&0x1; // return input from keys
}

bool HyperButton(void){
  return GPIO_PORTE_RIS_R&0x2; // return input from keys
}

bool DirButton(void){
  return GPIO_PORTE_RIS_R&0x4; // return input from keys
}

