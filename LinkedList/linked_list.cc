#include<iostream>
#include<cstdio>
#include<iomanip>
#include "linked_list.h"


using namespace std;

/* instanciate a new empty list */
Sorted_List::Sorted_List(){
  head =nullptr;
}

/* instanciate a new sorted list with one int value*/
Sorted_List::Sorted_List(int val){
  head = head->insert_s(nullptr,val);
}

/*
 * checks whether the list is empty or not
 * returns true if list is empty, false otherwise
 */
bool Sorted_List::is_empty(){
  return (head == nullptr);
}

/* print the list on cout*/
void Sorted_List::print_list(){
    head->print_list_s(head);
}

/* checks whether value is first on list*/
bool Sorted_List::is_first_on_list(int val){
  return head->value == val;
}

/*
 * gets the value located at the 'pos' position
 * and updates the int& val parameter with the value at this position
 */
void Sorted_List::get(int pos, int &val) {
  Link *it{head};
  int act_pos = 0;

  while (it != nullptr) {
    if (pos == act_pos) {
      val = it->value;
      break;
    } else {
      it = it->next;
      act_pos++;
    }
  }
}

/* returns the size of the list */
int Sorted_List::size(){
  int size{0};
  Link *it{head};
  while(it != nullptr)
  {
    it = it->next;
    size ++;
  }
  return size;
}

/* insert a value 'val' in the list while sorting it*/
void Sorted_List::insert(int val){
        head = head->insert_s(head,val);
}

/*deep copy the list to another one while instanciating it*/
Sorted_List::Sorted_List(Sorted_List const & other) : head{copy(other.head)}{}

/*copy definition for deep copy*/
Sorted_List::Link* Sorted_List::copy(Sorted_List::Link* const other){
    if (other == nullptr) {
      return nullptr;
    }
    return new Link{other->value,Sorted_List::copy(other->next)};
}

/* alternative way to copy list if it is already instanciated */
void Sorted_List::copylist(Sorted_List other){
    head=copy(other.head);
}

/* removes an element 'val' in the list */
void Sorted_List::remove(int val){
  head = head->remove_s(head,val);
}
