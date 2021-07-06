#ifndef BIN_H
#define BIN_H
#include <string>
//#include <string>
using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>

template <class T>
class bin 
{
 private:
    T* item;

 public:
    bin(T t);
    ~bin();
    T getData() const;
};
 #endif
 //#include "bin.cpp"