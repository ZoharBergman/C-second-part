#include "Zoo.h"

Zoo::Zoo(const char* name, int maxNumOfAreas) : name(_strdup(name)), maxNumOfAreas(maxNumOfAreas), numOfAreas(0)
{
	areas = new Area*[maxNumOfAreas];
}

Zoo::~Zoo()
{
	delete[]name;

	delete[]areas;
}

void Zoo::addArea(Area& area) throw (const char *)
{
	if (numOfAreas < maxNumOfAreas)
	{
		areas[numOfAreas++] = &area;
	}
	else
	{
		throw "The number of areas in this zoo is max";
	}
}

void Zoo::addAnimal(Animal& animal, const char* areaName) throw (const char *)
{
	int areaIndex = getAreaByName(areaName);

	if (areaIndex != NOT_FOUND)
	{
		areas[areaIndex]->addAnimal(&animal);
	}
	else
	{
		throw "This area name does not exists in this zoo";
	}
}

void Zoo::addWorker(Worker& worker, const char* areaName) throw (const char *)
{
	int areaIndex = getAreaByName(areaName);

	if (areaIndex != NOT_FOUND)
	{
		areas[areaIndex]->addWorker(&worker);
	}
	else
	{
		throw "This area name does not exists in this zoo";
	}
}

ostream& operator<<(ostream& os, const Zoo& zoo)
{
	if (&zoo != nullptr)
	{
		os << "Name: " << zoo.getName() << endl << "Max number of areas: " << zoo.getMaxNumOfAreas()
			<< endl << "Number of areas: " << zoo.getNumOfAreas() << endl << "Areas: " << endl;

		const Area*const* areas = zoo.getAllAreas();

		for (int i = 0; i < zoo.getNumOfAreas(); i++)
		{
			os << "{" << *areas[i] << "}";

			if (i < zoo.getNumOfAreas() - 1)
				os << "," << endl;
		}
	}

	return os;
}

int Zoo::getAreaByName(const char* name) const
{
	for (int i = 0; i < numOfAreas; i++)
	{
		if (strcmp(areas[i]->getName(), name) == 0)
		{
			return i;
		}
	}

	return NOT_FOUND;
}