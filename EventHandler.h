#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Window/Event.hpp>

class EventHandler
{
public:
  virtual ~EventHandler();
  virtual void handle(sf::Event const& ev) = 0;
};

#endif // EVENTHANDLER_H
