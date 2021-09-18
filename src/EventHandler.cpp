#include "EventHandler.h"

EventHandler::EventHandler(bool autoDelete) {
  this->autoDelete(autoDelete);
}

bool EventHandler::autoDelete() const {
  return _needAutoDelete;
}

void EventHandler::autoDelete(bool needDel) {
  _needAutoDelete = needDel;
}

EventHandler::~EventHandler() {
  
}
