#ifndef FIRECONTROL_H
#define FIRECONTROL_H
#include "weapon.h"
#include "laser.h"
#include "missile.h"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>

using namespace std;

// uncomment what you need or add more

// #include <cstdlib>

class fireControl
{
 private:
 
 weapon ** weapons;

 int numWeapons;

 public:
 fireControl(int numWeapons,string* weaponList);
 ~fireControl();
 weapon* accessWeapon(int i);
 struct weaponFailure:public exception
 {
    public:
        weaponFailure();
        virtual ~weaponFailure() throw();
        const char* what() const throw(); 
    
 };
};

 #endif