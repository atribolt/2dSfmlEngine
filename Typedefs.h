#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <chrono>

using Clock = std::chrono::system_clock;
using Duration = Clock::duration;

namespace sf {
  class Window;
  class Event;
  class Drawable;
  class RenderWindow;
}

class AnimObject;
class EventHandler;

#endif // TYPEDEFS_H
