#include <future>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Snake.h"
#include "AnimEngine.h"
#include "PaintEngine.h"
#include "EventEngine.h"

Snake::Snake()
  : Game("Snake")
{
}

Snake::~Snake() {
  this->stop();
  
  delete _eventEngine;
  delete _animEngine;
  delete _paintEngine;
  delete _window;
  
  _eventEngine = nullptr;
  _animEngine = nullptr;
  _paintEngine = nullptr;
  _window = nullptr;
}

int Snake::play() {
  this->start();
  return 0;
}

void Snake::init() {
  _window = new (std::nothrow) sf::RenderWindow();
  _window->setVisible(false);
  _window->setFramerateLimit(60);
  
  _window->create({}, "Snake");
  
  _animEngine = new (std::nothrow) AnimEngine();
  _eventEngine = new (std::nothrow) EventEngine(_window);
  _paintEngine = new (std::nothrow) PaintEngine(_window);
  
  // TODO: need init game objects and handlers
}

void Snake::stop() {
  _window->setVisible(false);
  
  _eventEngine->stop();
  _animEngine->stop();
  _paintEngine->stop();
  
  auto wait = std::async(
    [](EventEngine* ee, AnimEngine* ae, PaintEngine* pe) {
      while(!ee->isStoped() || !ae->isStoped() || !pe->isStoped());
    }, _eventEngine, _animEngine, _paintEngine
  );
  
  wait.wait();
}

void Snake::start() {
  _animEngine->start();
  _paintEngine->start();
  _eventEngine->start();
  
  _window->setVisible(true);
}

void Snake::pause() {
  // TODO: may be realized later
}

void Snake::initBaseHandlers() {
  _eventEngine->push([this] (sf::Event const& ev) {
    if (ev.type == sf::Event::Closed) {
      this->stop();
    }
  });
}
