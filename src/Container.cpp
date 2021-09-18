#include "Container.h"

template<class T>
  void Container<T>::pop(value_type obj) {
    for (int i = 0; i < _objects.size(); ++i) {
      if (_objects[i] == obj) {
        std::lock_guard lock(_mtx);
        std::swap(_objects[i], _objects.back());
        _objects.resize(_objects.size() - 1);
      }
    }
  }
  
template<class T>
  void Container<T>::push(value_type obj) {
    std::lock_guard lock(_mtx);
    _objects.push_back(obj);
  }
  
