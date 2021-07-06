#include "train.h"
#include "bin.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout<<"Creating firsttrain with 2 int bins"<<endl;
    train<int> firsttrain(2);
    cout<<"1 added at index: "<<firsttrain.addBin(1)<<endl;
    cout<<"4 added at specific index 1: "<<firsttrain.addBin(1,4)<<endl;
    cout<<"3 added (supposed to fail) at index: "<<firsttrain.addBin(3)<<endl;
    cout<<"Storage of firsttrain"<<endl;
    firsttrain.printStorage();
    cout<<"Removing item at index 0: "<<firsttrain.removeBin(0)<<endl;
    cout<<"Removing item at index 1 of type int: "<<firsttrain.removeBin(1,1)<<endl;
    cout<<"Removing item at index 0:"<<firsttrain.removeBin(0,1)<<endl;
    firsttrain.printStorage();

    cout<<"Creating secondtrain with 2 string bins"<<endl;
    train<string> secondtrain(2);
    cout<<"one added at index: "<<secondtrain.addBin("one")<<endl;
    cout<<"four added at specific index 1: "<<secondtrain.addBin(1,"four")<<endl;
    cout<<"three added (supposed to fail) at index: "<<secondtrain.addBin("three")<<endl;
    cout<<"Storage of secondtrain"<<endl;
    secondtrain.printStorage();
    cout<<"Removing item at index 0: "<<secondtrain.removeBin(0)<<endl;
    cout<<"Removing item at index 1 of type string: "<<secondtrain.removeBin(1,"1")<<endl;
    cout<<"Removing item at index 0:"<<secondtrain.removeBin(0,"1")<<endl;
    secondtrain.printStorage();


    return 0;
}