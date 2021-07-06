#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H
#include "vehicle.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

class locomotive:public vehicle
{
	private:
		int supplyRange;
	public:
		locomotive(); //figure out how to call vehicle constructor
		~locomotive();
		int getSupplyRange();
		void setSupplyRange(int s);
		virtual void determineRouteStatistics();
};



#endif
