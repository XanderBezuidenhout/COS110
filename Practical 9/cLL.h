#ifndef CLL_H
#define CLL_H

#include <iostream>
#include <string>
#include "citem.cpp"
#include "citem.h"

using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>

template <class T>
class cLL
{
 private:
   
    int size;

 public:
    citem<T>* head; //make private again
    cLL();
    ~cLL();
    bool isEmpty();
    int getSize();
    void push(citem<T>* newItem);
    citem<T>* pop();
    citem<T>* removeAt(T x);
    void printList();
};

#include "cLL.cpp"
#endif