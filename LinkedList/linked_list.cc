#include<iostream>
#include<cstdio>
#include<iomanip>
#include "linked_list.h"


using namespace std;

Sorted_List::Sorted_List(){
  head =nullptr;
}

Sorted_List::Sorted_List(int val){
  head = head->insert_s(nullptr,val);
}


bool Sorted_List::is_empty(){
  return (head == nullptr);
}
void Sorted_List::print_list(){
    head->print_list_s(head);
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
/*
void Sorted_List::insert(int val){
  Link *insert;
  insert = new struct Link;
  insert -> value = val;
  insert -> next = nullptr;
  if (is_empty()){
    head = insert;
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
*/


void Sorted_List::insert(int val){
        head = head->insert_s(head,val);
}


Sorted_List::Sorted_List(Sorted_List const & other) : head{copy(other.head)}{}


Sorted_List::Link* Sorted_List::copy(Sorted_List::Link* const other){
    if (other == nullptr) {
      return nullptr;
    }
    return new Link{other->value,Sorted_List::copy(other->next)};
}

void Sorted_List::copylist(Sorted_List other){
    head=copy(other.head);
}

/*
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
  }
}
*/

void Sorted_List::remove(int val){
  head = head->remove_s(head,val);
}
