#ifndef BIN_CPP
#define BIN_CPP
#include "bin.h"
#include <string>

using namespace std;

template <class T>
bin<T>::bin(T t)
{
    this->item= new T;
    *(this->item)=t;
}

template <class T>
bin<T>::~bin()
{
    if (item!=0)
    {
         delete item;
    }
   
}

template <class T>
T bin<T>::getData() const
{
    return *(this->item);
}
#endif
template class bin<int>;
template class bin<double>;
template class bin<string>;
template class bin<char>;
template class bin<float>;