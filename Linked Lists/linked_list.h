#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;


template <class T>
struct Node{
  T data;
  Node<T> *next;
};

template <class T>
class LinkedList{
  private:
    Node<T> *head;
  public:
    LinkedList();
    ~LinkedList();
    bool is_empty();
    void push_back(T data);
    void push_front(T data);
    void push_at(T data, int position);
    T pop_back();
    T pop_front();
    T pop_at(int position);
    void reverse();
    void clear();
    void print();
};

#include "linked_list.tpp"

#endif
