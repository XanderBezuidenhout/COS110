#ifndef LL_CPP
#define LL_CPP
#include "LL.h"
#include "item.cpp"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
LL<T>::LL(int rS)
{
    this->randomSeed=rS;
    size=0;
    this->head=nullptr;
}

template <class T>
LL<T>::~LL()
{
    item<T>* nodePtr; 
    item<T>* nextNode; 
    nodePtr = head;
 while (nodePtr != nullptr)
 {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
 }
}

template <class T>
item<T>* LL<T>::getHead() const
{
    return head;
}

template <class T>
void LL<T>::addItem(item<T>* newItem)
{
    if (head!=nullptr)
    {
        item<T>* currNode;
        item<T>* oldHead;
        item<T>* lastnode;
        
        currNode=this->head;
        oldHead=this->head;
        if (newItem->getData()<=this->minNode())
        {
            while (currNode->next!=nullptr)
            {
                currNode=currNode->next;
            }
            lastnode=currNode;
            lastnode->next=newItem;
            newItem->next=nullptr;
        }
        else
        {
            this->head=newItem;
            newItem->next=oldHead;
        }
        
    }
    else
    {
        head=newItem;
        newItem->next=nullptr;
    }
    size++;   
}

template <class T>
void LL<T>::randomShuffleList()
{
    if (this->size==0)
    {
        return;
    }
    srand(this->randomSeed);
    int nodeindex=rand()%(size);
    this->randomShuffleList(nodeindex);
}

template <class T>
void LL<T>::randomShuffleList(int i)
{
    int nodeindex=i;
    item<T>* currNode;
    item<T>* oldHead;
    //item<T>* lastNode;
    item<T>* newHead;
    item<T>* previous=nullptr;
    item<T>* nodebeforeselect=nullptr;
    if ((nodeindex<=0)||(nodeindex>=size))
    {
        return;
    }
        currNode=this->head;
        oldHead=this->head;
        int index=0;
        while (currNode!=nullptr)
        {    
            if (index==nodeindex)
            {
                newHead=currNode;
                nodebeforeselect=previous;
            }
            previous=currNode;
            currNode=currNode->next;
            index++;
        }
        this->head=newHead;
        previous->next=oldHead;
        if (nodebeforeselect!=nullptr)
        {
            nodebeforeselect->next=nullptr;
        }
        
}

template <class T>
item<T>* LL<T>::pop()
{
    if (this->size==0)
    {
        return NULL;
    }
    else
    {
        item<T>* oldHead=this->head;
        if (this->size==1)
        {
            this->head=nullptr;
        }
        else if(this->size>1)
        {
            this->head=this->head->next;
        }
        this->size--;
        return oldHead;
    }
    
   
    
}

template <class T>
item<T>* LL<T>::getItem(int i) const
{
    if (i>=size)
    {
        return NULL;
    }
    else if (i<0)
    {
        return NULL;
    }  
    else
    {
        item<T>* currNode;
        currNode=this->head;
        for (int index=0;currNode!=nullptr;index++)
        {
            if (index==i)
            {
                return currNode;
            }
            else
            {
                currNode=currNode->next;
            }
        }
        return currNode;
    }
    
}

template <class T>
T LL<T>::minNode()
{
    item<T> * currNode;
    item<T> * smallNode;
    if (head!=nullptr)
    {
        currNode=head;
        smallNode=head;
        while (currNode!=nullptr)
        {
            if (currNode->getData()<smallNode->getData())
            {
                smallNode=currNode;
            }
            currNode=currNode->next;
        }
        return smallNode->getData();
    }
    else
    {
        return 0; //return null or 0
    }
    
}

template <class T>
T LL<T>::maxNode()
{
    
    item<T> * currNode;
    item<T> * largeNode;
    if (head!=nullptr)
    {
        currNode=head;
        largeNode=head;
        while (currNode!=nullptr)
        {
            if (currNode->getData()>largeNode->getData())
            {
                largeNode=currNode;
            }
            currNode=currNode->next;
        }
        return largeNode->getData();
    }
    else
    {
        return 0; //return Null or 0
    }
}

template <class T>
int LL<T>::getSize() const
{
    return this->size;
}

template <class T>
void LL<T>::printList()
{
    item<T>* currNode=this->head;
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
   /* currNode=head;
    for (int index=0;currNode!=nullptr;index++)
    {
        if (currNode->next==nullptr)
        {
            cout<<currNode<<endl;
        }
        else
        {
            cout<<currNode<<"->"<<currNode->next<<"=";
        }
        currNode=currNode->next;  
    }*/
}
/*template class LL<int>;
template class LL<double>;
template class LL<string>;
template class LL<char>;
template class LL<float>;*/
#endif