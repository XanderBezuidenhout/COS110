#ifndef STORAGE_CPP
#define STORAGE_CPP
#include "storage.h"
#include "dLL.h"
#include "dLL.cpp"
#include "ditem.h"
#include "ditem.cpp"
#include "cLL.h"
#include "cLL.cpp"
#include "citem.h"
#include "citem.cpp"

template <class T>
storage<T>::storage(int rS)
{
    this->randomSeed=rS;
    this->cList = new cLL<T>;
    this->dList = new dLL<T>;
}

template <class T>
storage<T>::~storage()
{
    if (cList!=nullptr)
    {
         delete cList;
    }
    if (dList!=nullptr)
    {
         delete dList;
    }
   
}

template <class T>
void storage<T>::storeData(T data)
{
    if ((data%2)==0)
    {
        citem<T>* cData= new citem<T>(data);
        this->cList->push(cData);
    }
    else
    {
        ditem<T>* dData=new ditem<T>(data);
        this->dList->push(dData);
    }
    
}

template <class T>
void storage<T>::printCList()
{
    this->cList->printList();
}

template <class T>
void storage<T>::printDList()
{
    this->dList->printList();
}
#endif
