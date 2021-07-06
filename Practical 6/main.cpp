#include <iostream>
#include <string>
#include "weapon.h"
#include "laser.h"
#include "missile.h"
#include "fireControl.h"
#include <exception>


using namespace std;

int main()
{
    string * weaponlist;
    int numweapons=5;
    weaponlist=new string[numweapons];
    weaponlist[0]="beam laser";
    weaponlist[1]="missile launcher";
    weaponlist[2]="LASER UBER SHOT";
    weaponlist[3]="Missile destroya";
    weaponlist[4]="Laser proton cannon";
    try
    {
        cout<<"Not Failed Yet"<<endl;
        fireControl fire(numweapons,weaponlist);
        cout<<"Not Failed Yet"<<endl;
        for (int count=0;count<numweapons;count++)
        {
            fire.accessWeapon(count);
            cout<<fire.accessWeapon(count)->getName()<<": "<<endl;
            cout<<"Type: "<<fire.accessWeapon(count)->getType()<<endl;
            cout<<"Ammo: "<<fire.accessWeapon(count)->getAmmo()<<endl;
            
        }
        fire.accessWeapon(0)->ventWeapon(6);
       // fire.accessWeapon(5);
        fire.accessWeapon(0)->setAmmo(2);
        cout<<fire.accessWeapon(0)->fire()<<endl;
        cout<<fire.accessWeapon(0)->fire()<<endl;
        //cout<<fire.accessWeapon(0)->getName()<<endl;
        fire.accessWeapon(0)->setAmmo(1);
        cout<<fire.accessWeapon(0)->fire()<<endl;
        laser firstlaser(6);
        firstlaser.setName("firstlaser");
        cout<<"Venting firstlaser at 67.8:"<<endl;
        firstlaser.ventWeapon(67.8);
        missile firstmissile;
        firstmissile.setName("firstmissile");
        cout<<"Venting firstmissile at 112: "<<endl;
        firstmissile.ventWeapon(112);

    }
    catch(fireControl::weaponFailure& e)
    {
        cout << e.what() << '\n';
    }
    catch (weapon::ammoOut& e)
    {
       cout<<e.what()<<endl;
    }

    return 0;
}