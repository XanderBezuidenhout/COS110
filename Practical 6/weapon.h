#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

using namespace std;

// uncomment what you need or add more
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <cstdlib>


class weapon
{
 private:
    int ammo;
    string type;
    string name;

 public:
    weapon();
    weapon(int a,string t,string n);
    virtual ~weapon();
    virtual string fire() =0;
    int getAmmo();
    void setAmmo(int a);
    string getType();
    void setType(string s);
    string getName();
    void setName(string s);
    template <class T>
    void ventWeapon(T heat);
    struct ammoOut:public exception
    {
        public:
            ammoOut();
            virtual ~ammoOut() throw();
            const char* what() const throw();
    };
};

#endif