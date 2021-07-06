#ifndef STORAGE_H
#define STORAGE_H
#include "dLL.h"
#include "dLL.cpp"
#include "ditem.h"
#include "ditem.cpp"
#include "cLL.h"
#include "cLL.cpp"
#include "citem.h"
#include "citem.cpp"

using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>

template <class T>
class storage
{
 private:
    cLL<T>* cList;
    dLL<T>* dList;
    int randomSeed;

 public:
    storage(int rS);
    ~storage();
    void storeData(T data);
    void printCList();
    void printDList();
};
#include "storage.cpp"
#endif