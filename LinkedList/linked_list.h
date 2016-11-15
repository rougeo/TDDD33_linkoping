#include<iostream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<random>
using namespace std;

class Sorted_List{
public:
   Sorted_List(); // constructor
   void copylist(Sorted_List other); // alternative way to copy list
   Sorted_List(int val); // instanciate list with one int value
   Sorted_List(Sorted_List const &); // deep copy constructor
   bool is_empty(); // checks whether list is empty
   int size(); // returns size of list
   void insert(int val); // insert value in list
   bool is_first_on_list(int val); // checks first value of list
   void print_list(); // print list in cout
   void remove(int val); // remove value in list (once)
   void get(int pos, int &val); // updates &val with value at position 'pos'
private:
    struct Link{
      int value;
      Link *next;

      //  insert subfunction
      Link * insert_s (Link *current,int val){
        Link *insert;
        insert = new struct Link;
        insert -> value = val;
        insert -> next = nullptr;
        // if nullptr, we are at the end of the list
        if (current == nullptr){
          return insert;
        }
        else{
          // checks next value, if greater then we are at the right position
          // so insert here
          if(current-> value > val){
            insert->next = current;
            return insert;
          }
          else{
            current ->next = insert_s(current->next,val);
          }}
        };

      // remove subfunction
      Link* remove_s (Link *current,int val){
        Link *to_remove;
        if (current != nullptr){
          // if current is not nullptr and next value is equal to the value we want
          // to remove, remove it
          if (current->value == val) {
            to_remove = current;
            current = current->next;
            to_remove -> next = nullptr;
            delete to_remove;
            return current;
          }
          else{
            // go to next value
            current ->next = remove_s(current->next, val);
            return current;
          }
        }
        else{
          return current;
      }
    };

    // print subfunction
    void print_list_s (Link *head){
        if (head != nullptr) {
          cout << head->value <<endl;
          return print_list_s(head->next);
        }
    };

    // subfunction for checking whether value is on the list
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
    Link* copy(Link* const other); // copy function
    Link *head{};
};
