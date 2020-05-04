//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Bullet.h" 
#include <stdint.h>
#include "Images.h"
#include "ST7735.h"
#include "Random.h"

#define SCREENWIDTH 160

uint8_t fireBulletFlag = 0;

Bullet::Bullet(){
	bulletSprite = Sprite(BulletImage, 1, 2);
  x = 0;
  start_x = x - 1;
  y = 0;
  color = ST7735_BLACK;
  dir = right;
  status = alive;
}

Bullet::~Bullet(){
  if(dir == right){
    ST7735_DrawFastVLine(y, start_x - 10, x - start_x + 10, ST7735_BLACK);
  }else{
    ST7735_DrawFastVLine(y, x, start_x - x + 12, ST7735_BLACK);
  }
}


//helper function to get the even x position used in fireBullet function
int16_t makeCloseEven(int16_t x_position){
	if(x_position % 2 != 0){
		x_position++;
			return x_position;
	}else{
			return x_position;
	}
}

Bullet::Bullet(int16_t new_x, uint8_t new_y, direction_t new_dir){
  dir = new_dir;
  x = makeCloseEven(new_x);
  if(dir == left){
    x -= 21;
  }
  
  start_x = x - 1;
  y = new_y + 3;
  
  color = ST7735_Color565(Random(), Random(), Random());
  
	bulletSprite = Sprite(BulletImage, 1, 2);
  status = alive;
}


void Bullet::Draw(){ 
  int16_t length = 10;
  uint8_t pixel_deletion_factor = 3;
  if(dir == right){
    ST7735_DrawFastVLine(y, x - 10, length, color);
    for(uint8_t i = 0; i < pixel_deletion_factor; i++){
      uint8_t rnum = Random() % (x - start_x + 10);
      ST7735_DrawPixel(y, rnum + start_x - length, ST7735_BLACK);
    }
  }else{
    ST7735_DrawFastVLine(y, x, length, color);
    for(uint8_t i = 0; i < pixel_deletion_factor; i++){
      uint8_t rnum = Random() % (start_x + 10 - x);
      ST7735_DrawPixel(y, start_x - rnum + length, ST7735_BLACK);
    }
  }
  
	bulletSprite.Draw(x, y);
  if(dir == right){
    UpdatePos(x + 2, y);
  }else{
    UpdatePos(x - 2, y);
  }
  if(x > SCREENWIDTH+5 || x < 0){//MIGHT HAVE PROBLEMS WHEN BULLET EXITS LEFT OF SCREEN
    status = dead;
  }
}

void Bullet::UpdatePos(int16_t new_x, uint16_t new_y){
	x = new_x;
  y = new_y;
}


int16_t Bullet::Getx(){
  return x;
}
  
uint8_t Bullet::Gety(){
  return y;
}

status_t Bullet::GetStatus(){
  return status;
}

