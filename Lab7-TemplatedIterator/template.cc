//template

void printTwice (int data){
  cout<< data*2<<endl;
}

void printTwice (int double){
  cout<< data*2<<endl;
}

void printTwice (long data){
  cout<< data*2<<endl;
}

//So in this case, we needed 3 functions to print 3 differents types of data twice;

// To fix that, we use templates


void printTwice (TYPE data){
  cout<< data*2<<endl;
} /*that what we wouldlike*/

//In order to do that, we will :

template <typename TYPE>
void printTwice (TYPE data){
  cout<< data*2<<endl;
}
//Now the compiler will adapt the function to the typename
printTwice(3);
printTwice(3.14);

/********************************************************************/
//Another one

template <typename TYPE>
TYPE twice (TYPE data){
  return data*2;
}


//It works too
template <typename TYPE, typename TYPE1 >
TYPE twice (TYPE1 data){
  return data*2;
}

/***********************************************************************/

template <typename T>
T multiply (T a, T b){
  return a*b;
}

multiply(3.4); // => 12
// the generated code will be
int multiply(int a, int b){
  return a*b
}


// if we have
multiply ("hi", "bye");
// the generated code will be
int multiply(string a, string b){
  return a*b
}
// there will be a compile error which says that a string has no operatot *
/*******************************************************************************/
template <typename T>
T sum (T a, T b){
  T result; // so the type must have a default constructor
  result = a + b // the type must have + operator
  return result;
}

/*******************************************************/

template <typename T>
void twice (T& data){
  data *= 2;
}

template <typename T>
void twice (T* data){
  (*data) = (*data) * 2;
}
/********************************************************/

template <typename T1, typename T2>
T1 multiply(T1 a, T2 b){
  return a*b;
}
multiply(3.14, 5);

/****************************************************/

class Item {
public:
  Item(): data {0}{};
  void setData (int value){
    data=value;
  }
  int getData(){
    return data;
  }
private:
  int data;
}
//////////////// Main file;

Item item1;
item1.setData(3);
cout<<item1.getData();

/*  Now with the templates if we wouldlike to use multiple data types*/

template <typename T>
class Item {
  T data;
public:
  Item(): data {T{}}{};
  void setData (T value){
    data=value;
  }
  T getData(){
    return data;
  }
//private:
//  int data;
}

Item<int> item1;

Item<double> item2;
// that's how vector works  vector <int> v;

/******************************************************************/
template <typename T1, typename T2>
Struc Pair{
  T1 first;
  T2 second;
}

Pair <int,int> point;
point.first = 10;
point.second = 20;

Pair <string,string> name;
name.first ="Sam";
name.second = "Le"
///////////////////////////////////////////
/***********************************************************************/
/*                        Operator overloading                         */
/***********************************************************************/


// member function
int plus (int i){
  return data + i;
}

item1.setData(3);
std::cout << item1.plus(5)<< std::endl;


/************************************/
//but if we wouldlike to use like this item1+5

return_type orperator+(argument_datatype name)

int operator+(int i){
  return data + i;
}


// now we can use directly
item1 + 5;
//same as
item1.operator+(5);

5+ item1 // this line won't work but if we add this code outside the class
int operator+(int i, Item item){
  return item+5;
}
// Really weird



/*******************************************************************************/
/* Prefix an postfix incrementation
/*******************************************************************************/

++item => Prefix
Item& operator++(){
  ++data;
  return *this;
}

itm++ => postfix
Item operator++(int){
  Item temp{};
  temp.setData (data);
  ++data;
  return temp;
}


// Comparaison of two objects

bool operator !=(Item const& other){
  return data != othe.data;
}

Item<int> i1;

i1.setData(3);
Item<int> i2;
i2.setData (5);

if(i1 !=i2 ){
  // do a lot of stuffs
}
