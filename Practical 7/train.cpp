#ifndef TRAIN_CPP
#define TRAIN_CPP
#include "train.h"
#include "bin.h"
#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

template <class T>
train<T>::train(int numBins)
{
    this->bins=numBins;
    this->storage=new bin<T>*[numBins];
    for (int binindex=0;binindex<numBins;binindex++)
    {
        this->storage[binindex]=NULL;
    }
}

template <class T>
train<T>::~train()
{
    //ignore deallocation
}

template <class T>
int train<T>::addBin(T item)
{
    bool added=false;
    for (int binindex=0;binindex<bins;binindex++)
    {
        if (storage[binindex]==NULL)
        {
            this->storage[binindex]=new bin<T>(item);
            added=true;
            return binindex;
        }
    }
          return -1;
    
  
}

template <class T>
int train<T>::addBin(int index,T item)
{
    if (index<0 || index>=bins)
    {
        return -1;
    }
    if (storage[index]==NULL)
    {
            this->storage[index]=new bin<T>(item);
            return index;
    }
    else
    {
      //  cout<<"Failed to add"<<endl;
        return -1;
    }
    
}

template <class T>
int train<T>::removeBin(int index)
{
    if (index<0 || index>=bins)
    {
        return -1;
    }
    if (storage[index]!=0)
    {
        delete storage[index];
        storage[index]=0;
        return index;
    }
    else
    {
        return -1;
    }
    

}

template <class T>
int train<T>::removeBin(int index,T type)
{
    if (index<0 || index>=bins)
    {
        return -1;
    }
    if (storage[index]!=0)
    {
        if (typeid(storage[index]->getData()).name()==typeid(type).name())
        {
            delete storage[index];
            storage[index]=0;
            return index;
        }
        else
        {
             return -1;
        
        }
        
        
        
        
    }
    else
    {
        return -1;
    }
    
        
    
}

template <class T>
void train<T>::printStorage()
{
    for (int binindex=0;binindex<bins;binindex++)
    {
        if (storage[binindex]!=0)
        {
            std::cout<<"Bin "<<binindex+1<<": "<<storage[binindex]->getData()<<std::endl;
        }
        else
        {
            std::cout<<"Bin "<<binindex+1<<": NA"<<std::endl;
        }
        
    }
}

template class train<int>;
template class train<double>;
template class train<string>;
template class train<char>;
template class train<float>;
#endif