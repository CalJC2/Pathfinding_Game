//
// Created by cj2-cornelius on 16/05/2023.
//

#ifndef WHACKAMOLESFML_PLAYER_H
#define WHACKAMOLESFML_PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Player
{
 public:
  Player();
  ~Player();
  bool initSprite(sf::Texture& texture, std::string filename);
  sf::Sprite* getSprite();
  int getSpeed() const;
  void setSpeed(int speed);
  const Vector2& getDirection() const;
  void setDirection(const Vector2& direction);


 private:
  sf::Sprite* sprite = nullptr;
  int speed = 0;
  Vector2 direction = {0,0};


};

#endif // WHACKAMOLESFML_PLAYER_H
