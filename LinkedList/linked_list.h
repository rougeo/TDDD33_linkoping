#include<iostream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<random>




class Sorted_List{
public:
   Sorted_List();
   //~Sorted_List();
   bool is_empty();
   int size();
   void insert(int val);
      
private:
    struct Link{
      int value;
      Link *next;
    };

    Link *head{};
};
