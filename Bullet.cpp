//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Bullet.h" 
#include <stdint.h>

void Bullet::Draw(){
	bulletSprite.Draw();
}

void Bullet::UpdatePos(uint16_t x, uint16_t y){
	bulletSprite.UpdatePos(x, y);
}

void Bullet::fireBullet(PlayerShip Player){
	//TODO: Change 200 for the actual width of the LCD
	for(int i = Player.sprite.Getx(); i < 200; i++){
		this->UpdatePos(i+20, Player.sprite.Gety()-2);
		this->Draw();
		//delay
		for(int i = 0; i < 10000; i++){
		}
	}
}
