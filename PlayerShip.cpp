//Provides implementation of playership class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "PlayerShip.h" 

void PlayerShip::Draw(){
  sprite.Draw();
}

//y value is raw ADC value and must be converted
void PlayerShip::UpdatePos(uint16_t x, uint16_t y){
  uint16_t old_y = sprite.Gety();
  uint16_t new_y = 16 + (y >> 5);
  
  if((new_y - old_y) > 2){
    new_y = old_y + 2;
  }
  else if((old_y - new_y) > 2){
    new_y = old_y - 2;
  }
  
  sprite.UpdatePos(x, new_y);
}


