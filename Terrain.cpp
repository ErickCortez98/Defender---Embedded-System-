//Provides implementation of terrain
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/30/2020


#include "Terrain.h"

#define TERRAINSPEED 2

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
  
  if(hyper){
    if(dir == right){
      TerrainIndex += TERRAINSPEED;
    }else if(dir == left && TerrainIndex < TERRAINSPEED){
      TerrainIndex = (TERRAINSIZE + TerrainIndex) - TERRAINSPEED;
    }else{
      TerrainIndex -= TERRAINSPEED;
    }
    
    if(TerrainIndex >= TERRAINSIZE){
      TerrainIndex -= TERRAINSIZE;
    }
  }
}

