#include "dieselLocomotive.h"

dieselLocomotive::dieselLocomotive():vehicle()
{
	
}

dieselLocomotive::~dieselLocomotive()
{
	cout<<"diesel locomotive removed"<<endl;
}

int dieselLocomotive::getPassengerLimit()
{
	return this->passengerLimit;
}

void dieselLocomotive::setPassengerLimit(int s)
{
	this->passengerLimit=s;
}

void dieselLocomotive::determineRouteStatistics()
{
	string viability;
	char** tempmap=this->getMap();
	int numPassengers=0;
	int hashes=0;
	int origin[2]={0,0};
	int exit[2]={0,0};
	int size=this->getSize();
	
	for (int row=0;row<size;row++)
	{
			for (int col=0;col<size;col++)
			{
				switch (tempmap[row][col])
				{
						case 'M':
						{
							numPassengers+=50;
							hashes++;
							break;
						}
						
						case 'N':
						{
							numPassengers+=25;
							hashes++;
							break;
						}
						
						case 'P':
						{	
							numPassengers+=10;
							hashes++;
							break;
						}
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
		cout<<"Name: "<<this->getName()<<endl;
	cout<<"Origin Coordinates: "<<origin[0]<<","<<origin[1]<<endl;
	cout<<"Exit Coordinates: "<<exit[0]<<","<<exit[1]<<endl;
	cout<<"Distance: "<<hashes<<endl;
	cout<<"Passengers Carried: "<<numPassengers<<endl;
	if (numPassengers>passengerLimit)
	{
			viability="Not Viable";
	}
	else
	{
		viability="Viable";
	}
	cout<<"Status: "<<viability<<endl;
}

