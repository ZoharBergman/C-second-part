#include "Zoo.h"

Zoo::Zoo(const char* name, int maxNumOfAreas) : name(_strdup(name)), maxNumOfAreas(maxNumOfAreas), numOfAreas(0)
{
	areas = new Area*[maxNumOfAreas];
}

Zoo::~Zoo()
{
	delete[]name;

	for (int i = 0; i < numOfAreas; i++)
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