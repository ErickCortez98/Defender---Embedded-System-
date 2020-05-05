//Provides implementation of playership class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "Sprite.h"
#include "ST7735.h"

void Sprite::Draw(int x, uint8_t y){
  int xdif = x - last_x;
  int ydif = y - last_y;
  
  if(xdif < 0){
    xdif *= -1;
  }
  if(ydif < 0){
    ydif *= -1;
  }
  
  if(xdif > 2 || ydif > 2){
    ST7735_FillRect(last_y, last_x - 19, 12, 19, ST7735_BLACK);
  }
  
  if(x >= 0){
    ST7735_DrawBitmap(y, x, image, w, h);
  }
  
  last_x = x;
  last_y = y;
}



