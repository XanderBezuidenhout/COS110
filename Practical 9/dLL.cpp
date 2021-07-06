#ifndef DLL_CPP
#define DLL_CPP
#include "ditem.cpp"
#include "dLL.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
dLL<T>::dLL()
{
    this->head=nullptr;
    this->tail=nullptr;
    this->size=0;
}

template <class T>
dLL<T>::~dLL()
{
    ditem<T>* nodePtr; 
    ditem<T>* nextNode; 
    nodePtr = head;
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <class T>
ditem<T>* dLL<T>::getHead()
{
    return this->head;
}

template <class T>
ditem<T>* dLL<T>::getTail()
{
    return this->tail;
}

template <class T>
void dLL<T>::push(ditem<T>* newItem)
{
    if (newItem==nullptr)
    {
        return;
    }
    else if (this->size==0)
    {
        this->head=newItem;
        this->tail=newItem;
        newItem->prev=nullptr;
        newItem->next=nullptr;
        this->size++;
    }
    else
    {
        if (newItem->getData()<this->minNode())
        {
            newItem->next=this->head;
            newItem->prev=nullptr;
            this->head->prev=newItem;
            this->head=newItem;
        }
        else
        {
            this->tail->next=newItem;
            newItem->prev=this->tail;
            this->tail=newItem;
        }
        this->size++;
        
    }
    
}

template <class T>
ditem<T>* dLL<T>::pop()
{
    if (this->size==0)
    {
        return NULL;
    }
    else
    {
        ditem<T>* oldHead=this->head;
        if (this->size==1)
        {
            this->head=nullptr;
            this->tail=nullptr;
        }
        else if(this->size>1)
        {
            this->head=this->head->next;
            this->head->prev=nullptr;
        }
        this->size--;
        return oldHead;
    }
}

template <class T>
ditem<T>* dLL<T>::getItem(int i)
{
    if ((i<0)||(i>=this->size))
    {
        return nullptr;
    }
    ditem<T>* currNode;
    currNode=this->head;
    for (int index=0;currNode!=nullptr;index++)
    {
        if (index==i)
        {
            break;
            return currNode;
        }
        currNode=currNode->next;
    }
    return currNode;
}

template <class T>
T dLL<T>::minNode()
{
    T smallest;
    smallest=this->head->getData();
    ditem<T>* currNode;
    currNode=this->head;
    while (currNode!=nullptr)
    {
        if (smallest>currNode->getData())
        {
            smallest=currNode->getData();
        }
        currNode=currNode->next;
    }
    return smallest;
}

template <class T>
int dLL<T>::getSize()
{
    return this->size;
}

template <class T>
void dLL<T>::printList()
{
    ditem<T>* currNode=this->head;
    if (this->head==nullptr)
    {
        return;
    }
    for (int index=0;currNode!=nullptr;index++)
    {
        if (currNode->next==nullptr)
        {
            cout<<currNode->getData()<<endl;
        }
        else
        {
            cout<<currNode->getData()<<",";
        }
        currNode=currNode->next;  
    }
}
#endif
