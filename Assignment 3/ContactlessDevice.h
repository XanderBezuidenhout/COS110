#ifndef CONTACTLESSDEVICE_H
#define CONTACTLESSDEVICE_H
#include <iostream>
#include <string>
#include <sstream>
#include "AccessDevice.h"
//#include "Exception.h"

using namespace std;

class ContactlessDevice : public AccessDevice
{
    protected:
        int* keyword;
        int * tempkey;
        int * prevtemp;
        int iteration;
        int maxStudents;
        int currentStudent;
        int** rotor;  //Amount of asterisks differ in spec at places
        string** studentDatabase;
        virtual char hashChar(char)=0;  //THIS IS AN ABSTRACT CLASS, this should be virtual but this works better
        //int RotorStep; //one setting to set step between each iteration
       // int currstep; //RotorStep*numIterations
        int keylength;//length of keyword to dictate num cols of rotor
        void rotorRowSet(int keyoffset,int rotorrow); //sets row of rotor
        void clearRotor(); //frees memory if rotor already set
    public:
        virtual string registerStudent(const string&)=0;
        virtual string authenticateStudent(const string&);
        ContactlessDevice();
        virtual ~ContactlessDevice();
        int* setKeyword(const string&);
        void setRotor();
        virtual void changeRotorStart();
        int** getRotor();
        string** getStudentDatabase();
       // void setRotorStep(int stepsize);
        void setStudentDatabase();
        bool findStudent(const string& codetofind);
};
#endif