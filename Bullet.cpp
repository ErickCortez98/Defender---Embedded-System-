//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Bullet.h" 
#include <stdint.h>
#include "Images.h"

#define SCREENWIDTH 160

uint8_t fireBulletFlag = 0;

Bullet::Bullet(){
	bulletSprite = Sprite(BulletImage, 5, 25);
  x = 0;
  y = 0;
  status = alive;
}


//helper function to get the even x position used in fireBullet function
int8_t makeCloseEven(int8_t x_position){
	if(x_position % 2 != 0){
		x_position++;
			return x_position;
	}else{
			return x_position;
	}
}

Bullet::Bullet(uint8_t new_x, uint8_t new_y){
  x = makeCloseEven(new_x) + 10;
  y = new_y + 1;
	bulletSprite = Sprite(BulletImage, 5, 25);
  status = alive;
}


void Bullet::Draw(){
	bulletSprite.Draw(x, y);
  UpdatePos(x + 2, y);
  if(x > SCREENWIDTH+50 || x == 0){//MIGHT HAVE PROBLEMS WHEN BULLET EXITS LEFT OF SCREEN
    status = dead;
  }
}

void Bullet::UpdatePos(uint16_t new_x, uint16_t new_y){
	x = new_x;
  y = new_y;
}


uint8_t Bullet::Getx(){
  return x;
}
  
uint8_t Bullet::Gety(){
  return y;
}

status_t Bullet::GetStatus(){
  return status;
}

