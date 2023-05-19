
#ifndef WHACKAMOLESFML_GAME_H
#define WHACKAMOLESFML_GAME_H

#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Player.h"
#include "Vector2.h"


class Game
{
 public:
  Game(sf::RenderWindow& game_window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void mouseMoved(sf::Event event);
  void playerMove(float dt);


 private:
  void turnRight();
  void turnLeft();
  //change state
  void changeState(int newState);
  void GameMenu();
  void GamePlay();
  void WinState();
  void LoseState();

  sf::Text mainText;
  sf::Text playText;
  sf::Text exitText;
  sf::Text helpText;
  sf::Sprite background;
  int gameCondition = 1;
  bool forward = false;
  bool backward = false;

  sf::Font font;
  sf::Texture backgroundTexture;
  sf::Texture playerTexture;
  sf::RenderWindow& window;
  bool playSelected = true;


  // class namespace
  TileMap map;
  Player player;



};

#endif // WHACKAMOLESFML_GAME_H
