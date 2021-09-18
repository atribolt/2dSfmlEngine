#include <thread>
#include "Engine.h"

Engine::Engine() {
  stop();
  framerate(60);
}

Engine::~Engine() {
  
}

void Engine::stop() {
  _stop = true;
}

void Engine::start() {
  _stop = false;
  
  auto last_time = Clock::now();
  
  do {
    work(Clock::now() - last_time);
    last_time = Clock::now();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / _fps));
  } while(!_stop);
}

bool Engine::isStoped() const {
  return _stop;
}

int Engine::framerate() const {
  return _fps;
}

void Engine::framerate(int fps) {
  _fps = fps;
}
