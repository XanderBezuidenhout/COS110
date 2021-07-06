#include <iostream>
#include "PalmVein.h"
#include "FacialRecognition.h"

using namespace std;

int main() {
    string s = "456";

    PalmVein palmVein(s, 5);
    FacialRecognition facecialRecognition(s, 5, 2);

    int *keyWord = palmVein.setKeyword(s);
   for (int i = 0; i < s.length(); i++)
    {
        cout << keyWord[i];
    }
    cout << endl;
    palmVein.setRotor();
    facecialRecognition.setRotor();
    int **rotor = palmVein.getRotor();
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < s.length(); j++)
         {
            cout << rotor[i][j]<< " ";
        }
        cout << endl;
    }
    //cout<<endl<<"First rotorset of facialrecognition: "<<endl;
   /* int **rotor = facecialRecognition.getRotor();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < s.length(); j++) {
            cout << rotor[i][j]<< " ";
        }
        cout << endl;
    }*/
   /* cout<<"See if palmvein changes rotor with 4 successive sets with same key and 0 step: Start"<<endl;
    for (int count=0;count<4;count++)
    {
        int **rotor = palmVein.getRotor();
        for (int i = 0; i < 10; i++)
         {
            for (int j = 0; j < s.length(); j++)
            {
                cout << rotor[i][j]<< " ";
            }
            cout << endl;
        }
        cout<<endl;
        palmVein.setRotor();
    }*/
    /* cout<<"hashed char of 734"<<endl;
    cout<<palmVein.hashChar('7');
    cout<<palmVein.hashChar('3');
    cout<<palmVein.hashChar('4')<<endl;*/
    try
    {
         palmVein.registerStudent("7345");
        palmVein.registerStudent("563");
        palmVein.registerStudent("100986");
        palmVein.registerStudent("5335");

    }
    catch(Exception e)
    {
        cout<< e.getError() << '\n';
    }
    
   
    cout << "palmVein.authenticateStudent(5335)" << endl;
    cout << palmVein.authenticateStudent("5335")<< endl;
    string **db = palmVein.getStudentDatabase();
    for (int i = 0; i < 5; i++)
     {
        for (int j = 0; j < 2; j++) 
        {
            cout << db[i][j]<< " ";
        }
        cout << endl;
    }
    try
    {
        //PalmVein newpalm("warra",5);
    }
    catch(Exception e)
    {
        cout<< e.getError() << '\n';
    }
    
   cout << facecialRecognition.registerStudent("7345")<< endl;
    return 0;
}

/*
 Output
 --------------
456
4 9 5
5 0 6
6 1 7
7 2 8
8 3 9
9 4 0
0 5 1
1 6 2
2 7 3
3 8 4
palmVein.authenticateStudent(5335)
0880true
7345 2890
563 018
100986 655431
5335 0880
z z
2680
 */