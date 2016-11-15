#include<iostream>
#include<cstdio>
#include<iomanip>

using namespace std;

class Rectangle {
  public:
    void draw() {
      cout << "Draw rectangle";
    }

  private:
    Point top_left;
    int width;
    int height;
};

class Square {
  public:
    void draw() {
      cout << "Draw square";
    }

  private:
    Point top_left;
    int width;
};


class Window {
  public:
    void draw_all() {
      for (Square s : v2) s.draw();
      for (Rectangle r : v1) r.draw();
    }

    void add_rectangle(Rectangle r) {
      v1.push_back(r);
    }

    void add_square(Square s) {
      v2.push_back(s);
    }

  private:
    vector<Rectangle> v1;
    vector<Square> v2;
};

// alternate way to do it, instead of having a Rdcangle and Square class
// still not perfect because if we want a lot of shapes we need different constructors
// issue is moved from rectangle and square to shape
class Shape {
  public:
    Shape(String type, ...); // i.e. point, width, height
    void draw() {
        if (type == "Rectangle") cout << "Draw rectangle";
    }

  private:
    String type,
    Point top_left;
    int width;
    int height;
};

// window becomes:
class Window {
  public:
    draw_all() {
      for (Shape s : v) s.draw();
    }

    void add_shape(Shape s) {
      v.push_back(s);
    }

  private:
    vector<shape> v;
}
