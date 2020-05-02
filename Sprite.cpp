//Provides implementation of playership class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "Sprite.h"
#include "ST7735.h"

void Sprite::Draw(uint8_t x, uint8_t y){
  ST7735_DrawBitmap(y, x, image, w, h);
}



