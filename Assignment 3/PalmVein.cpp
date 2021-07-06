#include <iostream>
#include <string>
#include <sstream>
#include "PalmVein.h"
#include "ContactlessDevice.h"
#include "AccessDevice.h"
#include "Exception.h"

using namespace std;

PalmVein::PalmVein(const string& key,const int& maxStud) : ContactlessDevice()//maxstud is either int or a string, differs in spec at places
{
    this->setKeyword(key);
    this->maxStudents=maxStud;
    this->setStudentDatabase();
   
}

PalmVein::~PalmVein()
{
   
}


string PalmVein::authenticateStudent(const string& codetofind)
{   
   return ContactlessDevice::authenticateStudent(codetofind); 
}
string PalmVein::registerStudent(const string& codetoenter)
{
    return ContactlessDevice::registerStudent(codetoenter);
}

char PalmVein::hashChar(char chartohash)
{
    //cout<<chartohash<<endl;
        stringstream ss;
        ss.clear();
        string temp;
        temp=chartohash;
       // cout<<"length: "<<temp.length()<<endl;
        ss.str(temp);
        int inttohash;
        ss>>inttohash;
        
       // cout<<inttohash<<endl;
        temp.clear();
        char hashedchar;
        if (rotor==0)
        {
           
            setRotor();   //could be throwing exception or just prevent problem
        }
        for (int index=0;index<10;index++)
        {
            if (rotor[index][keylength-1]==inttohash)
            {
                ss.clear();
                ss<<index;
                temp=ss.str();
                hashedchar=temp[0];
               // cout<<"found at "<<hashedchar<<endl;
                return hashedchar;
            }
        } 
        return hashedchar;
}

