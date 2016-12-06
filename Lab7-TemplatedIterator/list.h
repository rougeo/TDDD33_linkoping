#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

//using Data = std::string;


//template <typename T> class Iterator;
template <typename T>
class List
{
public:
   List();
  ~List() { delete first; }
  void insert(T const& d);
  List(List const&);
  List(List&&);
  List& operator=(List<T> const&);
  List& operator=(List<T>&&);
  /*friend std::ostream& operator<<(std::ostream& out, const List& o){
    {
       return os << (o->first).getData;
   };
 */
private:
  class Link
  {
    public:
      Link(T const& d, Link* n)
        : data(d), next(n) {}
      ~Link() { delete next; }
      T getData(){return data;}
      friend class List;
      friend class Iterator;
      static Link* clone(Link const*);


    private:
      friend class Iterator;
      T data;
      Link* next;
  };

  Link* first;
public:
  using value_type = T;
  Link* begin(){
    return first;
  };
  Link* end(){
  /*  Link* current{first};
    if (current != nullptr){
    while (current->next != nullptr) {
        current = current -> next;
      }
    }
    return current;
    */return nullptr;
  };
  // Suitable place to add things...
  //friend class Iterator<T>;

    class Iterator {
      private:
          Link* current;

      public:
        Iterator(Link* l):current(l){}
        Link* getCurrent(){
          return current;
        }
        T operator* () {     //dereferencing operator
            return current->data; //It returns the contents of a Node object
        }

        void operator++ () { //inc operator
            current = current->next;
        }

        void operator++ (int) {
            current = current->next;
        }

        bool operator!= (const Iterator& iterator) {
            return current != iterator.current;
        }

    };

};


#include "list.tcc"
#endif
