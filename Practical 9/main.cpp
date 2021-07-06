#include "storage.h"
#include "storage.cpp"
#include "dLL.h"
#include "dLL.cpp"
#include "cLL.h"
#include "cLL.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    storage<int> firststore(time(0));
    ditem<int> * dints[5]={new ditem<int>(2), new ditem<int>(3), new ditem<int>(4), new ditem<int>(5) ,new ditem<int>(1)};
    citem<float> * cfloats[5]={new citem<float>(2.3123), new citem<float>(3.123), new citem<float>(4.74574), new citem<float>(5.445), new citem<float>(1.001)};
    dLL<int> dFirstint;
    for (int count=0; count<5;count++)
    {
        dFirstint.push(dints[count]);
    }
    cout<<"Original first dlist: "<<endl;
    dFirstint.printList();
    cout<<"Smallest dlist value: "<<dFirstint.minNode()<<endl;
    cout<<"First dlist head value: "<<dFirstint.getHead()->getData()<<endl;
    cout<<"First dlist tail value: "<<dFirstint.getTail()->getData()<<endl;
    cout<<"First dlist size: "<<dFirstint.getSize()<<endl;
    cout<<"Ensuring correct linkages: "<<endl;
    for (int count=0;count<5;count++)
    {
        cout<<"Index "<<count<<": "<<dFirstint.getItem(count)->prev<<"<-"<<dFirstint.getItem(count)<<"->"<<dFirstint.getItem(count)->next<<endl;
    }   
    cout<<"Popping list until empty: "<<endl;
    while (dFirstint.getSize())
    {
        cout<<"Popped Head: "<<dFirstint.pop()<<endl;
    }
    cout<<"Try popping empty list"<<endl;
    cout<<dFirstint.pop()<<endl;
    cout<<"Repopulate with original values for destruct"<<endl;
    for (int count=0; count<5;count++)
    {
        dFirstint.push(dints[count]);
    }



    cLL<float> cSecondfloat;
    for (int count=0; count<5;count++)
    {
        cSecondfloat.push(cfloats[count]);
    }
    cout<<"Original second dlist: "<<endl;
    cSecondfloat.printList();
    cout<<"Second clist size: "<<cSecondfloat.getSize()<<endl;
    cout<<"Second clist head value: "<<cSecondfloat.head->getData()<<endl;
    cout<<"Ensuring correct linkages: "<<endl;
    citem<float> * currNode;
    currNode=cSecondfloat.head;
    for (int count=0;count<cSecondfloat.getSize()*2;count++)
    {
        if (currNode==cSecondfloat.head)
        {
            cout<<"HEADNODE "<<currNode->getData()<<"->";
        }
        else if (count==cSecondfloat.getSize()*2-1)
        {
            cout<<currNode->getData()<<endl;
        }
        else
        {
            cout<<currNode->getData()<<"->"; 
        }
        currNode=currNode->next;
    }   
    //cout<<endl;
    cout<<"Remove value of 1.001"<<endl;
    cout<<cSecondfloat.removeAt(1.001)<<endl;
    cSecondfloat.printList();
    cout<<"Popping list until empty: "<<endl;
    while (cSecondfloat.getSize())
    {
        cout<<"Popped Head: "<<cSecondfloat.pop()<<endl;
        cSecondfloat.printList();
    }
    cout<<"Try popping empty list"<<endl;
    cout<<cSecondfloat.pop()<<endl;
    cout<<"Repopulate with original values for destruct"<<endl;
    for (int count=0; count<5;count++)
    {
        cSecondfloat.push(cfloats[count]);
    }
    return 0;
}
