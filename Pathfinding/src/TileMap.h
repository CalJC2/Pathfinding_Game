//
// Created by cj2-cornelius on 15/05/2023.
//

#ifndef WHACKAMOLESFML_TILEMAP_H
#define WHACKAMOLESFML_TILEMAP_H

#include "SFML/Graphics.hpp"

class TileMap
{
 public:
  /*void load(sf::Vector2u tileSize);
  sf::VertexArray vArray;
  sf::Vertex* tile;
  int width = 34;
  int height = 22;*/
  sf::Sprite wallLayer;
  sf::Sprite baseLayer;
  int floorCost;
  int wallCost;

  void MapInit();
  void SetCost(int floorCost, int wallCost);

 private:
  sf::Texture baseLayerTexture;
  sf::Texture wallLayerTexture;

};

#endif // WHACKAMOLESFML_TILEMAP_H
