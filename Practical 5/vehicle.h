#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

class vehicle
{
	private:
		char** map;
		std::string name;
		int size;
	public:
		vehicle();
		void setName(std::string s);
		std::string getName();
		char** getMap();
		int getSize();
		void setMap(std::string s);
		char getMapAt(int x,int y);
		virtual ~vehicle();
		virtual void operator--();
		virtual void determineRouteStatistics() =0;
};

#endif
