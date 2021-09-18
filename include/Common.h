#ifndef COMMON_H
#define COMMON_H

enum class EntityTypes {
  Enemy,
  Player
};

enum class AnimationAction {
  Play,
  Stop,
  Pause
};

enum class AnimationState {
  Played,
  Paused,
  Stoped
};

enum class Games {
  Snake
};

#endif // COMMON_H
