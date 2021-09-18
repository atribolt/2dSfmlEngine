#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

#include "EventEngine.h"
#include "EventHandler.h"

EventEngine::EventEngine(sf::Window* window)
  : _eventSrc(window)
{
}

EventEngine::~EventEngine() {
  for (value_type iter = this->begin(); iter != this->end(); ++iter) {
    if (iter->autoDelete())
      delete iter;
  }
}

void EventEngine::push(std::function<void (const sf::Event&)> handler) {
  class Handler final : public EventHandler {
  public:
    Handler(std::function<void (const sf::Event&)> handler)
      : EventHandler(true)
      , _handler(handler) {}
    
    void handle(sf::Event const& ev) override {
      _handler(ev);
    }
    
  private:
    std::function<void (const sf::Event&)> _handler;
  };
  
  Container::push(new Handler(handler));
}

void EventEngine::work(Duration) {
  sf::Event ev;
  while(_eventSrc->pollEvent(ev)) {
    for (value_type iter = this->begin(); iter != this->end(); ++iter) {
      iter->handle(ev);
    }
  }
}
