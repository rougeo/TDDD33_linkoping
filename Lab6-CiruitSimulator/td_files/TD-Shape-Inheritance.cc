#include<iostream>
#include<cstdio>
#include<iomanip>

using namespace std;

class Shape {
  public:
    int globally;
    void foo() {

    }

    void bar() {

    }

    Shape(Point const& p) : top_left{p} {}
  private:
    int only_shape;
    Point top_left;
  protected:
    int shape_and_subclasses;
};

class Square : public Shape {
public:
    void bar() {
      foo();
    }

    void bar() {
      Shape::bar(); // need to be explicit there because there are two bar()
    }

    Square(Point const& p, int width) : Shape{p}, width{width} {}
  private:
    int width;
};

class Rectangle : public Square {

};

class Triangle : public Shape {

};

class Circle : public Shape {

};

// void foo(Shape &shape) {
//   shape.draw();
// }

void Square::foo() {
  Square s{};
  s.globally = 3; // works
  s.only_shape = 5; // compile error
  s.shape_and_subclasses = 10; // works
}

int main () {
    // Square square{};
    // Shape shape1{square};
    // Circle circle{};
    // Shape shape2{circle};

    // foo(circle);

    Square s{};
    s.globally = 3; // works
    s.only_shape = 5; // compile error
    s.shape_and_subclasses = 10; //compile error, can only be accessed in Square class
    s.bar() // calls square's barwhich calls shape's foo.
}
