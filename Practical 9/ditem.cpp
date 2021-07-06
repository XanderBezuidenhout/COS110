#ifndef DITEM_CPP
#define DITEM_CPP
#include <string>
#include <iostream>
#include "ditem.h"

using namespace std;

template <class T>
ditem <T>::ditem(T t)
{
    this->data=t;
}

template <class T>
ditem <T>::~ditem()
{
    cout<<this->data<<" Deleted"<<endl;
}

template <class T>
T ditem <T>::getData()
{
    return this->data;
}

#endif