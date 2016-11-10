#include <iostream>

using namespace std;
class Stack {
  Public:
    // constructor and destructor
    Stack() = default;
    ~Stack();
    Stack(Stack &&);
    // Stack& operator = (Stack&&);
    Stack(Stack const&);
    // Stack& operator = (Stack const&);
    void Push(int);
    int Pop();
  Private:
    struct Node {
      int value;
      Node* next;
    }
    Node* currNode{};
    Node* copy(Node const* n);
}

Stack::Stack(Stack const & other) : currNode{copy(other.currNode)} {}
Node* copy(Node* const other) {
  if (other == nullptr) {
    return nullptr;
  }
  return new Node {other -> value, copy(other -> next)};
}
// makes sure the chain is deleted when copied (destructor)
Stack::~Stack() {
  for (Node* it {currNode}; it != nullptr; it = currNode) {
    currNode = currNode -> next;
    it->next = nullptr; // null next field
    delete it; // deletes currNode (value and next not sure)
  }
}
