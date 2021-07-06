#ifndef ITEM_CPP
#define ITEM_CPP
#include "item.h"

using namespace std;

template <class T>
item<T>::item(T t)
{
    data=t;
    next=nullptr;
}

template <class T>
item<T>::~item()
{
    cout<<data<<" Deleted"<<endl;
}

template <class T>
T item<T>::getData()
{
    return data;
}

/*template class item<int>;
template class item<double>;
template class item<string>;
template class item<char>;
template class item<float>;*/
#endif
