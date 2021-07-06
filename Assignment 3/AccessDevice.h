#ifndef ACCESSDEVICE_H
#define ACCESSDEVICE_H
#include <iostream>
#include <string>
#include <sstream>
#include "Exception.h"

using namespace std;

class AccessDevice
{
public:
    virtual string registerStudent(const string&) =0;
    virtual string authenticateStudent(const string&)=0; //THIS IS AN ABSTRACT CLASS
};


#endif