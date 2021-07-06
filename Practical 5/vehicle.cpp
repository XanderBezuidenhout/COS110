#include "vehicle.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

vehicle::vehicle()
{
	map=0;
}

void vehicle::setName(std::string s)
{
	this->name=s;
}

std::string vehicle::getName()
{
		return (name);
}

char** vehicle::getMap()
{
		return map;
}

int vehicle::getSize()
{
		return size;
}

void vehicle::setMap(std::string s)
{
	this->operator--();
	ifstream file;
	file.open(s.c_str());
	string line;
	stringstream ss;
	//file>>this->size;
	getline(file,line);
	ss.clear();
	ss.str(line);
	ss>>this->size;
	map=new char*[this->size];
	
	for (int row=0;row<this->size;row++)
	{
			map[row]=new char[size];
			getline(file,line);
			for (int col=0;col<size;col++)
			{
				map[row][col]=line[col];
				//cout<<map[row][col];
			}
			//cout<<endl;		
	}
	file.close();
	
}

char vehicle::getMapAt(int x, int y)
{
	if ((x<0)||(x>=this->size)||(y<0)||(y>=this->size)||(map==0))
	{
			return ':';
	}
	else
	{
		if (map[y]!=0)
		{
			return map[x][y];
		}
		else
		{
			return ':';	
		}
	}
}

vehicle::~vehicle()
{
	if (map!=0)
	{
			for (int row=0;row<size;row++)
			{
				if (map[row]!=0)
				{
						delete map[row];
				}	
			}
			delete [] map;
	}
}

void vehicle::operator--()
{
	if (map!=0)
	{
			for (int row=0;row<size;row++)
			{
				if (map[row]!=0)
				{
						delete map[row];
				}	
			}
			delete [] map;
			size=0;
	}
	else
	{
			return;
	}
}



