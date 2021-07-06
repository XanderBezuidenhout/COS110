#ifndef CITEM_H
#define CITEM_H
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
class citem 
{
 private:
    T data;

 public:
    citem(T t);
    ~citem();
    citem<T>* next;
    T getData();
};
#include "citem.cpp"
 #endif