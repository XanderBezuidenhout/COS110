#include <iostream>
#include <string>
#include <sstream>
#include "FacialRecognition.h"
#include "ContactlessDevice.h"
#include "Exception.h"
#include "AccessDevice.h"

using namespace std;

FacialRecognition::FacialRecognition(const string& key,const int& maxStudents,int stepSize) : ContactlessDevice()
{
    this->maxStudents=maxStudents;
    this->setKeyword(key);
    this->stepSize=stepSize;

}
FacialRecognition::~FacialRecognition()
{
    
}
void FacialRecognition::setStepSize(int stepsize)
{
    if (stepsize<0)
    {
        throw Exception("Negative number provided");
    }
    else
    {
        this->stepSize=stepsize;
    }
    
    
}

string FacialRecognition::registerStudent(const string& codetoenter)
{
    return ContactlessDevice::registerStudent(codetoenter);
}

string FacialRecognition::authenticateStudent(const string& codetofind)
{
    return ContactlessDevice::authenticateStudent(codetofind);
}
void FacialRecognition::changeRotorStart()
{
    iteration++;
    switch (iteration)
    {
        case 1:
        {
            tempkey[0]=keyword[0];
             for (int keyindex=1;keyindex<keylength;keyindex++)
             {
                tempkey[keyindex]=(keyword[keyindex]+tempkey[keyindex-1])%10;
             }
             break;
        }
        case 2:
        {
            tempkey[0]=(keyword[0]+stepSize)%10;
            prevtemp[0]=tempkey[0];
             for (int keyindex=1;keyindex<keylength;keyindex++)
             {
                tempkey[keyindex]=(keyword[keyindex]+tempkey[keyindex-1])%10;
                prevtemp[keyindex]=tempkey[keyindex];
             }
            break;
        }
        default:
        {
            tempkey[0]=(prevtemp[0]+ stepSize)%10;
            prevtemp[0]=tempkey[0];
            for (int keyindex=1;keyindex<keylength;keyindex++)
            {
                tempkey[keyindex]=(tempkey[keyindex-1]+prevtemp[keyindex])%10;
                prevtemp[keyindex]=tempkey[keyindex];
            }
            break;
        }
    }
}

char FacialRecognition::hashChar(char chartohash)
{
    
        stringstream ss;
        ss.clear();
        string temp;
        temp=chartohash;
        ss.str(temp);
        int inttohash;
        ss>>inttohash;

        temp.clear();
        char hashedchar;
        if (rotor==0)
        {
            setRotor();   //could be throwing exception or just prevent problem
        }
        this->changeRotorStart();
        this->setRotor();
        for (int index=0;index<10;index++)
        {
            if (rotor[index][keylength-1]==inttohash)
            {
                ss.clear();
                ss<<index;
                temp=ss.str();
                hashedchar=temp[0];
               // cout<<"found at "<<hashedchar<<endl;
                break;
            }
        } 
        for (int index=0;index<keylength;index++)
        {
            tempkey[index]=keyword[index];
        }
        
        return hashedchar;
}