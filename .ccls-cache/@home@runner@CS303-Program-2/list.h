#pragma once


template <typename Item_Type>
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
    void pop_front(Item_Type d);
    void pop_back(Item_Type d);


};
