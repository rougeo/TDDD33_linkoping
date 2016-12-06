#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

//using Data = std::string;


template <typename T> class Iterator;
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

private:
  class Link
  {
  public:
    Link(T const& d, Link* n)
      : data(d), next(n) {}
    ~Link() { delete next; }
    friend class List;
    friend class Iterator<T>;
    static Link* clone(Link const*);

  private:

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
    Link* current{first};
    if (current != nullptr){
    while (current->next != nullptr) {
        current = current -> next;
      }
    }
    return current;
  };
  // Suitable place to add things...
  friend class Iterator<T>;
};


template <typename T>
class Iterator {
public:
    //Iterator( Link & l): current( l ){}
/*
    T operator* () {     //dereferencing operator
            return p->getValue(); //It returns the contents of a Node object
    }

    void operator++ () { //inc operator
        p = p->getNext();
    }
    void operator++ (int) {
        p = p->getNext();
    }

    bool operator!= (const Iterator<int>& iterator) {
        return p != iterator.p;
    }

    operator Node<T>*() {
        return p;
    }
*/
//  using value_type2 = T2;
//  Iterator(List<T2>* l){current=l;}
//  Iterator & operator++(); // pre-increment
//  Iterator operator++(int); // post-increment
//  bool  operator!=(Iterator const & other);

private:
      List<T>* current;
      Link* current2;
      //friend class Link;
};

#include "list.tcc"
#endif
