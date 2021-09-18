#ifndef EVENTENGINE_H
#define EVENTENGINE_H

#include <vector>
#include <functional>

#include "Engine.h"
#include "Container.h"

class EventEngine final 
    : public Engine
    , public Container<EventHandler*>
{
public:
  EventEngine(sf::Window* src);
  ~EventEngine() override;
  
  void push(std::function<void(sf::Event const&)> handler);
  
protected:
  void work(Duration dt) override;
  
private:
  sf::Window* _eventSrc;
};

#endif // EVENTENGINE_H
