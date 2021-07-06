#ifndef DIESELLOCOMOTIVE_H
#define DIESELLOCOMOTIVE_H
#include "vehicle.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

class dieselLocomotive:public vehicle
{
	private:
		int passengerLimit;
	
	public:
		dieselLocomotive();//figure out how to call vehicle constructor
		~dieselLocomotive();
		int getPassengerLimit();
		void setPassengerLimit(int s);
		virtual void determineRouteStatistics();
};

#endif
