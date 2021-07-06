#ifndef DITEM_H
#define DITEM_H
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
class ditem 
{
 private:
     T data;

 public:
    ditem(T t);
    ~ditem();
    ditem<T>* next;
    ditem<T>* prev;
    T getData();
};
#include "ditem.cpp"
 #endif