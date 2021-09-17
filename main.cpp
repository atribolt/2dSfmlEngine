#include "Game.h"

int main()
{ 
  std::unique_ptr<Game> game = Game::getGameInstance(Games::Snake);
  return game->play();
}
