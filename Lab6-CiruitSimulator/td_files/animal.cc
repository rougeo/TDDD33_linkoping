#include<iostream>
#include<cstdio>
#include<iomanip>

using namespace std;

class Animal {
public:
  Animal (std::string const & name =""): name{name}{};
  virtual void make_sound () const = 0; // pure virtual
  void ~Animal()=default;
protected:
  string name;
}

class Cat : public Animal{
public:
  using Animal :: Animal();
  void make_sound() const override;
  ~Cat() = default;
}

int main(int argc, char const *argv[]) {
  Animal * d {new Cat{"cat"}};
  Cat p;
  Animal & t{p};
  t.make_sound();
  d->make_sound();
  return 0;
}
