#include<iostream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<random>

class Sorted_List{
public:
   Sorted_List();
   Sorted_List(Sorted_List const &);
   bool is_empty();
   int size();
   void insert(int val);
   bool is_first_on_list(int val);
   void remove(int val);
private:
    struct Link{
      int value;
      Link *next;

      Link * insert_s (Link *current,int val){
        Link *insert;
        insert = new struct Link;
        insert -> value = val;
        insert -> next = nullptr;
        if (current == nullptr){
          return insert;
        }
        else{
          if((current->next == nullptr) || (current->value < val))
          {
            insert->next = current->next;
            current -> next = insert;
            return current;
          }
          else{
                current ->next = insert_s(current->next,val); //recursivity
                return current;
          }
        }
      };

      bool is_on_the_list(int val){
          if(value == val)
          {
            return true;
          }
          else
          {
            if(next != nullptr)
            {
              return next->is_on_the_list(val);
            }
            return false;
          }
      };
    };
    Link* copy(Link* const other);
    Link *head{};
};
