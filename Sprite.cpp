//Provides implementation of playership class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "Sprite.h"
#include "ST7735.h"

void Sprite::Draw(){
  ST7735_DrawBitmap(y, x, image, w, h);
}

uint8_t Sprite::Getx(){
  return x;
}
  
uint8_t Sprite::Gety(){
  return y;
}
  
void Sprite::UpdatePos(uint8_t new_x, uint8_t new_y){
  x = new_x;
  y = new_y;
}


