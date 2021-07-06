#include "item.h"
#include "LL.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    item<int>* intlistitems[5]= {new item<int>(1), new item<int>(2), new item<int>(3), new item<int>(4), new item<int>(5)};
    LL<int> intlist(time(0));
    for (int index=4;index>=0;index--)
    {
        intlist.addItem(intlistitems[index]);
    }
    cout<<"Original list"<<endl;
    intlist.printList();
    cout<<"Min List Item: "<<intlist.minNode()<<endl;
    cout<<"Max List Item: "<<intlist.maxNode()<<endl;
    cout<<"Random Shuffled List with index 0"<<endl;
    intlist.randomShuffleList(0);
    intlist.printList();
    cout<<"Random Shuffled List with index 2"<<endl;
    intlist.randomShuffleList(2);
    intlist.printList();
    cout<<"List after being popped"<<endl;
    intlist.pop();
    cout<<"New Size: "<<intlist.getSize()<<endl;
    intlist.printList();
     cout<<"List after being popped"<<endl;
    intlist.pop();
    cout<<"New Size: "<<intlist.getSize()<<endl;
    intlist.printList();
     cout<<"List after being popped"<<endl;
    intlist.pop();
    cout<<"New Size: "<<intlist.getSize()<<endl;
    intlist.printList();
     cout<<"List after being popped"<<endl;
    intlist.pop();
    cout<<"New Size: "<<intlist.getSize()<<endl;
    intlist.printList();
     cout<<"List after being popped"<<endl;
    intlist.pop();
    cout<<"New Size: "<<intlist.getSize()<<endl;
    intlist.printList();
    cout<<"Random Shuffled List with Random Index"<<endl;
    intlist.randomShuffleList();
    intlist.printList();

    for (int index=4;index>=0;index--)
    {
        intlist.addItem(intlistitems[index]);
    }
    cout<<"NEw list "<<endl;
    intlist.printList();
     cout<<"Random Shuffled List with Random Index"<<endl;
    intlist.randomShuffleList();
    intlist.printList();
    
    



}