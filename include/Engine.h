#ifndef ENGINE_H
#define ENGINE_H

#include "Typedefs.h"

class Engine
{
public:
  Engine();
  virtual ~Engine();
  
  void stop();
  void start();
  
  int framerate() const;
  void framerate(int fps);
  
  bool isStoped() const;
  
protected:
  virtual void work(Duration dt) = 0;
  
private:
  int _fps;
  bool _stop;
};

#endif // ENGINE_H
