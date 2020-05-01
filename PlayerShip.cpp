//Provides implementation of playership class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "PlayerShip.h" 
#include "Images.h" 

PlayerShip::PlayerShip(){
  //initial x and y position, followed by sprite image information
  sprite = Sprite(32, 80, PlayerShipIm, 10, 21);
  hyper = false;
	
	//TO TEST DIFFERENT SPRITES
	//sprite = Sprite(32, 80, HyperSpeed_Ship, 10, 28); //- HYPERSPEED SHIP SPRITE
	//sprite = Sprite(32, 80, Enemy_1, 12, 13); //- Enemy 1
	//sprite = Sprite(32, 80, Enemy_2, 8, 15); //- Enemy 2
}

void PlayerShip::Draw(){
  sprite.Draw();
}

//y value is raw ADC value and must be converted
void PlayerShip::UpdatePos(uint8_t x, uint8_t y){
  uint8_t old_y = sprite.Gety();
  uint8_t new_y = y;
  
  if((new_y - old_y) > 2){
    new_y = old_y + 2;
  }
  else if((old_y - new_y) > 2){
    new_y = old_y - 2;
  }
  
  sprite.UpdatePos(x, new_y);
}

uint8_t PlayerShip::Getx(){
  return sprite.Getx();
}
  
uint8_t PlayerShip::Gety(){
  return sprite.Gety();
}



