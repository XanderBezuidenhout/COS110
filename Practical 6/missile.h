#ifndef MISSILE_H
#define MISSILE_H
#include "weapon.h"
#include <iostream>
#include <string>

using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>

class missile: public weapon
{
 private:

 public:
 missile();
 ~missile();
 string fire();
};

 #endif