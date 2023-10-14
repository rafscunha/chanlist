#ifndef STUDENT_hpp
#define STUDENT_hpp

#include "../List/List.hpp"


//FIFO
template <class T>
class Queue : private List<T>{
  void push(T* element);
  void pop();
  T* get();
}

template <class T>
void Queue<T>::push(){}

#endif /* Node_hpp */