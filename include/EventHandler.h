#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Window/Event.hpp>

class EventHandler
{
public:
  EventHandler(bool autoDelete = false);
  
  bool autoDelete() const;
  void autoDelete(bool needDel);
  
  virtual ~EventHandler();
  virtual void handle(sf::Event const& ev) = 0;
  
private:
  bool _needAutoDelete;
};

#endif // EVENTHANDLER_H
