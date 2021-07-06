#include "fireControl.h"
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

fireControl::fireControl(int numWeapons,string* weaponList)
{
    this->numWeapons=numWeapons;
    weapons=new weapon*[numWeapons];
    for (int count=0;count<numWeapons;count++)
    {
        string search;
        search=weaponList[count];
        
        for (int index=0;index<search.length();index++)
        {
            search.at(index)=toupper(search.at(index));
        }
        //cout<<"Searchstring: "<<search<<endl;
       // cout<<search.find("LASER",0)<<endl;
        if (search.find("LASER",0)!=-1)
        {
            weapons[count]=new laser(5);
            weapons[count]->setName(weaponList[count]); 
           // cout<<"Its a laser"<<endl;
        }
        else if (search.find("MISSILE",0)!=-1)
        {
           weapons[count]=new missile();
            weapons[count]->setName(weaponList[count]); 
            //cout<<"Its a missile"<<endl;
        }
        /*switch (toupper(weaponList[count][0]))
        {
            case 'L':
            {
                weapons[count]=new laser(5);
                weapons[count]->setName(weaponList[count]); 
                break;
            }
            case 'M':
            {
                weapons[count]=new missile();
                weapons[count]->setName(weaponList[count]);
                break;
            }
        }*/
    }
}
fireControl::~fireControl()
{
    if (weapons!=0)
    {
        for (int count=0;count<this->numWeapons;count++)
        {
            if (this->weapons[count]!=0)
            {
                delete weapons[count];
               // weapons[count]=0;
            }
        }
        delete [] weapons;
        //weapons=0;
    }
}

weapon* fireControl::accessWeapon(int i)
{
    if ((i<0)||(i>=this->numWeapons))
    {
        throw weaponFailure();
    }
    else
    {
        return weapons[i];
    }
    
}

fireControl::weaponFailure::weaponFailure():exception()
{

}

fireControl::weaponFailure::~weaponFailure() throw()
{

}

const char* fireControl::weaponFailure::what() const throw()
{
    return "Weapon Systems Failure!";
}
