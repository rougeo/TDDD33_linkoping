#include<iostream>
#include<cstdio>
#include<iomanip>

using namespace std;


class Ninja {
};

class Turtle{
};

/*Sub class of both up classes*/
class TMNT: public Ninja , public Turtle{
};

class A{
public:
  virtual void f(){};
};


class B{
public:
  virtual void f(){};
};


class C: public A, public B{
public:
   void f() override{};
};



int main(int argc, char const *argv[]) {
  /* code */
  C *c {new C()};
  c->f();
  c->A::f();
  c->B::f();
  return 0;
}
