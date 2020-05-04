//Provides implementation of Systick functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include <stdint.h>
#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"
#include "Sound.h"
#include "Systick.h"


void SysTick_Init(uint32_t period){
	// write this
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = period;
	NVIC_ST_CURRENT_R = 0;
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF) | 0x40000000;//priority 2
	NVIC_ST_CTRL_R = 0x00000007;//enable systick with interupts
}

void SysTick_Handler(void){
	SoundTask(); //everytime the systick handler gets executed, so at 11kHz, we execute the SoundTask function inside Sound.cpp
}
