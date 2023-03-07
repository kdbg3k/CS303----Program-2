//Program 2
//Class: CS303
//Author: Katy Bohanan
//Date: 03/06/2023

#pragma once
#include <cstddef>

template <class Item_Type>
class Single_Linked_List {
  struct Node{
    Item_Type data;
    Node* next;
  };
  private:
    Node* head;
    Node* tail;
    int num_items;
  public:
    Single_Linked_List();
    void push_front(Item_Type d);
    void push_back(Item_Type d);
    void pop_front();
    void pop_back();
    Item_Type front();
    Item_Type back();
    bool empty();
    void insert(size_t index, Item_Type& d);
    bool remove(size_t index);
    size_t find(Item_Type& item);
};
