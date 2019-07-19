#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

using namespace std;


template <class T>
struct Node{
  T data;
  Node<T> *next;
};

template <class T>
class Stack{
  private:
    Node<T> *top;
  public:
    Stack();
    ~Stack();
    bool is_empty();
    void push(T data);
    T pop();
    void reverse();
    void clear();
    void print();
};

#include "stack.tpp"

#endif
