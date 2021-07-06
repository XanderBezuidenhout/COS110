#include "electricLocomotive.h"

electricLocomotive::electricLocomotive():vehicle()
{
	
}

electricLocomotive::~electricLocomotive()
{
	cout<<"electric locomotive removed"<<endl;
}

double electricLocomotive::getUnitCost()
{
	return perUnitCost;
}

void electricLocomotive::setUnitCost(double s)
{
	perUnitCost=s;
}

void electricLocomotive::determineRouteStatistics()
{
	char** tempmap;
	tempmap=this->getMap();
	int hashes=0;
	int origin[2]={0,0};
	int exit[2]={0,0};
	int size=this->getSize();
	int trunccost=0;
	for (int row=0;row<size;row++)
	{
			if (tempmap[row]!=0)
			{
					for (int col=0;col<size;col++)
					{
						switch (tempmap[row][col])
						{
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
	cout<<"Origin Coordinates: "<<origin[0]<<","<<origin[1]<<endl;
	cout<<"Exit Coordinates: "<<exit[0]<<","<<exit[1]<<endl;
	cout<<"Distance: "<<hashes<<endl;
	trunccost=hashes*perUnitCost;
	cout<<"Cost: "<<trunccost<<endl;
}

