#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "Game.h"
#include "AnimEngine.h"
#include "PaintEngine.h"
#include "EventEngine.h"

class Object;

class Snake : public Game
{
public:
  Snake();
  ~Snake() override;
  
  int play() override;
  void init() override;
  
private:
  std::vector<Object*> _objects;
  
  AnimEngine _animEngine;
  EventEngine _eventEngine;
  PaintEngine _paintEngine;
};

#endif // SNAKE_H
