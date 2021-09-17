#include "Game.h"
#include "Snake.h"

Game::Game(const std::string& name)
{
  _name = name;
}

const std::string& Game::name() const
{
  return _name;
}

std::unique_ptr<Game> Game::getGameInstance(Games game)
{
  std::unique_ptr<Game> result;
  
  switch (game) {
    case Games::Snake:
      result = std::make_unique<Game>(new Snake());
  }
  
  result->init();
  return result;
}
