//Provides implementation of enemy class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/01/2020

#include "Enemy.h" 
#include <stdint.h>
#include "Images.h"

#define MAXENEMIES 10

Enemy::Enemy (uint8_t x, uint8_t y, uint8_t typeEnemy){
		//if enemy's live is 50, then we now is enemy type 1, otherwise, it is 100, so the enmey is type 2
		if(typeEnemy == 1){
			enemySprite = Sprite(x, y, Enemy_1, 12, 13);
			this->status = 1;
			this->live = 50; //max live of small enemy
		}else{
			enemySprite = Sprite(x, y, Enemy_2, 8, 15);
			this->status = 1;
			this->live = 100; //max live of big enemy
		}
}
uint8_t Enemy::getX(){
	return enemySprite.Getx();
}
uint8_t Enemy::getY(){
	return enemySprite.Gety();
}
uint8_t Enemy::getStatus(){
	return status;
}
void Enemy::setStatus(uint8_t newStatus){
	this->status = newStatus;
}
uint8_t Enemy::getLive(){
	return live;
}
void Enemy::reduceLive(uint8_t liveReduction){
	this->live -= liveReduction;
}
void Enemy::Draw(){
	enemySprite.Draw();
	//updating enemy position to the left
	UpdatePos(getX() - 1, getY());
	//Checking if we are outside the screen meaning the status changes to dead alien! (FOR NOW)
	if(getX() < 1){
    status = 0;
  }
}
void Enemy::UpdatePos(uint16_t x, uint16_t y){
	enemySprite.UpdatePos(x, y);
}
