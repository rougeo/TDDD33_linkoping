#include <algorithm>
#include <iostream>
#include <string>

#include "list.h"

using namespace std;
template <typename T>
void List<T>::insert(T const& d)
{
  first = new Link(d, first);
}

/*
template <typename T>
List<T>::Link* List<T>::begin(){
  return first;
}

template <typename T>
List<T>::Link* List<T>::end(){
  return nullptr;
}
*/


template <typename T>
std::ostream& operator<<(std::ostream& out, List<T> & l)
{

   return out <<l.begin()->getData()<<endl;
   //out <<"hello world"<<endl;
}

//-----------------------------------------------------//
// Important copy and assignment stuff
/*template <typename T>
List<T>::Link*  List<T>::Link::clone(Link const* dolly)
{
  if ( dolly != nullptr )
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}
*/

template <typename T>
List<T>::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

template <typename T>
List<T>::List(List<T> const& l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}


template <typename T>
List<T>::List(List<T>&& l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}


template <typename T>
List<T>& List<T>::operator=(List<T> const& rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List<T> copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}


template <typename T>
List<T>& List<T>::operator=(List<T>&& rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}


/*
 template <typename T>
List<T>& List::operator=(List<T>&& rhs)

 */
