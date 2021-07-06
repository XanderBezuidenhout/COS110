#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "locomotive.h"

using namespace std;

locomotive::locomotive() :vehicle()
{
	this->supplyRange=0;
}

locomotive::~locomotive()
{
	cout<<"locomotive removed"<<endl;
}

int locomotive::getSupplyRange()
{
	return supplyRange;
}

void locomotive::setSupplyRange(int s)
{
	this->supplyRange=s;
}
void locomotive::determineRouteStatistics()
{
	char** tempmap;
	tempmap=this->getMap();
	int asterisks=0,hashes=0;
	int origin[2]={0,0};
	int exit[2]={0,0};
	int size=this->getSize();
	string viability;
	
	for (int row=0;row<size;row++)
	{
			if (tempmap[row]!=0)
			{
					for (int col=0;col<size;col++)
					{
						switch (tempmap[row][col])
						{
								case '*':asterisks++;
								break;
								case '#':hashes++;
								break;
								case 'O':
								{	
									origin[0]=row;
									origin[1]=col;
									break;
								}
								case 'E':
								{
									exit[0]=row;
									exit[1]=col;
									break;
								}
								
						}
					}
			}
	}
	cout<<"Name: "<<this->getName()<<endl;
	cout<<"Supply Range: "<<this->getSupplyRange()<<" units"<<endl;
	cout<<"Origin Coordinates: "<<origin[0]<<","<<origin[1]<<endl;
	cout<<"Exit Coordinates: "<<exit[0]<<","<<exit[1]<<endl;
	cout<<"Distance: "<<hashes<<endl;
	cout<<"Number of Stations: "<<asterisks<<endl;
	if (asterisks>0)
	{
			viability="Viable";
	}
	else
	{
			viability="Not Viable";
	}
	cout<<"Status: "<<viability<<endl;
	
}

