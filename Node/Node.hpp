#ifndef Node_hpp
#define Node_hpp

#include <iostream>

template <class T>
class Node {
  private :
    Node* last;
    Node* next;
    

  public:
  T* data;
  Node(Node* last, Node* next, T* date);
  Node* getNext();
  Node* getLast();
  void setNext(Node* next);
  void setLast(Node* last);
};

template <class T>
Node<T>::Node(Node* last, Node* next, T* data){
  this->last = last;
  this->next = next;
  this->data = data;
}

template <class T>
Node<T>* Node<T>::getNext(){
  return this->next;
};

template <class T>
Node<T>* Node<T>::getLast(){
  return this->last;
};

template <class T>
void Node<T>::setNext(Node* next){
  this->next = next;
};

template <class T>
void Node<T>::setLast(Node* last){
  this->last = last;
};

#endif /* Node_hpp */
