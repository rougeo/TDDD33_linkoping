template <typename T>
class Stack{
  public:
    T Pop();
    void Push(T v);
    bool empty();
  private:
    std::List<T> data;
}

template <typename T>
T Stack<T>::Pop(){
  T reseult = data.front();
  data.pop_front();
  return result;
}

template <typename T>
void Stack<T>::Push(T v){
  data.Push_front(v);
}
//we need to includ #include "Stack.cc"
//on the bottom of the h file.
// Then we will just compile the mainfile

/*
* Iterator on list
*/
class Linked_List{
  public:
    class Iterator;
    Iterator begin();
    Iterator end();
  private:
    class Link///////////////////////////////

}


class Iterator{
public:
    Iterator (Link* l):current{l}{}
    Iterator & operator++(); // pre-increment
    Iterator operator++(int); // post-increment
    bool  operator!=(Iterator const & other);
private:
    Link* current{};
    friend class List
}

::Iterator Linked_List::begin(){
    return Iterator{head};
}

::Iterator Linked_List::end(){
    return Iterator{nullptr};
}

int main(int argc, char const *argv[]) {
  List l{1,2,3};
  for (List::Iterator it=l.begin(); it != l.end(); ++it) {
    std::cout <<*it<< std::endl;
  }
  return 0;
}

Iterator & operator++(){
  if (current != nullptr ) {
    current = current->next;
  }
  return *this;
}

//friend classes
