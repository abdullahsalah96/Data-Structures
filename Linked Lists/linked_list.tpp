#include "linked_list.h"

template <class T>
LinkedList<T>::LinkedList(){ //constructor
  // cout << "created" << endl;
  head = NULL;
}

template <class T>
LinkedList<T>::~LinkedList(){ //destructor
  // cout << "destroyed" << endl;
  clear();
}

template <class T>
bool LinkedList<T>::is_empty(){
  if(head == NULL){
    return true;
  }else{
    return false;
  }
}

template <class T>
void LinkedList<T>::push_back(T data){ //add element to the end
  Node<T> *element = new Node<T>();
  element->data = data;
  element->next = NULL;

  Node<T> *temp = head;

  if(head == NULL){
    head = element;
  }else{
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = element;
  }
}


template <class T>
T LinkedList<T>::pop_back(){ //remove element from back
  T ret_val;
  if(is_empty()){
    return 0;
  }else{
    Node<T>* temp = head;
    Node<T>* temp2 = head;
    int count = 0;
    while(temp->next != NULL){
      temp = temp->next;
      count++;
    }
    for(int i =0; i<count-1; i++){
      temp2 = temp2->next;
    }
    ret_val = temp->data;
    temp2->next = NULL;
    delete(temp);
  }
  return ret_val;
}

template <class T>
void LinkedList<T>::push_front(T data){ //add element to the front
  Node<T> *element = new Node<T>();
  element->data = data;
  element->next = head;
  head = element;
}

template <class T>
void LinkedList<T>::push_at(T data, int position){ //add element to the nth position
  // need to handle case when this position doesn't exist
  Node<T> *element = new Node<T>();
  element->data = data;
  element->next = NULL;
  if(position == 0){
    element->next = head;
    head = element;
  }else{
    Node<T> *temp = head;
    for(int i =0; i<position-1; i++){
      temp = temp->next;
    }
    element->next = temp->next;
    temp->next = element;
  }
}

template <class T>
T LinkedList<T>::pop_front(){ //remove element from front
  Node<T> *temp = head;
  head = head->next;
  T ret_val = temp->data;
  delete(temp);
  return ret_val;
}

template <class T>
T LinkedList<T>::pop_at(int position){ //remove element at nth position
  //need to handle case when position doesn't exist
  Node<T> *temp = head;
  T ret_val;
  if(position == 0){
    head = temp->next;
    ret_val = temp->data;
    delete(temp);
  }else{
    Node<T> *temp2 = head;
    for(int i=0; i<position-1; i++){
      temp = temp->next;
    }
    temp2 = temp->next;
    ret_val = temp2->data;
    temp->next = temp2->next;
    delete(temp2);
  }
  return ret_val;
}

template <class T>
void LinkedList<T>::reverse(){ //reverse linked list elements
  Node<T> *prev, *curr, *next;
  curr = head;
  prev = NULL;
  next = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

template <class T>
void LinkedList<T>::print(){ //print list elements
  Node<T> *temp = head;
  while(temp != NULL){
    cout << temp->data << "\t";
    temp = temp->next;
  }
  cout << endl;
}

template <class T>
void LinkedList<T>::clear(){ //removes all list elements
  Node<T> *temp = head;
  while(temp != NULL){
    head = head->next;
    delete(temp);
    temp = head;
  }
}
