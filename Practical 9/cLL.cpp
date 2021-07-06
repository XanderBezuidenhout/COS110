#ifndef CLL_CPP
#define CLL_CPP
#include "cLL.h"
#include "citem.cpp"
#include "citem.h"

template <class T>
cLL<T>::cLL()
{
    this->size=0;
    this->head=nullptr;
}

template <class T>
cLL<T>::~cLL()
{
    if (this->size==0)
    {
        return;
    }
    else if (this->size==1)
    {
        delete this->head;
        return;
    }
    citem<T>* nodePtr=this->head->next; 
    citem<T>* nextNode; 
    for (int count=1;count<this->size;count++)
    {
        nextNode=nodePtr->next;
        delete nodePtr;
        nodePtr=nextNode;
    }
    delete this->head;
}

template <class T>
bool cLL<T>::isEmpty()
{
    return (this->size==0);
}

template <class T>
int cLL<T>::getSize()
{
    return this->size;
}

template <class T>
void cLL<T>::push(citem<T>* newItem)
{
    if (newItem==nullptr)
    {
        return;
    }
    else if (this->size==0)
    {
        this->head=newItem;
        newItem->next=nullptr;
        this->size++;
    }
    else if (this->size==1)
    {
        if (newItem->getData()>this->head->getData())
        {
            newItem->next=this->head;
            this->head->next=newItem;
            this->head=newItem;
        }
        else
        {
            this->head->next=newItem;
            newItem->next=this->head;
        }
        this->size++;  
    }
    else
    {
        citem<T>* currNode;
        citem<T>* prevNode;
        citem<T>* tailNode;
        currNode=this->head;
        prevNode=this->head;
        bool largest=true;
        do 
        {
            prevNode=currNode;
            currNode=currNode->next;
        }while (currNode!=this->head);
        tailNode=prevNode;
        do 
        {
            largest=(newItem->getData()>currNode->getData());
            if (!largest)
            {
                break;
            }
            prevNode=currNode;
            currNode=currNode->next;
        }while (currNode!=this->head);
        if (largest)
        {
            newItem->next=this->head;
            tailNode->next=newItem;
            this->head=newItem;
        }
        else
        {
            newItem->next=this->head;
            tailNode->next=newItem;
        }
        this->size++;
    }
    
}

template <class T>
citem<T>* cLL<T>::pop()
{
    if (this->size==0)
    {
        return NULL;
    }
    else
    {
        citem<T>* oldHead=this->head;
        citem<T>* currNode;
        citem<T>* prevNode;
        citem<T>* tailNode;
        currNode=this->head;
        prevNode=this->head;
        bool largest=true;
        do 
        {
            prevNode=currNode;
            currNode=currNode->next;
        }while (currNode!=this->head);
        tailNode=prevNode;
        tailNode->next=oldHead->next;
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
citem<T>* cLL<T>::removeAt(T x)
{
    if (this->head==nullptr)
    {
        return NULL;
    }
    citem<T>* currNode;
    citem<T>* prevNode;
    currNode=this->head;
    prevNode=nullptr;
    for (int count=0;count<this->size;count++)
    {
        if (currNode->getData()==x)
        {
            if (currNode==this->head)
            {
                return this->pop();
            }
            else
            {
                prevNode->next=currNode->next;
                this->size--;
                return currNode;
            }
        }
        prevNode=currNode;
        currNode=currNode->next;
    }
    return NULL;
}

template <class T>
void cLL<T>::printList()
{
    
    if (this->head==nullptr)
    {
        return;
    }
    if (this->size==1)
    {
        cout<<this->head->getData()<<endl;
        return;
    }
    else
    {
        cout<<this->head->getData()<<",";
    } 
    citem<T>* currNode=this->head->next;
    for (int index=0;currNode!=this->head;index++)
    {
        if (currNode->next==this->head)
        {
            cout<<currNode->getData()<<endl;
            return;
        }
        else
        {
            cout<<currNode->getData()<<",";
        }
        currNode=currNode->next;  
    }

}
#endif
