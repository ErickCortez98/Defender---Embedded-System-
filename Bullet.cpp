//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Bullet.h" 
#include <stdint.h>
#include "Images.h"

#define SCREENWIDTH 160

uint8_t fireBulletFlag = 0;

Bullet::Bullet(){
	bulletSprite = Sprite(Bullet_Laser, 1, 25);
  x = 0;
  y = 0;
  dir = right;;
  status = alive;
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
  if(dir == right){
    x += 14; 
  }else{
    x -= 14; 
  }
  
  y = new_y + 1;
  
	bulletSprite = Sprite(BulletImage, 5, 25);
  status = alive;
}


void Bullet::Draw(){
	bulletSprite.Draw(x, y);
  if(dir == right){
    UpdatePos(x + 2, y);
  }else{
    UpdatePos(x - 2, y);
  }
  if(x > SCREENWIDTH+50 || x < -50){//MIGHT HAVE PROBLEMS WHEN BULLET EXITS LEFT OF SCREEN
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

