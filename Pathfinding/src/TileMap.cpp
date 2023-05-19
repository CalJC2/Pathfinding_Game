//
// Created by cj2-cornelius on 15/05/2023.
//
#include <iostream>
#include "TileMap.h"

void TileMap::MapInit()
{
  if(!baseLayerTexture.loadFromFile("Data/Images/Background/BaseMap.png"))
  {
    std::cout << "base layer texture did not load" << std::endl;
  }

  if(!wallLayerTexture.loadFromFile("Data/Images/Background/Walls.png"))
  {
    std::cout << "Walls texture did not load" << std::endl;
  }

  baseLayer.setTexture(baseLayerTexture);
  wallLayer.setTexture(wallLayerTexture);
  baseLayer.setScale(1.5,1.5);
  wallLayer.setScale(1.5,1.5);
}

void TileMap::SetCost(int cost_1, int cost_2)
{
  floorCost = cost_1;
  wallCost = cost_2;
}