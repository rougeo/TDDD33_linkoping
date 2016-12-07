#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

//using Data = std::string;

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
  friend std::ostream;
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
      friend std::ostream;

    private:
      friend class Iterator;
      friend std::ostream;
      T data;
      Link* next;
  };

  Link* first;
public:
  using value_type = T;

    class Iterator {
      private:
          Link* current;
          friend std::ostream;

      public:
        Iterator(Link* l):current(l){}
        Iterator(const Iterator& t)=default;
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

    Iterator begin(){
      Iterator it{first};
      return  it;
    }
    Iterator end(){
      Iterator it{nullptr};
      return it;
    }
    // Suitable place to add things...

};


#include "list.tcc"
#endif
