//Provides implementation of start screen class
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 05/03/2020

#include "StartScreen.h"
#include "Images.h"
#include "ST7735.h"
#include "HelperFns.h"

void drawStartScreen(void){
	ST7735_FillScreen(0x0000); //Black screen
	ST7735_DrawBitmap(60, 138, Defender_Logo, 26, 120); //Draw Defender logo image 
	//ST7735_DrawBitmap(0, 12, Enemy_1, 12, 15);
	ST7735_SetTextColor(ST7735_WHITE);
	ST7735_SetRotation(1);
	ST7735_SetCursor(8, 8);
	ST7735_OutString((char*)"Press Start!");
	ST7735_SetRotation(0);
}

void drawYouLoseScreen(uint32_t Score){
	ST7735_FillScreen(0x0000); //Black screen
	ST7735_DrawBitmap(60, 138, Game_Over, 25, 120);
	ST7735_SetTextColor(ST7735_WHITE);
	ST7735_SetRotation(1);
	if(Score < 10000){
		ST7735_SetCursor(5, 8);
		ST7735_OutString((char*)"Your Score:");
		ST7735_SetCursor(16, 8);
		LCD_OutDec1(Score);
	}else{
		ST7735_SetCursor(4, 8);
		ST7735_OutString((char*)"Your Score:");
		ST7735_SetCursor(15, 8);
		LCD_OutDec1(Score);
	}
	ST7735_SetRotation(0);
}
