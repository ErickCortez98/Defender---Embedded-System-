//Various helper fns moved out of main.c
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/1/2020


#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"
#include "ST7735.h"
#include <stdint.h>
#include "Sound.h"


#ifndef HELPER_H
#define HELPER_H


void LCD_OutDec1(uint32_t n);

void Heartbeat_Init();

void toggle_Heartbeat();

#endif
