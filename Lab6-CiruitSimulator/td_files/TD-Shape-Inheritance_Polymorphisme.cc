#include<iostream>
#include<cstdio>
#include<iomanip>

using namespace std;

class Shape {
  public:

    virtual ~Shape(){
      std::cout << "shape" << std::endl;
    }
    /*void bar() {
    }
    Shape(Point const& p) : top_left{p} {}*/
  private:
    int only_shape;
    Point top_left;
  protected:
    int shape_and_subclasses;
    void bar(){
      cout <"shape's.bar"<<end;
    }  /*This bar fucntion is only available on shape class */
};

class Square : public Shape {
public:

    //if we want to use the bar fucntion from the Shape class we need to put like this
    using Shape::bar;
    using Shape:: Shape;
    /*
    void bar() {
      Shape::bar(); // need to be explicit there because there are two bar()
    }

    Square(Point const& p, int width) : Shape{p}, width{width} {}
    */
    Square (string filename ): Shape{}, t{new Texture{filename}}{};
    ~Square () override {delete t;} // if if we call a destrucctor from a shape, this function will be called
  private:
    int width;
};

class Rectangle : public Square {
public:
      Rectangle (string filename1, string filename2):
      Square {filename1},tr{new Texture{filename2}}{}
      ~Rectangle () override {delete tr;}
      void foo(){}; // Dynamic_cast  example
};


class Triangle : public Shape {

};

class Circle : public Shape {

};


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
    /*
    Square s{};
    s.globally = 3; // works
    s.only_shape = 5; // compile error
    s.shape_and_subclasses = 10; //compile error, can only be accessed in Square class
    s.bar() // calls square's barwhich calls shape's foo.
    */
    Shape * s {new Rectangle{}}; // or Shape * s {new Rectangle{}};
    delete s;

    Rectangle *r{ Dynamic_cast<Rectangle *> (s)};
    if(r!= nullptr)
      r->foo();
    s->globally = 10;
    ///////////////////////////////////////////////////
}
