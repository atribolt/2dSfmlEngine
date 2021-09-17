#ifndef ANIMOBJECT_H
#define ANIMOBJECT_H

#include "Common.h"
#include "Typedefs.h"

class AnimObject
{
public:
  AnimObject();
  virtual ~AnimObject();
  
public:
  AnimationState state() const;
  
  void stop();
  void play();
  void pause();
  
public:
  virtual void update(Duration const& dt) = 0;
  
private:
  void setState(AnimationState state);
  
private:
  AnimationState _state;
};

#endif // ANIMOBJECT_H
