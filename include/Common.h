#ifndef COMMON_H
#define COMMON_H

#include <algorithm>
#include <type_traits>

#ifdef __cpp_lib_endian
#  include <bit>
  using std::endian;
#else
  enum class endian
  {
  #ifdef _WIN32
    little = 0,
    big    = 1,
    native = little
  #else
    little = __ORDER_LITTLE_ENDIAN__,
    big    = __ORDER_BIG_ENDIAN__,
    native = __BYTE_ORDER__
  #endif
  };
#endif

template<class Data>
  Data& invert_bytes(Data& data) {
    char* begin = (char*)(&data);
    char* end = begin + sizeof(Data);
    std::reverse(begin, end);
    return data;
  }
  
template<class Data>
  Data& normalize(Data& data) {
    if constexpr (endian::native != endian::little) {
      invert_bytes(data);
    }
    return data;
  }
  
enum ASCII : char {
  NUL = 0x0,
  STX = 0x2,
  ETX = 0x3
};
  
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

template<class T, class Func>
  struct LocalObject : public T {
    template<class ...Args>
      LocalObject(T&& t, Func onDestroy) 
        : T(t)
      {
        this->onDestroy = onDestroy;
      }
      
    ~LocalObject() override {
      if constexpr (std::is_member_function_pointer_v<Func>) {
        ((*this).*onDestroy)();
      }
      else
        onDestroy();
    }
    
    Func onDestroy;
  };

#endif // COMMON_H
