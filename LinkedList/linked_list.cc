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
    cout << head ->value <<endl;
  }
  else{
    Link *it{head};
    while((it-> next != nullptr) || ((it->next)->value <= val ))
    {
      it = it->next;
    }
    insert->next = it->next;
    it->next = insert;
  }
}
