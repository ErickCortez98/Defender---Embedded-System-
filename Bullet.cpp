//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Bullet.h" 
#include <stdint.h>
#include "Images.h"

Bullet::Bullet(){
	 bulletSprite = Sprite(32, 80,  BulletImage, 8, 5);
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
	//TODO: Change 107 for the actual width of the LCD
	while(x_position < 107){
		this->UpdatePos(x_position+20, Player.sprite.Gety()-2);
		this->Draw();
		x_position+=2;
		//delay
		for(int i = 0; i < 10000; i++){
		}
	}
}

