#include <algorithm>

#include "AnimObject.h"
#include "AnimEngine.h"

AnimEngine::AnimEngine()
{
}

void AnimEngine::work(Duration dt) {
  for (value_type iter = this->begin(); iter != this->end(); ++iter) {
    if (iter->state() == AnimationState::Played)
      iter->update(dt);
  }
}
