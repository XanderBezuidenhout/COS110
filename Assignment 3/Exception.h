#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Exception
{
    protected:
        string error;
    public:
        Exception(const string& errormessage)
        {
            this->error=errormessage;
        }
        string getError()
        {
            return this->error;
        }
};
#endif