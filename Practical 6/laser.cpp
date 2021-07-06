#include "laser.h"
#include "weapon.h"
#include <string>
#include <iostream>

laser::laser(int s): weapon()
{
    this->setAmmo(0);
    this->strength=s;
    this->setType("laser");
}


laser::~laser() 
{
    cout<<this->getName()<<" Uninstalled!"<<endl;
}


void laser::setStrength(int s)
{
    this->strength=s;
}


int laser::getStrength()
{
    return this->strength;
}


string laser::fire()
{
    if (this->getAmmo()<=0)
    {
        throw ammoOut();
    }
    else
    {
        string output;
        stringstream ss;
        output.clear();
        output.append(this->getName());
        output.append(" fired at strength: ");
        ss<<this->getStrength();
        output.append(ss.str());
        
        //cout<<this->getName()<<" fired at strength: "<<this->getStrength()<<endl;
        this->setStrength(this->getStrength()+1);
        this->setAmmo(this->getAmmo()-1);
        return output;
        
    }
    
    
}

