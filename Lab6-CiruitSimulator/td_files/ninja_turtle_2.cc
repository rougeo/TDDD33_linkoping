// Multiple inheritance
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
class A: public D{
public:
  virtual void f(){};
};


class B: public D{
public:
  virtual void f(){};
};


class C: public A, public B{
public:
   void f() override{};
};


class D{
public:
  virtual void bar(){};
};

//using interface to avoid multiple inheritance problemes

class I{
public:
    virtual void foo()=0; // in this classe, there is a huge whole in thjis place
    virtual void bar()=0; // // in this classe, there is a huge whole in thjis place
    //We can't yet creat any instance of this class until this function
     //will be correctry writed; Remind the interfaces in Java
};


class J{
public:
    virtual void foo()=0; // in this classe, there is a huge whole in thjis place
    virtual void baz()=0; // // in this classe, there is a huge whole in thjis place
    //We can't yet creat any instance of this class until this function
     //will be correctry writed; Remind the interfaces in Java
};

class J: public I, public J {
public:
  void foo(){}; // now we have filled ou huge whole
  void baz(){};

}


int main(int argc, char const *argv[]) {
  /* code */
  C *c {new C()};
  c->f();
  c->A::f();
  c->B::f();
  return 0;
}
