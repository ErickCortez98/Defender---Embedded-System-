//Various helper fns moved out of main.c
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/1/2020


#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"
#include "ST7735.h"
#include <stdint.h>

#ifndef HELPER_H
#define HELPER_H


void LCD_OutDec1(uint32_t n){
    char num;
    if(n < 10){
		 ST7735_OutChar('0' + n);
        return;
    }
    num = ('0' + (n%10));
    LCD_OutDec1(n/10);
		ST7735_OutChar(num);
} 

void Heartbeat_Init(){
	//Set up for the LED heartbeat
	SYSCTL_RCGCGPIO_R |= 0x20;
		while((SYSCTL_RCGCGPIO_R & 0x20) == 0){};	//Waiting for clock to be ready
	GPIO_PORTF_DIR_R |= 0x04;
	GPIO_PORTF_DEN_R |= 0x04;
}

void toggle_Heartbeat(){
  GPIO_PORTF_DATA_R ^= 0x04;
}

void SysTick_Init(void){
	// write this
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x00000005;
}

/*void SysTick_Handler(void){
	//Nothing for now
  if(SoundOn){
    //set DAC to next element of sine wave
    DAC_Out(SineWave4Bit[IndexSine++]);
    if(IndexSine > 63)
      IndexSine = 0;
  }
  else{
    DAC_Out(0);
  }
}*/




#endif
