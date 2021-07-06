#include "missile.h"
#include "weapon.h"
#include <iostream>
#include <string>

using namespace std;

missile::missile(): weapon()
{
    this->setAmmo(0);
    this->setType("missile");
}

missile::~missile()
{
    cout<<this->getName()<<" Uninstalled!"<<endl;
}

string missile::fire()
{
    if (this->getAmmo()<=0)
    {
        throw ammoOut();
    }
    else
    {
        string output;
        output.clear();
        output.append(this->getName());
        output.append(" fired!");
        //cout<<this->getName()<<" fired!"<<endl;
        this->setAmmo(this->getAmmo()-1);
        return output;
    }
    
}

