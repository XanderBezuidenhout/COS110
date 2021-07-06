#ifndef FACIALRECOGNITION_H
#define FACIALRECOGNITION_H
#include <iostream>
#include <string>
#include <sstream>
#include "ContactlessDevice.h"

using namespace std;

class FacialRecognition: public ContactlessDevice
{
    private:
        int stepSize;
    public:
        FacialRecognition(const string&,const int&,int stepSize=0);
        ~FacialRecognition();
        void setStepSize(int);
        string registerStudent(const string&);
        string authenticateStudent(const string &);
        void changeRotorStart();
    protected: 
        char hashChar(char);
    
};

#endif