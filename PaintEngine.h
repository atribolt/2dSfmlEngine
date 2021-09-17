#ifndef PAINTENGINE_H
#define PAINTENGINE_H

#include <SFML/Graphics/RenderStates.hpp>

#include "Engine.h"
#include "Container.h"

class PaintEngine final 
    : public Engine
    , public Container<sf::Drawable*>
{
public:
  PaintEngine(sf::RenderWindow* canvas);
  ~PaintEngine() override;
  
  void setRenderState(sf::RenderStates s);
  
protected:
  void work(Duration dt) override;
  
private:
  sf::RenderStates _state;
  sf::RenderWindow* _target;
};

#endif // PAINTENGINE_H
