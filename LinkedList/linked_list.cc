#include<iostream>
#include<cstdio>
#include<iomanip>
#include "linked_list.h"


using namespace std;

Sorted_List::Sorted_List(){
}

bool Sorted_List::is_empty(){
  return (head == nullptr);
}

bool Sorted_List::is_first_on_list(int val){
  return head->value == val;
}

int Sorted_List::size(){
  int size{0};
  Link *it{head};
  while(it != nullptr)
  {
    it = it->next;
    size ++;
  }
  return size;
    // for (Link* it{head}; it != nullptr; it = it -> next) {
  //   size++;
  // }
}

void Sorted_List::insert(int val){
  Link *insert;
  insert = new struct Link;
  insert -> value = val;
  insert -> next = nullptr;
  if (is_empty()){
    head = insert;
    //cout << head ->value <<endl;
  }
  else{
    if (!(head->is_on_the_list(val))) {
      Link *it{head};
      while((it-> next != nullptr) && ((it->next)->value <= val ))
      {
        it = it->next;
      }
      insert->next = it->next;
      it->next = insert;
    }
  }
}

void Sorted_List::remove(int val){
  Link *to_remove, *it{head};
  if (!is_empty()){
    if(is_first_on_list(val)){
      to_remove = head;
      head = head->next;
      to_remove -> next = nullptr;
      delete to_remove;
    }
    else{
      while((it-> next != nullptr) && ((it->next)->value != val ))
      {
        it = it->next;
      }
      if (it->next != nullptr ) {
        to_remove = it->next;
        it->next = to_remove ->next;
        to_remove -> next = nullptr;
        delete to_remove;
      }
    }
    /**********************************/
  }
}
