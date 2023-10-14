#ifndef Node_hpp
#define Node_hpp

#include <iostream>

template <class T>
class Node {
  private :
    Node* last;
    Node* next;
    T* data;

  public:
  Node(Node* last, Node* next, T* date);
  Node* getNext();
  Node* getLast();
  void setNext(Node* next);
  void setLast(Node* last);
};

#endif /* Node_hpp */
