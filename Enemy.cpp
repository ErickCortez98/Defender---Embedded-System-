//Provides implementation of enemy class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/01/2020

#include "Enemy.h" 
#include <stdint.h>
#include "Images.h"
#include "Random.h"
#include "ST7735.h"
#define SCREENWIDTH 160
#define MAXENEMIES 10

Enemy::Enemy (int x, uint8_t y, uint8_t typeEnemy, direction_t direction){
		//if enemy's live is 50, then we now is enemy type 1, otherwise, it is 100, so the enmey is type 2
		if(typeEnemy == 1){
			enemySprite = Sprite(Enemy_1, 12, 15);
			this->live = 50; //max live of small enemy
			this->velocity = 1;
		}else{	
			enemySprite = Sprite(Enemy_2_Hyper, 8, 19);
			this->live = 250; //max live of big enemy, TODO: change depending on the size of the bullet
			this->velocity = 2;
		}
		this->direction  = direction;
		this->status = alive;
		this->x = x;
		this->y = y;
		this->updatePosition = 0;
}

Enemy::~Enemy (){
	//we'll delete the image of the enemy by putting a black image on top of it
	if(this->velocity == 1){
			ST7735_DrawBitmap(y, x, Black_Enemy_1, 12, 15);
		}else{	
			ST7735_DrawBitmap(y, x, Black_Enemy_2_Hyper, 8, 19);
		}
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
int Enemy::getX(){
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
void Enemy::Draw(uint8_t hyper, direction_t playerShipDirection, List<Bullet> *BulletList){ 
	if(checkCollision(BulletList)){
		this->live -=50; //reducing the enemy live points
		if(this->getLive() == 0){
			status = dead;
			return;
		}
	} 
	enemySprite.Draw(x, y);
	if(direction == left){
		//updating enemy position to the left - this reduces the overall speed of both enemies as they move to the left and up and down as well, if the number is bigger in the condition
		if(updatePosition == 3){
			if(playerShipDirection == right){
				UpdatePos(getX() - this->velocity - 2*hyper, getY()  + randomUpDownFn());
			}else{
				UpdatePos(getX() - this->velocity + 3*hyper, getY()  + randomUpDownFn());
			}
			updatePosition = 0;
		}
	}else{
		//updating enemy position to the right - this reduces the overall speed of both enemies as they move to the right and up and down as well, if the number is bigger in the condition
		if(updatePosition == 3){
			if(playerShipDirection == right){
				UpdatePos(getX() + this->velocity - 3*hyper, getY()  + randomUpDownFn());
			}else{
				UpdatePos(getX() + this->velocity + 2*hyper, getY()  + randomUpDownFn());
			}
			updatePosition = 0;
		}
	}
	
	//Checking if we are outside the screen either in the left or right side meaning the status changes to dead alien (for now) 
	if(x < -10 || x > SCREENWIDTH + 15){
    status = dead;
  }
	updatePosition++;
}

void Enemy::UpdatePos(int new_x, uint16_t new_y){
		x = new_x;
		y = new_y;
}

bool Enemy::checkCollision(List<Bullet> *BulletList){
	Node<Bullet>* current = (*BulletList).head;
  while(current != NULL){
		if(this->velocity == 1){ //if enemy is of type 1, which we can get from its velocity
			//if a bullet collisions with the enemy we return true
			if(( /*checking x coordinates*/(((current->data->Getx()) > (x-10)) && ((current->data->Getx()) < x)) ) 
					/*checking y coordinates*/ && ( ( ((current->data->Gety()) < (y+8)) && ((current->data->Gety()) > y) ) )  )  {
				return true;
			}
		}else{
			//if a bullet collisions with the enemy we return true
			if(( /*checking x coordinates*/(((current->data->Getx()) > (x-12)) && ((current->data->Getx()) < x)) ) 
					/*checking y coordinates*/ && ( ( ((current->data->Gety()) < (y+6)) && ((current->data->Gety()) > y) ) )  )  {
				return true;
			}
		}
		//going to next bullet
    current = current->next;
	}
	//if we have gone through the whole linked list of bullets and none touched the enemy, then we're good
	return false;
}

uint8_t Enemy::getVelocity(){
	return this->velocity;
}


