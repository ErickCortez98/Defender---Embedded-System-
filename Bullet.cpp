//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Bullet.h" 
#include <stdint.h>
#include "Images.h"

#define SCREENWIDTH 160

uint8_t fireBulletFlag = 0;

Bullet::Bullet(){
	 bulletSprite = Sprite(32, 80,  BulletImage, 5, 11);
};

//helper function to get the even x position used in fireBullet function
int8_t makeCloseEven(int8_t x_position){
	if(x_position % 2 != 0){
		x_position++;
			return x_position;
	}else{
			return x_position;
	}
}

void Bullet::Draw(){
	bulletSprite.Draw();
}

void Bullet::UpdatePos(uint16_t x, uint16_t y){
	bulletSprite.UpdatePos(x, y);
}

void Bullet::fireBullet(PlayerShip Player){
	uint8_t x_position = Player.sprite.Getx();
	x_position = makeCloseEven(x_position);	//getting only even x positions as recommended in the lab descriptor 
	
	while(x_position < SCREENWIDTH+5){
		this->UpdatePos(x_position+5, Player.sprite.Gety()+1);
		this->Draw();
		x_position += 2;
		//delay
		for(int i = 0; i < 10000; i++){
		}
	}
}

