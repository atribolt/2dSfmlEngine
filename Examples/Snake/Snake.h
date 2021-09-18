#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "Game.h"
#include "Typedefs.h"

class Snake : public Game
{
public:
  Snake();
  ~Snake() override;
  
  int play() override;
  void init() override;
  
private:
  void stop();
  void start();
  void pause();
  
  void initBaseHandlers();
  
private:
  sf::RenderWindow* _window;
  
  std::vector<Object*> _objects;
  
  AnimEngine* _animEngine   { nullptr };
  EventEngine* _eventEngine { nullptr };
  PaintEngine* _paintEngine { nullptr };
};

#endif // SNAKE_H
