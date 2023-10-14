#ifndef LIST_hpp
#define LIST_hpp

#include <iostream>
#include "../Node/Node.hpp"

template <class T>
class List{
  private:
  Node<T>* first = NULL;
  Node<T>* last = NULL;

  public:
  int push(T* data);
  int push(int n, T* data);
  T* get(int n);
  int remove(int n);
  int length();
};

#endif /* LIST_hpp */
