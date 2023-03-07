

#include "list.hpp"
#include <iostream>

template <class Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List(){
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

//Add new item to front of list
template <class Item_Type>
void Single_Linked_List<Item_Type>::push_front(Item_Type d) {
  Node* new_node = new Node(d);
  new_node->next = head;
  head = new_node;
  if (tail == nullptr) {
    tail = new_node;
  }
  ++num_items;
}

//Add new item to end of list
template <class Item_Type>
void Single_Linked_List<Item_Type>::push_back(Item_Type d){
  Node* new_node = new Node(d);
  if (tail == nullptr) {
    head = new_node;
  } 
  else {
    tail->next = new_node;
  }
  tail = new_node;
  ++num_items;
}

//Remove item at front of list
template <class Item_Type>
void Single_Linked_List<Item_Type>::pop_front(){
  if (head == nullptr) {
    return;
  }
  Node* temp = head;
  head = head->next;
  if (head == nullptr) {
    tail = nullptr;
  }
  delete temp;
  --num_items;
}


//Remove item at end of list
template <class Item_Type>
void Single_Linked_List<Item_Type>::pop_back(){
  if (tail == nullptr){
    return;
  }
  if (head == tail){
    delete head;
    head = nullptr;
    tail = nullptr;
    --num_items;
  }
  Node* temp = head;
  while (temp->next != tail) {
    temp = temp->next;
  }
  delete tail;
  tail = temp;
  tail->next = nullptr;
  --num_items;
}

//Return head of list
template <class Item_Type>
Item_Type Single_Linked_List<Item_Type>::front(){
  return head->data;
}

//Return tail of list
template<class Item_Type>
Item_Type Single_Linked_List<Item_Type>::back(){
  return tail->data;
}

//Check if list is empty
template<class Item_Type>
bool Single_Linked_List<Item_Type>::empty(){
  return head == nullptr;
}

//Insert item at position index (starting at 0).Insert at the end if index is beyond the end of the list
template <class Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, Item_Type& d) {
  if (index == 0) {
    push_front(d);
  } 
  else if (index >= num_items) {
    push_back(d);
  } 
  else {
  Node* new_node = new Node(d);
  Node* temp = head;
  for (size_t i = 0; i < index - 1; ++i) {
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
  ++num_items;
  }
}

//Remove the item at position index. Return true if successful; return false if index is beyond the end of the list.
template <class Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
  if (index >= num_items) {
    return false;
  }
  Node* temp = head;
  if (index == 0) {
    pop_front();
  } 
  else {
    for (size_t i = 0; i < index - 1; ++i)
      temp = temp->next;
  }
  Node* del_node = temp->next;
  temp->next = del_node->next;
  if (del_node == tail) {
  tail = temp;
  }
  delete del_node;
  --num_items;

}

//Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found.
template <class Item_Type>
size_t Single_Linked_List<Item_Type>::find(Item_Type& item) {
  Node* temp = head;
  size_t index = 0;
  while (temp != nullptr) {
    if (temp->data == item) {
      return index;
    }
    temp = temp->next;
    ++index;
  }
  return num_items;
}


