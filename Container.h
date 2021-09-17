#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <mutex>

template<class T>
  class Container
  {
  public:
    typedef T value_type;
    typedef std::vector<value_type> collection_t;
    
  public:
    Container();
    virtual ~Container();
    
    void pop(value_type obj);
    void push(value_type obj);
    
    const value_type& end() const {
      return _objects.data() + _objects.size();
    }
    const value_type& begin() const {
      return _objects.data();
    }
    
    value_type& end() {
      return _objects.data() + _objects.size();
    }
    value_type& begin() {
      return _objects.data();
    }
    
  private:
    std::mutex _mtx;
    collection_t _objects;
  };

#endif // CONTAINER_H
