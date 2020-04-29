//Provides implementation of playership class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "Sprite.h"
#include "ST7735.h"

void Sprite::Draw(){
  ST7735_DrawBitmap(x, y, image, w, h);
}

uint16_t Sprite::Getx(){
  return x;
}
  
uint16_t Sprite::Gety(){
  return y;
}
  
void Sprite::UpdatePos(uint16_t new_x, uint16_t new_y){
  x = new_x;
  y = new_y;
}


