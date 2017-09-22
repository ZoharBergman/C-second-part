#include "Zoo.h"

Zoo::Zoo(const char* name, int maxNumOfAreas) : name(_strdup(name)), maxNumOfAreas(maxNumOfAreas), numOfAreas(0)
{
	areas = new Area*[maxNumOfAreas];
}

Zoo::~Zoo()
{
	delete[]name;

	for (int i = 0; i < maxNumOfAreas; i++)
	{
		delete areas[i];
	}

	delete[]areas;
}

void Zoo::addArea(Area& area)
{
	if (numOfAreas < maxNumOfAreas)
	{
		areas[numOfAreas++] = &area;
	}
}

void Zoo::addAnimal(Animal& animal, const char* areaName)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		if (strcmp(areas[i]->getName(), areaName) == 0)
		{
			areas[i]->addAnimal(&animal);
		}
	}
}

void Zoo::addWorker(Worker& worker, const char* areaName)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		if (strcmp(areas[i]->getName(), areaName) == 0)
		{
			areas[i]->addWorker(&worker);
		}
	}
}

ostream& operator<<(ostream& os, const Zoo& zoo)
{
	os << "Name: " << zoo.getName() << ", Max number of areas: " << zoo.getMaxNumOfAreas() << ", Number of areas: " << zoo.getNumOfAreas() << ", Areas: {";

	const Area*const* areas = zoo.getAllAreas();

	for (int i = 0; i < zoo.getNumOfAreas(); i++)
	{
		os << "{" <<*areas[i] << "}, ";
	}

	os << "}";

	return os;
}