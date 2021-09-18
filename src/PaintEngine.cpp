#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "PaintEngine.h"

PaintEngine::PaintEngine(sf::RenderWindow* window)
  : Engine()
  , _target(window)
{
}

void PaintEngine::setRenderState(sf::RenderStates s) {
  _state = s;
}

void PaintEngine::work(Duration dt)
{
  for (value_type iter = this->begin(); iter != this->end(); ++iter) {
    _target->draw(*iter, _state);
  }
  _target->display();
  _target->clear();
}
