#ifndef TRAIN_H
#define TRAIN_H
#include "bin.h"
//#include "train.cpp"
#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>

template <class T>

class train
{
 private:
    bin<T>** storage;
    int bins;

 public:
    train(int numBins);
    ~train();
    int addBin(T item);
    int addBin(int index,T item);
    int removeBin(int index);
    int removeBin(int index,T type);
    void printStorage();
};
 #endif
// #include "train.cpp"