#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>

template <class T>
class item 
{
 private:
    T data;

 public:
    item(T t);
    ~item();
    item<T>* next;
    T getData();
};
#include "item.cpp"
#endif