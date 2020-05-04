//Provides implementation of playership class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "PlayerShip.h" 
#include "Images.h" 
#include "ST7735.h"

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
  static bool coming_from_hyper = false;
  static int16_t last_x = 0;
  static uint8_t last_y = 0;
  
  if(dir == right){
    if(hyper){
      coming_from_hyper = true;
      last_x = x;
      last_y = y;
      HRsprite.Draw(x + 2, y);
    }else{
      if(coming_from_hyper == true){
        ST7735_FillRect(last_y + 4, last_x - 23, 2, 3, ST7735_BLACK);
        ST7735_DrawPixel(last_y + 3, last_x, ST7735_BLACK);
      }
      Rsprite.Draw(x, y);
      coming_from_hyper = false;
    }
  }else{
    if(hyper){
      coming_from_hyper = true;
      last_x = x;
      last_y = y;
      HLsprite.Draw(x + 5, y);
    }else{
      if(coming_from_hyper == true){
        ST7735_FillRect(last_y + 4, last_x + 1, 2, 3, ST7735_BLACK);
        ST7735_DrawPixel(last_y + 3, last_x - 20, ST7735_BLACK);
      }
      Lsprite.Draw(x, y);
      coming_from_hyper = false;
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



