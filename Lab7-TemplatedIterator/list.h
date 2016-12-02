#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include <string>

//using Data = std::string;

template <typename TYPE>
class List
{
public:
  List();
  ~List() { delete first; }

  void insert(TYPE const& d);
  List(List const&);
  List(List&&);
  List& operator=(List const&);
  List& operator=(List&&);


private:

  class Link
  {
  public:
    Link(TYPE const& d, Link* n)
      : data(d), next(n) {}
    ~Link() { delete next; }

    friend class List;

    static Link* clone(Link const*);

  private:

    TYPE data;
    Link* next;
  };

  Link* first;

public:

  using value_type = TYPE;

  // Suitable place to add things...

};

#include "list.tcc"
#endif
