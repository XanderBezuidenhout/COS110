#ifndef CITEM_CPP
#define CITEM_CPP
#include "citem.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
citem <T>::citem(T t)
{
    this->data=t;
}

template <class T>
citem <T>::~citem()
{
    cout<<this->data<<" Deleted"<<endl;
}

template <class T>
T citem <T>::getData()
{
    return this->data;
}
#endif
