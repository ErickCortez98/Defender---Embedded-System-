//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Bullet.h" 
#include <stdint.h>
#include "Images.h"

#define SCREENWIDTH 160

uint8_t fireBulletFlag = 0;

Bullet::Bullet(){
	bulletSprite = Sprite(32, 80,  BulletImage, 5, 25);
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

Bullet::Bullet(uint8_t x, uint8_t y){
  x = makeCloseEven(x);
	bulletSprite = Sprite(x+10, y+1,  BulletImage, 5, 25);
  status = alive;
}


void Bullet::Draw(){
	bulletSprite.Draw();
  UpdatePos(Getx() + 2, Gety());
  if(Getx() > SCREENWIDTH+50 || Getx() == 0){//MIGHT HAVE PROBLEMS WHEN BULLET EXITS LEFT OF SCREEN
    status = dead;
  }
}

void Bullet::UpdatePos(uint16_t x, uint16_t y){
	bulletSprite.UpdatePos(x, y);
}


uint8_t Bullet::Getx(){
  return bulletSprite.Getx();
}
  
uint8_t Bullet::Gety(){
  return bulletSprite.Gety();
}

status_t Bullet::GetStatus(){
  return status;
}

