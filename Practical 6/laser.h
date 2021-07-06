#ifndef LASER_H
#define LASER_H
#include "weapon.h"
#include <string>
#include <iostream>

using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>

class laser: public weapon
{
 private:
 int strength;

 public:
 laser(int s);
 ~laser();
 void setStrength(int s);
 int getStrength();
 string fire();
};
 #endif