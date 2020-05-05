//Provides implementation of terrain
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/30/2020


#include "Terrain.h"

#define TERRAINSPEEDMAX 64

int16_t TerrainIndex = 0;

void DrawTerrain(){
  for(int i = 0; i < SCREENWIDTH; i++){
    
    int index = TerrainIndex + i;
    int last_index = LastTerrainIndex + i;
    
    if(index >= TERRAINSIZE){
      index -= TERRAINSIZE;
    }
    if(last_index >= TERRAINSIZE){
      last_index -= TERRAINSIZE;
    }
    
    ST7735_DrawPixel(TerrainData[last_index], i, ST7735_BLACK);//clear the last drawn terrain
    ST7735_DrawPixel(TerrainData[index], i, ST7735_YELLOW);
  }
}

void UpdateTerrainIndex(direction_t dir, bool hyper){
  LastTerrainIndex = TerrainIndex;
  static int8_t velocity = 0;
  int8_t vel = velocity/8;
  if(vel || hyper){
    TerrainIndex += vel;
    
    if(TerrainIndex >= TERRAINSIZE){
      TerrainIndex -= TERRAINSIZE;
    }else if(TerrainIndex < 0){
      TerrainIndex += TERRAINSIZE;
    }
    
    
    if(!hyper && velocity != 0){
      if(velocity < 0){
        velocity += 1;
      }else if(velocity > 0){
        velocity -= 1;
      }
    }else if(velocity < TERRAINSPEEDMAX && dir == right){
      velocity += 1;
    }else if(velocity > -TERRAINSPEEDMAX && dir == left){
      velocity -= 1;
    }
    
  }
}

//Map is 32x80 pixels in top middle of screen
void DrawMap(){
  for(int i = 0; i < MAPSIZE; i++){
    int last_index = i - 30 + (LastTerrainIndex >> 3);
    int index = i - 30 + (TerrainIndex >> 3);
    
    
    if(last_index < 0){
      last_index += MAPSIZE;
    }else if(last_index >= MAPSIZE){
      last_index -= MAPSIZE;
    }
    
    if(index < 0){
      index += MAPSIZE;
    }else if(index >= MAPSIZE){
      index -= MAPSIZE;
    }
    
    ST7735_DrawPixel(97 + TerrainMapData[last_index], 40 + i, ST7735_BLACK);
    ST7735_DrawPixel(97 + TerrainMapData[index], 40 + i, ST7735_YELLOW);
  }
}

void DrawUI(){
  ST7735_SetRotation(1);
	ST7735_SetCursor(21, 1);
	ST7735_OutString((char*)"Lives");
	ST7735_SetRotation(0);
  ST7735_DrawFastHLine(95, 39, 33, ST7735_GREEN);
  ST7735_DrawFastHLine(95, 121, 33, ST7735_GREEN);
  ST7735_DrawFastVLine(95, 0, 160, ST7735_GREEN);
  ST7735_DrawFastVLine(127, 70, 20, ST7735_WHITE);
  ST7735_DrawFastVLine(95, 70, 20, ST7735_WHITE);
  ST7735_DrawPixel(96, 70, ST7735_WHITE);
  ST7735_DrawPixel(96, 89, ST7735_WHITE);
  ST7735_DrawPixel(126, 70, ST7735_WHITE);
  ST7735_DrawPixel(126, 89, ST7735_WHITE);
}

