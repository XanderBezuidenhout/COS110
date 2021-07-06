#ifndef LL_H
#define LL_H
#include <cstdlib>
#include "item.h"
#include <iostream>

using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>

template <class T>
class LL
{
 private:
    item<T>* head;
    int size;
    int randomSeed;

 public:
    LL(int rS);
    ~LL();
    item<T>* getHead() const;
    void addItem(item<T>* newItem);
    void randomShuffleList();
    void randomShuffleList(int i);
    item<T>* pop();
    item<T>* getItem(int i) const;
    T minNode();
    T maxNode();
    int getSize() const;
    void printList();
};
#include "LL.cpp"
 #endif