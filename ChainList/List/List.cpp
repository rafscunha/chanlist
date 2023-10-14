#include "../Node/Node.hpp"
#include "List.hpp"

template <class T>
int List<T>::push(T* data){
  Node<T>* p_node = (Node<T>*) malloc(sizeof(Node<T>));
  new(p_node) Node<T>(this->last, NULL, data);
  this->last->setNext(p_node);
  this->last = p_node;
  return -1;
};

template <class T>
int List<T>::push(int n, T* data){
  Node<T>* p_node_n = this->get(n);
  if (p_node_n != NULL){
    Node<T>* p_node = (Node<T>*) malloc(sizeof(Node<T>));
    new(p_node) Node<T>(p_node_n->getLast(), p_node_n->getNext(), data);
    if (p_node_n->getLast() == NULL)
      this->first = p_node;
    else
      p_node_n->getLast()->setNext(p_node);
    if (p_node_n->getNext() == NULL)
      this->last = p_node;
    else
      p_node_n->getNext()->setLast(p_node);
    return 1;
  } else { return -1; };
};

template <class T>
T* List<T>::get(int n){
  if (n == 0) return this->first;
  Node<T>* p_node_now = this->first;
  for (int i = 0 ; i < n && p_node_now != NULL ; i++) {
    p_node_now = p_node_now->getNext();
  }
  return p_node_now;
};

template <class T>
int List<T>::remove(int n){
  Node<T>* p_node_n = this->get(n);
  if (p_node_n != NULL) {
    if (p_node_n->getLast() == NULL) {
      this->first = p_node_n->getNext();
    } else {
      p_node_n->getLast()->setNext(p_node_n->getNext());
    }
    if (p_node_n->getNext() == NULL){
      this->last = p_node_n->getLast();
    } else {
      p_node_n->getNext()->setLast(p_node_n->getLast());
    }
    delete p_node_n;
    return 1;
  } else { return -1; };
};

template <class T>
int List<T>::length(){
  Node<T>* p_node_now = this->first;
  int i;
  for  (i = 0; p_node_now != NULL; i++);
  return i;
};



