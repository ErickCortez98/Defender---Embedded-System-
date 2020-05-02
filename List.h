//Provides implementation a templated linked list
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/30/2020

#include <stdint.h>

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
private:
	uint8_t length;
public:

  Node<T>* head;

  List(){
    head = NULL;
		length = 0;
  }
  
  ~List(){
    Node<T>* current = head;
    while(current != NULL){
      current = remove(current);
    }
  }
  
	uint8_t getLength(){
			return length;
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
		length++;
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
    
		length--;
    delete current->data;
    delete current;
    return next;
  }
};


#endif
