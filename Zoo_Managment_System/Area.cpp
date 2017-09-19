#include "Area.h"

Area::Area(const char *name, int maxNumberOfAnimals, int maxNumberOfWorkers, const AreaManager* areaManager) :
name(_strdup(name)), maxNumberOfAnimals(maxNumberOfAnimals), maxNumberOfWorkers(maxNumberOfWorkers), numOfAnimals(0), numOfWorkers(0)
{
	//this->areaManager = areaManager;
	animals = new Animal*[maxNumberOfAnimals];
	workers = new Worker*[maxNumberOfWorkers];
}

Area::~Area()
{
	delete[]name;

	// Delete animals
	for (int i = 0; i < maxNumberOfAnimals; i++)
	{
		delete animals[i];
	}

	delete[]animals;

	// Delete workers
	for (int i = 0; i < maxNumberOfWorkers; i++)
	{
		delete workers[i];
	}

	delete[]workers;	
}

void Area::addAnimal(Animal& animal)
{
	if (numOfAnimals < maxNumberOfAnimals)
	{
		animals[numOfAnimals++] = &animal;
	}
}

void Area::addWorker(Worker& worker)
{
	if (numOfWorkers < maxNumberOfWorkers)
	{
		workers[numOfWorkers++] = &worker;
	}
}

ostream& operator<<(ostream& os, const Area& area)
{
	os << "Name: " << area.getName() << ", Max number of animals: " << area.getMaxNumberOfAnimals() << ", Number of animals: " << area.getNumOfAnimals()
		<< ", Max num of workers: " << area.getMaxNumberOfWorkers() << ", Number of workers: " << area.getNumOfWorkers() << ", Area manager: {" << area.getAreaManager() << "}, Animals: {";

	const Animal*const* animals = area.getAllAnimals();

	for (int i = 0; i < area.getNumOfAnimals(); i++)
	{
		os << "{" << *(animals[i]) << "}, ";
	}

	os << "}, Workers: {";

	const Worker*const* workers = area.getAllworkers();

	for (int i = 0; i < area.getNumOfWorkers(); i++)
	{
		os << "{" << *(workers[i]) << "}, ";
	}

	os << "}";

	return os;
}