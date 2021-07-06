#ifndef ELECTRICLOCOMOTIVE_H
#define ELECTRICLOCOMOTIVE_H
#include "vehicle.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

class electricLocomotive:public vehicle
{
	private:
		double perUnitCost;
	
	public:
		electricLocomotive();//figure out how to call vehicle constructor
		~electricLocomotive();
		double getUnitCost();
		void setUnitCost(double s);
		virtual void determineRouteStatistics();
};

#endif
