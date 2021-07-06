
#include "weapon.h"
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

using namespace std;


weapon::weapon()
{

}
weapon::~weapon()
{

}

weapon::weapon(int a,string t,string n)
{
    this->ammo=a;
    this->type=t;
    this->name=n;
}


int weapon::getAmmo()
{
    return this->ammo;
}


void weapon::setAmmo(int a)
{
    this->ammo=a;
}


string weapon::getType()
{
    return this->type;
}


void weapon::setType(string s)
{
    this->type=s;
}


string weapon::getName()
{
    return this->name;
}


void weapon::setName(string s)
{
    this->name=s;
}

template<class T>
void weapon::ventWeapon(T heat)
{
    if (heat<10)
    {
        cout<<"Insufficient heat to vent"<<endl;
        return;
    }
    else
    {
        T cycles=heat/10;
        int loop=int(cycles);
        for (int count=1;count<=loop;count++)
        {
            cout<<"Heat Cycle "<<count<<endl;
        }
    }
    
}
weapon::ammoOut::ammoOut() : exception()
{

}
weapon::ammoOut::~ammoOut() throw()
{

}
const char* weapon::ammoOut::what() const throw()
{
    return "Ammo Depleted!";
}

template void weapon::ventWeapon<int>(int);
template void weapon::ventWeapon<double>(double);



