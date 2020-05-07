//Provides implementation of enemy bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include <stdint.h>
#include "ST7735.h"
#include "Random.h"
#include "EnemyBullet.h"
#include <math.h>
#include "Sound.h"

using namespace std;

#define SCREENWIDTH 160

EnemyBullet::EnemyBullet(int16_t origin_x, uint8_t origin_y, uint16_t inplayer_x, uint8_t inplayer_y){
 //init x and y position local variables based on the position of the enemy
	this->x = origin_x-6;
	this->y = origin_y+2;
	this->last_x = 0;
	this->last_y = 0;
	//init x and y position local variables of the main player
	this->player_x = inplayer_x;
	this->player_y = inplayer_y;
	//determine the slope of the bullet and its direction
	determineSlope(inplayer_x-10, inplayer_y+2);
	//status alive for the linked list to know when to delete the element if it goes out bounds
  status = alive;
	this->collisionPlayer = 0; //no collision with player yet
	this->updatePositionSlow = 0;
}

/*EnemyBullet::~EnemyBullet(){
  if(dir == right){
    ST7735_DrawFastVLine(y, start_x - 10, x - start_x + 10, ST7735_BLACK);
  }else{
    ST7735_DrawFastVLine(y, x, start_x - x + 12, ST7735_BLACK);
  }
}*/

void EnemyBullet::Draw(uint16_t player_x, uint8_t player_y){
	//checking if bullet is out of bounds
	if(this->x > SCREENWIDTH || this->x < 0 || this->y > 70 || this->y < 5){ //if bullet goes out of bound we return and mark it as dead to be able to erase it form the linked list 
		ST7735_DrawPixel(last_y, last_x, ST7735_BLACK); //erasing previous bullet
		status = dead;
		return;
	}
	
	if(checkCollisionPlayer(player_x, player_y)){
			Sound_Killed();
			ST7735_DrawPixel(last_y, last_x, ST7735_BLACK); 
      status = dead;
			collisionPlayer = 1;
      return;
		}
	
	//drawing the pixel/bullet and erasing its previous spot
	ST7735_DrawPixel(y, x, ST7735_WHITE); //drawing new bullet in new position
	ST7735_DrawPixel(last_y, last_x, ST7735_BLACK); //erasing previous bullet
	
	//updating their position twice as slow 
	if(updatePositionSlow == 3){
	//update position by using direction and slope gotten in determineSlope() and send the new x and y to updatePos(x, y)
	if(slope == 0){ //meaning we are going up down left or right
		if(dirEnemyBullet == Left){
			UpdatePos(this->x - 1, this->y);
		}else if(dirEnemyBullet == Right){
			UpdatePos(this->x + 1, this->y);
		}else if(dirEnemyBullet == Up){
			UpdatePos(this->x, this->y + 1);
		}else{
			UpdatePos(this->x, this->y - 1);
		}
	} else if(abs(slope) < 1){ //meaning we are moving with some slope and change in x > change in y because abs(slope) is less than 1
			//so slope will change to represent then how many pixels in x we'll move for each in y
			//we'll divide 1/slope to get the new slope in which is slope = x/y
			//slope = 1/slope; 
			//we'll round the result to get a whole number and that way we'll know how many elements of x we move per y element
			//slope = floor(1/slope);
			if(dirEnemyBullet == DownLeft){ //if the bullet is going down to the left FIRST QUADRANT
				UpdatePos(x - floor(1/slope) , y - 1);
			}else if(dirEnemyBullet == DownRight){ //if the bullet is going down to the right SECOND QUADRANT
				UpdatePos(x + floor(1/slope) , y - 1);
			}else if(dirEnemyBullet == UpRight){ //if the bullet is going up to the right THIRD QUADRANT
				UpdatePos(x + floor(1/slope) , y + 1);
			}else if(dirEnemyBullet == UpLeft){ //if the bullet is going up to the left
				UpdatePos(x - floor(1/slope) , y + 1);
			}
	} else if(abs(slope) >= 1){ //meaning we are moving with some slope and change in y > change in x because abs(slope) >= 1
		//we'll round the result to get a whole number and that way we'll know how many elements of y we move per x element
			slope = floor(slope);
			if(dirEnemyBullet == DownLeft){ //if the bullet is going down to the left FIRST QUADRANT
				UpdatePos(x - 1, y - slope);
			}else if(dirEnemyBullet == DownRight){ //if the bullet is going down to the right SECOND QUADRANT
				UpdatePos(x + 1, y - slope);
			}else if(dirEnemyBullet == UpRight){ //if the bullet is going up to the right THIRD QUADRANT
				UpdatePos(x + 1, y + slope);
			}else if(dirEnemyBullet == UpLeft){ //if the bullet is going up to the left
				UpdatePos(x - 1, y + slope);
			}
	}
	updatePositionSlow = 0;
}
	updatePositionSlow ++;
}

void EnemyBullet::UpdatePos(int16_t new_x, uint16_t new_y){
	this->last_x = this->x;
	this->last_y = this->y;
	this->x = new_x;
  this->y = new_y;
}


int16_t EnemyBullet::Getx(){
  return x;
}

uint8_t EnemyBullet::Gety(){
  return y;
}

status_t EnemyBullet::GetStatus(){
  return status;
}

void EnemyBullet::determineSlope(int16_t player_x, uint8_t player_y){ //determine the direction and slope of the bullet
	//////cases in which the slope is 0 or infinite ///////
	if(this->y == player_y){ //when the enemy bullet has to go right or left because the enemy is positioned exactly at the same y coordinate of the player
		if(this->x > player_x){//if it is going left because the enemy is located on the right of the playership
			dirEnemyBullet = Left;
		}else{//it is going right because the enemy is on the left of the player ship
			dirEnemyBullet = Right;
		}
		slope = 0; //setting slope to 0 because we don't need it this case
	} else if(this->x == player_x){ //when the enemy bullet has to go up or down because the enemy is positioned exactly at the same x coordinate of the player
			if(this->y > player_y){//going down 
				dirEnemyBullet = Down;
			}else{ //going up
				dirEnemyBullet = Up;
			}
		slope = 0; //setting slope to 0 because we don't need it this case
	} 
	
	//////now starting to check in cases in which we'll have an slope /////
	else if(this->x > player_x && this->y > player_y){ ///DOWN LEFT FIRST QUADRANT 
		dirEnemyBullet = DownLeft;
		slope = (this->y - player_y);
		slope = slope / (this->x-player_x); //slope is positive
		slope = abs(slope);
	} else if(this->x < player_x && this->y > player_y){ //DOWN RIGHT SECOND QUADRANT
		dirEnemyBullet = DownRight;
		slope = (player_y - this->y);
		slope = slope / (this->x-player_x); //slope is negative
		slope = abs(slope);
	} else if(this->x < player_x && this->y < player_y){ //UP RIGHT THIRD QUADRANT
		dirEnemyBullet = UpRight;
		slope = (player_y - this->y);
		slope = slope / (this->x-player_x); //slope is positive
		slope = abs(slope);
	} else if(this->x > player_x && this->y < player_y){ //UP LEFT FOURTH QUADRANT
		dirEnemyBullet = UpLeft;
		slope = (player_y - this->y);
		slope = slope / (this->x-player_x);
		//slope = (float)((player_y - this->y)/(this->x-player_x)); //slope is negative
		slope = abs(slope);
	}
}


uint8_t EnemyBullet::checkCollisionPlayer(int16_t player_x, int8_t player_y){
	if( ((player_x - 15 <= this->x ) && (player_x >= this->x)) && ((player_y + 7 >= this->y) && (player_y <= this->y)) ){
		return 1;
	}else{
		return 0;
	}
}

uint8_t EnemyBullet::getCollisionPlayer(){
	return collisionPlayer;
}


