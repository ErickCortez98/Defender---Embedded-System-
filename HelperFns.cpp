//Various helper fns moved out of main.c
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/1/2020


#include "HelperFns.h"

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
