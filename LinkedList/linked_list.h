#include<iostream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<random>

class Sorted_List{
public:
   Sorted_List();

   bool is_empty();
   int size();
   void insert(int val);
   bool is_first_on_list(int val);
   void remove(int val);
private:
    struct Link{
      int value;
      Link *next;
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
    Link *head{};
};
