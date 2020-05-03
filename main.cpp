// main.cpp
// Runs on LM4F120/TM4C123
// Jonathan Valvano and Daniel Valvano
// This is a starter project for the EE319K Lab 10 in C++

// Last Modified: 1/17/2020 
// http://www.spaceinvaders.de/
// sounds at http://www.classicgaming.cc/classics/spaceinvaders/sounds.php
// http://www.classicgaming.cc/classics/spaceinvaders/playguide.php
/* This example accompanies the books
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2017

   "Embedded Systems: Introduction to Arm Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2017

 Copyright 2018 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
// ******* Possible Hardware I/O connections*******************
// Slide pot pin 1 connected to ground
// Slide pot pin 2 connected to PD2/AIN5
// Slide pot pin 3 connected to +3.3V 
// fire button connected to PE0
// special weapon fire button connected to PE1
// 8*R resistor DAC bit 0 on PB0 (least significant bit)
// 4*R resistor DAC bit 1 on PB1
// 2*R resistor DAC bit 2 on PB2
// 1*R resistor DAC bit 3 on PB3 (most significant bit)
// LED on PB4
// LED on PB5

// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO), high for data, low for command
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground

 
#include <stdint.h>
#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"
#include "PLL.h"
#include "Print.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "SlidePot.h"
#include "Images.h"
#include "UART.h"
#include "Timer0.h"
#include "Timer1.h"
#include "PlayerShip.h"
#include "Buttons.h"
#include "Bullet.h"
#include "List.h"
#include "Terrain.h"
#include "HelperFns.h"
#include "Enemy.h"

extern "C" void DisableInterrupts(void);
extern "C" void EnableInterrupts(void);
extern "C" void SysTick_Handler(void);
extern "C" void GPIOPortE_Handler(void);


#define NULL 0
#define MAXREACHSHIP 70

List<Bullet> BulletList;
List<Enemy> EnemyList;

PlayerShip Player;
SlidePot Joystick(158,16);

uint32_t time = 0;
uint32_t timeEnemies = 0;
uint8_t randomInitFlag = 1;
uint8_t Flag = 1;
uint32_t score = 0;

void addEnemies(){ //spawning rates are determined in this function
	//if score < 100, we'll add 2 enemies
	//NOTE: The +10 added to Random()%MAXREACHSHIP allows the ships to be a little bit above the very bottom of the screen (because the ship doesn't go that down)
	if(score < 100){
			for(int i = EnemyList.getLength(); i < RandomN(2); i++){ //adding only the enemies necessary to get to 2
				Enemy *enemy = new Enemy(SCREENWIDTH+ RandomN(10), RandomN(MAXREACHSHIP + 10), 1); //we create a new enemy in a random x location
				EnemyList.push_front(enemy); //we add the enemy to the list
			}
	}
	
	else if(score >= 100 && score < 500){ //we'll add 3 enemies
		for(int i = EnemyList.getLength(); i < RandomN(3); i++){ //adding only the enemies necessary to get to 3
			//TODO: Check this values for x and y are actually correct 
			Enemy *enemy = new Enemy(SCREENWIDTH+ RandomN(10), RandomN(MAXREACHSHIP + 10), 1); //we create a new enemy in a random x location
			EnemyList.push_front(enemy); //we add the enemy to the list
		}
	}
	
	else if(score >= 500 && score < 1000){ //we'll add 5 enemies
		for(int i = EnemyList.getLength(); i < RandomN(5); i++){ //adding only the enemies necessary to get to 5
			//TODO: Check this values for x and y are actually correct 
			Enemy *enemy = new Enemy(SCREENWIDTH+ RandomN(10), RandomN(MAXREACHSHIP + 10), RandomN(2)); //we create a new enemy in a random x location
			EnemyList.push_front(enemy); //we add the enemy to the list
		}
	}
	
	else{ //we'll add 8 enemies 
			if(EnemyList.getLength() == 8){ //if we have 8 enemies already being displayed we don't add more
				return;
			}
			for(int i = EnemyList.getLength(); i < RandomN(8); i++){ //adding only the enemies necessary to get to 8
			//TODO: Check this values for x and y are actually correct 
			Enemy *enemy = new Enemy(SCREENWIDTH+ RandomN(10), RandomN(MAXREACHSHIP + 10), RandomN(2)); //we create a new enemy in a random x location
			EnemyList.push_front(enemy); //we add the enemy to the list
		}
	}
}

void clock(void){
  time++;
	timeEnemies++;
	toggle_Heartbeat();
	//every 3 seconds we add enemies depending on the current score of the user
	//TODO: change the spawning rate, decreasing the seconds if scores increments more
	if(timeEnemies == 3){
		addEnemies();
		timeEnemies = 0;
	}
}



void GPIOPortE_Handler(void){
	//initializing random number class with seed as the current systick value when the user presses a button for the first time
	if(randomInitFlag){
		Random_Init(NVIC_ST_CURRENT_R);
		randomInitFlag = 0;
	}
	
	//polling for FireButton
	if(FireButton()){		
		GPIO_PORTE_ICR_R = 0x1; //Acknowledge flag 0
    Bullet* bullet = new Bullet(Player.Getx(), Player.Gety(), Player.GetDir());
		BulletList.push_front(bullet);
		
		//checking random number generator
		//ST7735_SetCursor(0,200);
		//LCD_OutDec1(Random());
	}
	//polling for HyperButton
	if(HyperButton()){		
		GPIO_PORTE_ICR_R = 0x2; //Acknowledge flag 1
    Player.ToggleHyper();
	}
	//polling for DirButton
	if(DirButton()){
		GPIO_PORTE_ICR_R = 0x4; //Acknowledge flag 2
		Player.ToggleDirection();
	}
}

void DrawBullets(){
  Node<Bullet>* current = BulletList.head;
  while(current != NULL){
    current->data->Draw();
    if(current->data->GetStatus() == dead){
      current = BulletList.remove(current);
    }else{
      current = current->next;
    }
  }
}

void DrawEnemies(){
	//draw enemies that are currently in the enemyList 
	Node<Enemy> *current = EnemyList.head;
	while(current != NULL){
			current->data->Draw(Player.GetHyper()); //we sent true or false to the function to know if we increase or not the velocity
		if(current->data->getStatus() == dead){
			score+=50;
			current = EnemyList.remove(current);
			//checking random number generator
			ST7735_SetCursor(0,0);
			LCD_OutDec1(score);
		}else{
			current = current->next;
		}
	}
}

void background(void){
  Flag = 1;
  
  UpdateTerrainIndex(Player.GetDir(), Player.GetHyper());
  
  Joystick.Save(ADC_In());
  Player.UpdatePos(Player.Getx(), Joystick.GetY_Val());
}

void wait(uint32_t sec){
  uint32_t i = time;
  while((time - i) < sec){}
}

int main(void){
  PLL_Init(Bus80MHz);       // Bus clock is 80 MHz 
  ADC_Init();
	Buttons_Init();
	EnableInterrupts();
	SysTick_Init();
  Output_Init();
	Heartbeat_Init();
  Timer1_Init(&clock,80000000); // 1 Hz
  
  

//  ST7735_FillScreen(0x0000);            // set screen to black
//  ST7735_SetTextColor(ST7735_WHITE);
//  ST7735_SetCursor(1, 1);
//  ST7735_OutString((char*)"DEFENDER");
//  ST7735_SetCursor(1, 2);
//  ST7735_SetTextColor(ST7735_WHITE);
//  ST7735_OutString((char*)"By Jaxon & Erick");
//  wait(2);//wait 2 seconds before clearing screen
  ST7735_FillScreen(0x0000);
 
  Timer0_Init(&background,1600000); // 50 Hz
  
	ST7735_SetCursor(0,0);
	LCD_OutDec1(score);
	
  while(1){
    while(Flag == 0){}
    Flag = 0;
    DrawTerrain();
    DrawBullets();
    Player.Draw();
		DrawEnemies();
  }

}




