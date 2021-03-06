#include "Area.h"

Area::Area(const char *name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager* areaManager) :
	name(_strdup(name)), maxNumberOfAnimals(maxNumberOfAnimals), maxNumberOfWorkers(maxNumberOfWorkers), 
	numOfAnimals(0), numOfWorkers(0), areaManager(nullptr)
{
	animals = new Animal*[maxNumberOfAnimals];
	workers = new Worker*[maxNumberOfWorkers];
	setAreaManager(areaManager);	
}

Area::~Area()
{
	delete[]name;

	delete[]animals;

	delete[]workers;
}

void Area::setAreaManager(AreaManager* newAreaManager)
{
	if (areaManager != newAreaManager)
	{
		if (areaManager != nullptr)
		{
			areaManager->setArea(nullptr);
		}

		areaManager = newAreaManager;

		if (areaManager != nullptr)
		{
			areaManager->setArea(this);
		}
	}
}

void Area::addAnimal(Animal* animal) throw (const char*)
{
	// Checking that there is enough place for another animal
	if (numOfAnimals < maxNumberOfAnimals)
	{
		// Checking that the animal does not exists in this area
		if (animal != nullptr && isAnimalExists(animal) == NOT_FOUND)
		{
			animals[numOfAnimals++] = animal;
		}
	}
	else
	{
		throw "The number of animals in this area is the max";
	}
}

void Area::addWorker(Worker* worker) throw (const char*)
{
	// Checking that there is enough place for another wotker
	if (numOfWorkers < maxNumberOfWorkers)
	{
		// Checking that the worker does not exists in this area
		if (worker != nullptr && isWorkerExists(worker) == NOT_FOUND)
		{
			workers[numOfWorkers++] = worker;
			worker->setArea(this);
		}
	}
	else
	{
		throw "The number of workers in this area is the max";
	}
}

void Area::removeAnimal(const Animal* animal) throw (const char*)
{
	if (animal != nullptr)
	{
		int animalIndex = isAnimalExists(animal);

		// In case the animal exists, we should reduce the array of animals according to the index of the removed animal
		if(animalIndex != NOT_FOUND)
		{
			while (animalIndex < numOfAnimals - 1)
			{
				animals[animalIndex++] = animals[animalIndex + 1];
			}			

			numOfAnimals--;
		}
		else
		{
			throw "This animal does not exists in this area";
		}
	}
}

void Area::removeWorker(Worker* worker) throw (const char *)
{
	if (worker != nullptr)
	{
		int workerIndex = isWorkerExists(worker);

		// In case the worker exists, we should reduce the array of workers according to the index of the removed worker
		if(workerIndex != NOT_FOUND)
		{
			worker->setArea(nullptr);

			while (workerIndex < numOfWorkers - 1)
			{
				workers[workerIndex++] = workers[workerIndex + 1];
			}			
			
			numOfWorkers--;
		}
		else
		{
			throw "This worker does not exists in this area";
		}
	}
}

int Area::isWorkerExists(const Worker* worker) const
{
	for (int i = 0; i < numOfWorkers; i++)
	{
		if(workers[i] == worker)
			return i;
	}

	return NOT_FOUND;
}

int Area::isAnimalExists(const Animal* animal) const
{
	for (int i = 0; i < numOfAnimals; i++)
	{
		if(animals[i] == animal)
			return i;
	}

	return NOT_FOUND;
}

ostream& operator<<(ostream& os, const Area& area)
{
	if (&area != nullptr)
	{
		os << "Name: " << area.getName() << ", Max number of animals: " << area.getMaxNumberOfAnimals() << ", Number of animals: " << area.getNumOfAnimals()
			<< ", Max number of workers: " << area.getMaxNumberOfWorkers() << ", Number of workers: " << area.getNumOfWorkers() << ", Area manager: {" 
			<< *area.getAreaManager() << "}, Animals: {";

		const Animal*const* animals = area.getAllAnimals();

		for (int i = 0; i < area.getNumOfAnimals(); i++)
		{
			os << "{" << *(animals[i]) << "}, ";
		}

		if (area.getNumOfAnimals() > 0)
		{
			os << '\b' << '\b';
		}

		os << "}, Workers: {";

		const Worker*const* workers = area.getAllworkers();

		for (int i = 0; i < area.getNumOfWorkers(); i++)
		{
			os << "{" << *(workers[i]) << "}, ";
		}

		if (area.getNumOfWorkers() > 0)
		{
			os << '\b' << '\b';
		}

		os << "}";
	}

	return os;
}