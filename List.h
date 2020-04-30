//Provides implementation a templated linked list
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/30/2020


#ifndef LIST_H
#define LIST_H

#define NULL 0

template<class T>
class Node{
    public:
    T* data;
    Node *next;
    Node *prev;
};  

template<class T>
class List{ 
public:

  Node<T>* head;

  List(){
    head = NULL;
  }
  
  ~List(){
    Node<T>* current = head;
    while(current != NULL){
      current = remove(current);
    }
  }
  
  void push_front(T *val){
    Node<T>* current = new Node<T>;
    current->data = val;
    current->next = head;
    current->prev = NULL;
    
    if(head){
      head->prev = current;
    }
    head = current;
  }
  
  Node<T>* remove(Node<T>* current){
    Node<T>* prev = current->prev;
    Node<T>* next = current->next;
    
    if(current == head){
      head = next;
    }
    
    if(prev){
      prev->next = next;
    }
    if(next){
      next->prev = prev;
    }
    
    delete current->data;
    delete current;
    return next;
  }
};


#endif
