#include<iostream>
#include<iomanip>

using namespace std;

class Shape {
  public:
    void foo() {
      cout << "Shape's foo";
    }
};

class Square : public Shape {
  public:
    void foo() {
      cout << "Square's foo";
    }
};

int main() {
  Square square{};
  square.foo(); // "Square's foo"
  Shape shape{};
  shape.foo(); // "Shape's foo"

  Shape& test{square};
  test.foo(); //"Shape's foo"
}
