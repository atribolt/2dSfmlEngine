#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>

#include "Common.h"

class Game
{
public:
  Game(std::string const& name);
  const std::string& name() const;
  
  virtual ~Game() = 0;
  virtual int play() = 0;
  
  static std::unique_ptr<Game> getGameInstance(Games game);
  
protected:
  virtual void init() = 0;
  
private:
  
  std::string _name;
};

#endif // GAME_H
