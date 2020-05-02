//Provides implementation of playership class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "PlayerShip.h" 
#include "Images.h" 

#define RIGHT_XPOS 32
#define LEFT_XPOS 138

PlayerShip::PlayerShip(){
  Rsprite = Sprite(PlayerShipR, 10, 21);
  Lsprite = Sprite(PlayerShipL, 10, 21);
  HRsprite = Sprite(HyperShipR, 10, 28);
  HLsprite = Sprite(HyperShipL, 10, 28);
  x = RIGHT_XPOS;
  y = 80;
  hyper = false;
  dir = right;

}

void PlayerShip::Draw(){
  if(dir == right){
    if(hyper){
      HRsprite.Draw(x, y);
    }else{
      Rsprite.Draw(x, y);
    }
  }else{
    if(hyper){
      HLsprite.Draw(x, y);
    }else{
      Lsprite.Draw(x, y);
    }
  }
}

//y value is raw ADC value and must be converted
void PlayerShip::UpdatePos(int16_t new_x, uint8_t new_y){
  //Compute new y
  uint8_t old_y = y;
  
  if((new_y - old_y) > 2){
    new_y = old_y + 2;
  }
  else if((old_y - new_y) > 2){
    new_y = old_y - 2;
  }
  
  y = new_y;
  
  //Compute new x
  if(new_x != RIGHT_XPOS && dir == right){
    new_x -= 1;
  }else if(new_x != LEFT_XPOS && dir == left){
    new_x += 1;
  }
  
  x = new_x;
}

int16_t PlayerShip::Getx(){
  return x;
}
  
uint8_t PlayerShip::Gety(){
  return y;
}

void PlayerShip::ToggleDirection(){
  if(dir == right){
    dir = left;
  }else{
    dir = right;
  }
}


direction_t PlayerShip::GetDir(){
  return dir;
}

void PlayerShip::ToggleHyper(){
  uint8_t button_data = (GPIO_PORTE_DATA_R & 0x02) >> 1;
  if(button_data){
    hyper = true;
  }else{
    hyper = false;
  }
}


bool PlayerShip::GetHyper(){
  return hyper;
}



