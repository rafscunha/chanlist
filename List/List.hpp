#ifndef LIST_hpp
#define LIST_hpp

#include <iostream>
#include "../Node/Node.hpp"

template <class T>
class List{
  private:
  Node<T>* first = NULL;
  Node<T>* last = NULL;
  Node<T>* getNode(int n);
  void change(Node<T>* first, Node<T>* second);

  public:
  List();
  int push(T* element);
  int push(int n, T* element);
  T* get(int n);
  int remove(int n);
  int length();
  void pop();
  void shift();
  int unshift(T* element);
  void sort(std::function<bool(T*, T*)> func);
  T* find(std::function<bool(T*)> func);
};

template <class T>
List<T>::List(){
  this->first = NULL;
  this->last = NULL;
}

template <class T>
int List<T>::push(T* element){
  Node<T>* p_node = (Node<T>*) malloc(sizeof(Node<T>));
  new(p_node) Node<T>(this->last, NULL, element);
  if(this->last != NULL) {
    this->last->setNext(p_node);
  } else {
    this->first = p_node;
  }
  this->last = p_node;
  return 1;
};

template <class T>
int List<T>::push(int n, T* element){
  Node<T>* p_node_n = this->getNode(n);
  if (p_node_n != NULL){
    Node<T>* p_node = (Node<T>*) malloc(sizeof(Node<T>));
    new(p_node) Node<T>(p_node_n->getLast(), p_node_n->getNext(), element);
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
Node<T>* List<T>::getNode(int n){
  if (n == 0) return this->first;
  Node<T>* p_node_now = this->first;
  for (int i = 0 ; i < n && p_node_now != NULL ; i++) {
    p_node_now = p_node_now->getNext();
  }
  return p_node_now;
};

template <class T>
T* List<T>::get(int n){
  return this->getNode(n)->data;
};

template <class T>
int List<T>::remove(int n){
  Node<T>* p_node_n = this->getNode(n);
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
  for  (i = 0; p_node_now != NULL; i++){
    p_node_now = p_node_now->getNext();
  };
  return i;
};


template <class T>
void List<T>::pop(){
  if (this->last != NULL){
    Node<T>  *p_node = this->last;
    if (this->last == this->first){
      this->last = NULL;
      this->first = NULL;
    }else{
      this->last->getLast()->setNext(NULL);
      this->last = this->last->getLast();
    }
    delete p_node;
  }
}

//i can implement with this->remove(0); but e want to make a specialist method
template <class T>
void List<T>::shift(){
  if (this->first != NULL){
    Node<T>  *p_node = this->first;
    if (this->last == this->first){
      this->last = NULL;
      this->first = NULL;
    }else{
      this->first->getNext()->setLast(NULL);
      this->first = this->first->getNext();
    }
    delete p_node;
  }
}

//i can implement with this->push(0, element); but e want to make a specialist method
template <class T>
int List<T>::unshift(T* element){
  Node<T>* p_node = (Node<T>*) malloc(sizeof(Node<T>));
  if(this->first != NULL){
    new(p_node) Node<T>(NULL, this->first, element);
    this->first->setLast(p_node);
  }else {
    new(p_node) Node<T>(NULL, NULL, element);
    this->last = p_node;
  }
  this->first = p_node;

}

template <class T>
void List<T>::change(Node<T>* first, Node<T>* second){
  T* flag = first->data;
  first->data = second->data;
  second->data = flag;
}

template <class T>
void List<T>::sort(std::function<bool(T*, T*)> func){
  if (this->first != NULL){
    Node<T>* p_node_now = this->first;
    while (p_node_now != this->last){
      if (func(p_node_now->data, p_node_now->getNext()->data)){
        this->change(p_node_now, p_node_now->getNext());
      }
      p_node_now = p_node_now->getNext();
    }
  }
}

template <class T>
T* List<T>::find(std::function<bool(T*)> func){
  if (this->first != NULL){
    Node<T>* p_node_now = this->first;
    while (p_node_now != NULL){
      if (func(p_node_now->data)){
        return p_node_now->data;
      }
      p_node_now = p_node_now->getNext();
    }
  }else {
    return NULL;
  }
}

#endif /* LIST_hpp */
