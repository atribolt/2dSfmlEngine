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

class Object;
class AnimObject;
class EventHandler;

class AnimEngine;
class EventEngine;
class PaintEngine;

#endif // TYPEDEFS_H
