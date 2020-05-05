//Provides implementation of enemy class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/01/2020

#include "Enemy.h"
#include <stdint.h>
#include "Images.h"
#include "Random.h"
#include "ST7735.h"
#include "Terrain.h"
#include "Sound.h"
#include "HelperFns.h"//ONLY FOR DEBUG PURPOSES

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
			this->live = 200; //max live of big enemy, TODO: change depending on the size of the bullet
			this->velocity = 2;
		}
		this->direction  = direction;
		this->status = alive;
    UpdatePos(x, y);
    last_mapx = 0;
    last_mapy = 0;
		this->updatePosition = 0;
}

Enemy::~Enemy (){
	//we'll delete the image of the enemy by putting a black image on top of it
	if(this->velocity == 1){
			ST7735_DrawBitmap(y, x, Black_Enemy_1, 12, 15);
  }else{
    ST7735_DrawBitmap(y, x, Black_Enemy_2_Hyper, 8, 19);
  }
  ST7735_DrawPixel(97 + last_mapy, 40 + last_mapx, ST7735_BLACK);
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

void Enemy::DrawMap(){
  int xpos = Abs_x/8 - (TerrainIndex/8) + 30;
  if(xpos < 0){
    xpos += MAPSIZE;
  }else if(xpos >= MAPSIZE){
    xpos -= MAPSIZE;
  }
  uint8_t ypos = y/2 - 10;

  ST7735_DrawPixel(97 + last_mapy, 40 + last_mapx, ST7735_BLACK);
  ST7735_DrawPixel(97 + ypos, 40 + xpos, ST7735_GREEN);

  last_mapx = xpos;
  last_mapy = ypos;
}


void Enemy::Draw(uint8_t hyper, direction_t playerShipDirection, List<Bullet> *BulletList){
  if(updatePosition == 3){
    if(direction == left){
      UpdatePos(Abs_x - this->velocity, getY()  + randomUpDownFn());
    }else{
      UpdatePos(Abs_x + this->velocity, getY()  + randomUpDownFn());
    }
    updatePosition = 0;
  }else{
    UpdatePos(Abs_x, getY()  + randomUpDownFn());
  }

	updatePosition++;

  if(x >= 0){
    if(checkCollision(BulletList)){
      this->live -=50; //reducing the enemy live points
      if(this->getLive() == 0){
        status = dead;
        return;
      }
    }
  }
  enemySprite.Draw(x, y);
  DrawMap();
}

void Enemy::UpdatePos(int new_x, uint16_t new_y){
		Abs_x = new_x;
    if(Abs_x < 0){
      Abs_x += TERRAINSIZE;
    }else if(Abs_x >= TERRAINSIZE){
      Abs_x -= TERRAINSIZE;
    }
    int temp_Abs_x = Abs_x;
    if((TerrainIndex + SCREENWIDTH) >= TERRAINSIZE && temp_Abs_x < SCREENWIDTH){
      temp_Abs_x += TERRAINSIZE;
    }
    
    //=============DEBUG PURPOSE ONLY
//    ST7735_SetRotation(1);
//    ST7735_SetCursor(1, 2);
//    LCD_OutDec1(TerrainIndex);
//    
//    ST7735_SetCursor(1, 3); 
//    LCD_OutDec1(temp_Abs_x);
//    ST7735_SetRotation(0);
    //=============DEBUG PURPOSE ONLY
    
    
    if(temp_Abs_x >= TerrainIndex && temp_Abs_x < (TerrainIndex + SCREENWIDTH)){
      this->x = temp_Abs_x - TerrainIndex;
    }else{
      this->x = -10;
    }
		y = new_y;
}

bool Enemy::checkCollision(List<Bullet> *BulletList){
	Node<Bullet>* current = (*BulletList).head;
  while(current != NULL){
		if(this->velocity == 1){ //if enemy is of type 1, which we can get from its velocity
			//if a bullet collisions with the enemy we return true
			if(( /*checking x coordinates*/(((current->data->Getx()) > (x-10)) && ((current->data->Getx()) < x)) )
					/*checking y coordinates*/ && ( ( ((current->data->Gety()) < (y+10)) && ((current->data->Gety()) > y) ) )  )  {
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
