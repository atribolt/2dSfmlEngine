#ifndef ANIMENGINE_H
#define ANIMENGINE_H

#include <mutex>
#include <vector>
#include <chrono>

#include "Engine.h"
#include "Container.h"

class AnimEngine final 
    : public Engine
    , public Container<AnimObject*>
{
public:
  AnimEngine();
  ~AnimEngine() override;
  
protected:
  void work(Duration dt) override;
};

#endif // ANIMENGINE_H
