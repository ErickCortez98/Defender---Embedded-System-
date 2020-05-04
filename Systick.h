//Provides implementation of Systick functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include <stdint.h>

extern "C" void SysTick_Handler(void);

void SysTick_Init(uint32_t period);

void SysTick_Handler(void);
