#include "stack.h"

template <class T>
Stack<T>::Stack(){ //constructor
  // cout << "created" << endl;
  top = NULL;
}

template <class T>
Stack<T>::~Stack(){ //constructor
  // cout << "destroyed" << endl;
  clear();
}

template <class T>
bool Stack<T>::is_empty(){
  if(top == NULL){
    return true;
  }else{
    return false;
  }
}

template <class T>
void Stack<T>::push(T data){
  Node<T> *element = new Node<T>();
  element->data = data;
  element->next = top;
  top = element;
}

template <class T>
T Stack<T>::pop(){
  if(is_empty()){
    return 0;
  }else{
    Node<T> *temp = top;
    top = top->next;
    T ret_val = temp->data;
    delete(temp);
    return ret_val;
  }
}

template <class T>
void Stack<T>::clear(){
  Node<T> *temp = top;
  while(temp != NULL){
    top = top->next;
    delete(temp);
    temp = top;
  }
}

template <class T>
void Stack<T>::print(){
  Node<T> *temp = top;
  while(temp != NULL){
    cout << temp->data << "\t";
    temp = temp->next;
  }
  cout << endl;
}
