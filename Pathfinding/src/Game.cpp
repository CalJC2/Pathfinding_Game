#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{


}
//------------------------------------------------------------------------------
bool Game::init()
{

  if(!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load" << std::endl;
  }

  if(!backgroundTexture.loadFromFile("Data/Images/OldWhackAMoleStuff/background.png"))
  {
    std::cout << "background texture did not load" << std::endl;
  }

  map.MapInit();
  map.SetCost(1,50);

  //player information
  player.initSprite(playerTexture, "Data/Images/Player/tankBlue.png");
  player.getSprite()->setPosition(window.getSize().x /2 - player.getSprite()->getGlobalBounds().width/2,
                                  window.getSize().y /2 - player.getSprite()->getGlobalBounds().height/2);
  player.getSprite()->setOrigin(player.getSprite()->getGlobalBounds().width,
                                player.getSprite()->getGlobalBounds().height);
  player.setDirection(Vector2(0.0f, -1.0f));
  player.setSpeed(50);

  background.setTexture(backgroundTexture);

  //state information
  mainText.setFont(font);
  playText.setFont(font);
  exitText.setFont(font);
  helpText.setFont(font);

  mainText.setCharacterSize(50);
  playText.setCharacterSize(30);
  exitText.setCharacterSize(30);
  helpText.setCharacterSize(30);

  mainText.setPosition(window.getSize().x / 2.45,
                       window.getSize().y /4.25);
  playText.setPosition(window.getSize().x / 2.2,
                       window.getSize().y /2.75);
  exitText.setPosition(window.getSize().x / 2.2,
                       window.getSize().y /2);


  return true;
}
//------------------------------------------------------------------------------
void Game::update(float dt)
{
  playerMove(dt);
  changeState(gameCondition);
}
//------------------------------------------------------------------------------
void Game::render()
{
  if(gameCondition == 2)
  {
    window.draw(map.baseLayer);
    window.draw(map.wallLayer);
    window.draw(*player.getSprite());
  }
  else
  {
    window.draw(background);
    window.draw(mainText);
    window.draw(playText);
    window.draw(exitText);

  }

}
//------------------------------------------------------------------------------
void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  // check if in bounds of bird Sprite
}
//------------------------------------------------------------------------------
void Game::keyPressed(sf::Event event)
{
 if(gameCondition == 2)
 {
   if (event.key.code == sf::Keyboard::A)
   {

     player.getSprite()->rotate(-4.5);
     turnLeft();
     std::cout<< player.getDirection().x << std::endl;
     std::cout<< player.getDirection().y << std::endl;
     std::cout<< "----------" << std::endl;

   }
   if (event.key.code == sf::Keyboard::D)
   {

     player.getSprite()->rotate(4.5);
     turnRight();
     std::cout<< player.getDirection().x << std::endl;
     std::cout<< player.getDirection().y << std::endl;
     std::cout<< "----------" << std::endl;
   }
   if(event.key.code == sf::Keyboard::W)
   {
     forward = true;
     std::cout<< player.getDirection().x << std::endl;
     std::cout<< player.getDirection().y << std::endl;
     std::cout<< "----------" << std::endl;
   }
   if (event.key.code == sf::Keyboard::S)
   {
     backward = true;
   }
 }
 else
 {
   if ((event.key.code == sf::Keyboard::W) || (event.key.code == sf::Keyboard::S))
   {
     playSelected = !playSelected;
   }

   if(event.key.code == sf::Keyboard::Enter)
   {
     if(!playSelected)
     {
       window.close();
     }
     else
     {
       gameCondition = 2;
     }
   }
 }

}
//------------------------------------------------------------------------------
void Game::keyReleased(sf::Event event)
{
  if(event.key.code == sf::Keyboard::W)
  {
    forward = false;
  }
  if (event.key.code == sf::Keyboard::S)
  {
    backward = false;
  }

}
//------------------------------------------------------------------------------
void Game::mouseMoved(sf::Event event)
{

}
//------------------------------------------------------------------------------
void Game::playerMove(float dt)
{
  if ((player.getSprite()->getPosition().x > 0 && player.getSprite()->getPosition().x < window.getSize().x) &&
      (player.getSprite()->getPosition().y > 0 && player.getSprite()->getPosition().y <window.getSize().y))
  {
    if (forward)
    {
      player.getSprite()->move(player.getSpeed() * player.getDirection().x * dt, player.getSpeed() * player.getDirection().y * dt);
    }
    if(backward)
    {
      player.getSprite()->move(-player.getSpeed() * player.getDirection().x * dt, -player.getSpeed() * player.getDirection().y * dt);
    }
  }
}
//------------------------------------------------------------------------------
void Game::turnLeft()
{
  if(player.getDirection().x <= -1)
  {
    player.setDirection(Vector2(-1 , player.getDirection().y + 0.1));
  }

  if(player.getDirection().y >= 1)
  {
    player.setDirection(Vector2(player.getDirection().x + 0.1, 1));
  }

  if(player.getDirection().x >= 1)
  {
    player.setDirection(Vector2(1 , player.getDirection().y - 0.1));
  }

  if(player.getDirection().y <= -1)
  {
    player.setDirection(Vector2(player.getDirection().x - 0.1, -1));
  }
}
//------------------------------------------------------------------------------
void Game::turnRight()
{
  // when you reach the outer corners of the rotation box
  //rotate the vectors to face the same direction as the sprite
  //top of box
  if(player.getDirection().x >= 1)
  {
    player.setDirection(Vector2(1 , player.getDirection().y + 0.1));
  }

  if(player.getDirection().y >= 1)
  {
    player.setDirection(Vector2(player.getDirection().x - 0.1, 1));
  }

  if(player.getDirection().x <= -1)
  {
    player.setDirection(Vector2(-1 , player.getDirection().y - 0.1));
  }

  if(player.getDirection().y <= -1)
  {
    player.setDirection(Vector2(player.getDirection().x + 0.1, -1));
  }

}

//------------------------------------------------------------------------------
void Game::changeState(int newState)
{
  switch (newState)
  {
    case 1:
      GameMenu();
      break;
    case 2:
      GamePlay();
      break;
    case 3:
      WinState();
      break;
    case 4:
      LoseState();
      break;
    default:
      std::cout << "could not change state" << std::endl;

  }
}
//------------------------------------------------------------------------------
void Game::GameMenu()
{
  gameCondition = 1;
  mainText.setString("TANKS!");
  playText.setString(">PLAY<");
  exitText.setString("exit");

  mainText.setFillColor(sf::Color::Green);
  playText.setFillColor(sf::Color::Black);
  exitText.setFillColor(sf::Color::Black);

  if(playSelected)
  {
    playText.setString(">PLAY<");
    exitText.setString("exit");
  }
  else
  {
    playText.setString("play");
    exitText.setString(">EXIT<");
  }
}
//------------------------------------------------------------------------------
void Game::GamePlay()
{
  gameCondition = 2;
}
//------------------------------------------------------------------------------
void Game::WinState()
{
  gameCondition = 3;

  mainText.setString("YOU WIN! Play again?");
  playText.setString(">PLAY<");
  exitText.setString("exit");

  mainText.setFillColor(sf::Color::Green);
  playText.setFillColor(sf::Color::Black);
  exitText.setFillColor(sf::Color::Black);

}
//------------------------------------------------------------------------------
void Game::LoseState()
{
  gameCondition = 4;

  mainText.setString("YOU LOSE! Play again?");
  playText.setString(">PLAY<");
  exitText.setString("exit");

  mainText.setFillColor(sf::Color::Green);
  playText.setFillColor(sf::Color::Black);
  exitText.setFillColor(sf::Color::Black);
}
//------------------------------------------------------------------------------
