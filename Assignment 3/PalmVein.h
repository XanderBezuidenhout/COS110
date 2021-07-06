#ifndef PALMVEIN_H
#define PALMVEIN_H
#include "ContactlessDevice.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class PalmVein: public ContactlessDevice
{
    public:
      
        PalmVein(const string& key,const int& maxStud);
        ~PalmVein();
        virtual string registerStudent(const string&);
        virtual string authenticateStudent(const string&);
    protected:
        char hashChar(char);  //change to protected
};

#endif