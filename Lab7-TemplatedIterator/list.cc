#include <algorithm>
#include <iostream>

#include "list.h"

void List::insert(Data const& d)
{
  first = new Link(d, first);
}

//-----------------------------------------------------//
// Important copy and assignment stuff
List::Link*
List::Link::clone(Link const* dolly)
{
  if ( dolly != nullptr )
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}

List::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

List::List(List const& l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}

List::List(List&& l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}

List& List::operator=(List const& rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}

List& List::operator=(List&& rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}
