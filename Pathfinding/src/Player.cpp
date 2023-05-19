//
// Created by cj2-cornelius on 16/05/2023.
//

#include "Player.h"

Player::Player()
{
  sprite = new sf::Sprite();
}

Player::~Player()
{
  if(sprite != nullptr)
  {
    delete sprite;
    sprite = nullptr;
  }
}

bool Player::initSprite(sf::Texture& texture, std::string filename)
{
  if(!texture.loadFromFile(filename))
  {
    std::cout << "error loading player texture" << std::endl;
    return false;
  }
  sprite->setTexture(texture);
  sprite->setScale(0.5f, 0.5f);
  return true;
}

sf::Sprite* Player::getSprite()
{
  return sprite;
}

int Player::getSpeed() const
{
  return speed;
}

void Player::setSpeed(int speed)
{
  Player::speed = speed;
}

const Vector2& Player::getDirection() const
{
  return direction;
}

void Player::setDirection(const Vector2& direction)
{
  Player::direction = direction;
}
