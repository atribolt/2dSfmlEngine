#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

#include "EventEngine.h"
#include "EventHandler.h"

EventEngine::EventEngine(sf::Window* window)
  : _eventSrc(window)
{
}

void EventEngine::work(Duration)
{
  sf::Event ev;
  while(_eventSrc->pollEvent(ev)) {
    for (value_type iter = this->begin(); iter != this->end(); ++iter) {
      iter->handle(ev);
    }
  }
}
