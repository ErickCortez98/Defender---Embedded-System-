//Provides implementation of enemy class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/01/2020

#include "Enemy.h" 
#include <stdint.h>
#include "Images.h"
#include "Random.h"

#define MAXENEMIES 10

Enemy::Enemy (uint8_t x, uint8_t y, uint8_t typeEnemy){
		//if enemy's live is 50, then we now is enemy type 1, otherwise, it is 100, so the enmey is type 2
		if(typeEnemy == 1){
			enemySprite = Sprite(Enemy_1, 12, 13);
			this->live = 50; //max live of small enemy
		}else{
			enemySprite = Sprite(Enemy_2, 8, 15);
			this->live = 100; //max live of big enemy
		}
		this->status = alive;
		this->x = x;
		this->y = y;
}
//helper function to go up or down in the vertical positon
int8_t Enemy::randomUpDownFn(){
	 int random1to3 = Random() % 3; //we get either 0, 1 or 2
	
	if(getY() < 10){
		//we go up
		return 1;
	}else if(getY() > 70){
		//we go down
		return -1;
	}
	
	if(random1to3 == 0){
		//we go straight 
		return 0;
	}else if(random1to3 == 1){
		//we go up
		return 1;
	}else{
		//we go down
		return -1;
	}
}
uint8_t Enemy::getX(){
	return this->x;
}
uint8_t Enemy::getY(){
	return this->y;
}
status_t Enemy::getStatus(){
	return status;
}
void Enemy::setStatus(status_t newStatus){
	this->status = newStatus;
}
uint8_t Enemy::getLive(){
	return live;
}
void Enemy::reduceLive(uint8_t liveReduction){
	this->live -= liveReduction;
}
void Enemy::Draw(){
	enemySprite.Draw(x, y);
	//updating enemy position to the left
	UpdatePos(getX() - 1, getY()  + randomUpDownFn());
	//Checking if we are outside the screen meaning the status changes to dead alien! (FOR NOW)
	if(getX() < 1){
    status = dead;
  }
}
void Enemy::UpdatePos(uint16_t new_x, uint16_t new_y){
		x = new_x;
		y = new_y;
}
