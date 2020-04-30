// SlidePot.cpp
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0
// Student names: Jaxon Coward, Erick Cortez
// Last modification date: 04/19/2020

#include <stdint.h>
#include "SlidePot.h"
#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"

// ADC initialization function 
// Input: none
// Output: none
// measures from PD2, analog channel 5
void ADC_Init(void){ 
//*** students write this ******
	SYSCTL_RCGCADC_R |= 0x0001;   // 1) activate ADC0
  SYSCTL_RCGCGPIO_R |= 0x08;    // activating clock for port D
  while((SYSCTL_PRGPIO_R&0x08) == 0){};  // for stabilization
  GPIO_PORTD_DIR_R &= ~0x04;    // make PD2 an input
  GPIO_PORTD_AFSEL_R |= 0x04;   // enable alternate function on PD2
  GPIO_PORTD_DEN_R &= ~0x04;    // disable digital I/O on PD2
  GPIO_PORTD_AMSEL_R |= 0x04;   // enable analog functionality on PD2
  while((SYSCTL_PRADC_R&0x0001) != 0x0001){};
  ADC0_PC_R &= ~0xF;
  ADC0_PC_R |= 0x1;             // 8) configure for 125K samples/sec
  ADC0_SSPRI_R = 0x0123;        // 9) Sequencer 3 is highest priority
  ADC0_ACTSS_R &= ~0x0008;      // 10) disable sample sequencer 3
  ADC0_EMUX_R &= ~0xF000;       // 11) seq3 is software trigger
  ADC0_SSMUX3_R &= ~0x000F;
  ADC0_SSMUX3_R += 5;           // 12) set channel
  ADC0_SSCTL3_R = 0x0006;       // 13) no TS0 D0, yes IE0 END0
  ADC0_IM_R &= ~0x0008;         // 14) disable SS3 interrupts
  ADC0_ACTSS_R |= 0x0008;       // 15) enable sample sequencer 3
}

//------------ADCIn------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
// measures from PD2, analog channel 5
uint32_t ADC_In(void){  
//*** students write this ******
	uint32_t result;
	ADC0_PSSI_R = 0x0008; //Init sequencer 3
	while((ADC0_RIS_R&0x08) == 0){}; //waiting for the analog to digital conversion to be done
	result = ADC0_SSFIFO3_R&0xFFF; 	//getting the result 
	ADC0_ISC_R = 0x0008;             // acknowledge completion
  return result; // remove this, replace with real code
}

// constructor, invoked on creation of class
// m and b are linear calibration coeffients 
SlidePot::SlidePot(uint32_t m, uint32_t b){
//*** students write this ******
// initialize all private variables
// make slope equal to m and offset equal to b
  data = 0;
  flag = 0;
  distance = 0;
  
  slope = m;
  offset = b;
}

void SlidePot::Save(uint32_t n){
//*** students write this ******
// 1) save ADC sample into private variable
  data = n;
// 2) calculate distance from ADC, save into private variable
  distance = Convert(data);
// 3) set semaphore flag = 1
  flag = 1;
}
uint32_t SlidePot::Convert(uint32_t n){
  //*** students write this ******
  // use calibration data to convert ADC sample to distance
	//FORMULA OBTAINED FROM CALIBRATION
  //d = 160*data/4096 + 16.519 = 160 * data / 4096 + 17
	//distance is in 0.01 cm 
	return (((slope * n) / 4096) + offset); 
}

void SlidePot::Sync(void){
// 1) wait for semaphore flag to be nonzero
  while(flag == 0){}
// 2) set semaphore flag to 0
    flag = 0;
}

uint32_t SlidePot::ADCsample(void){ // return ADC sample value (0 to 4095)
  //*** students write this ******
  // return last calculated ADC sample
  return data;
}

uint32_t SlidePot::Distance(void){  // return distance value (0 to 2000), 0.001cm
  //*** students write this ******
  // return last calculated distance in 0.001cm
  return distance;
}


