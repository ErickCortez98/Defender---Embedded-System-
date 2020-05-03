//Provides implementation of start screen class
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 05/03/2020

#include "StartScreen.h"
#include "Images.h"
#include "ST7735.h"

void drawStartScreen(void){
	ST7735_FillScreen(0x0000); //Black screen
	ST7735_DrawBitmap(60, 138, Defender_Logo, 26, 120); //Draw Defender logo image 
	ST7735_SetTextColor(ST7735_WHITE);
	ST7735_SetRotation(1);
	ST7735_SetCursor(8, 8);
	ST7735_OutString((char*)"Press Start!");
	ST7735_SetRotation(0);
}
