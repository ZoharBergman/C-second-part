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

	// Delete animals
	for (int i = 0; i < numOfAnimals; i++)
	{
		delete animals[i];
	}

	delete[]animals;

	// Delete workers
	for (int i = 0; i < numOfWorkers; i++)
	{
		delete workers[i];
	}

	delete[]workers;	

	// Delete area manager
	delete areaManager;
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

void Area::addAnimal(Animal* animal)
{
	// Checking that there is enough place for another animal
	if (numOfAnimals < maxNumberOfAnimals)
	{
		// Checking that the animal does not exists in this area
		if (animal != nullptr && isAnimalExists(animal) == -1)
		{
			animals[numOfAnimals++] = animal;
		}
	}
}

void Area::addWorker(Worker* worker)
{
	// Checking that there is enough place for another wotker
	if (numOfWorkers < maxNumberOfWorkers)
	{
		// Checking that the worker does not exists in this area
		if (worker != nullptr && isWorkerExists(worker) == -1)
		{
			workers[numOfWorkers++] = worker;
			worker->setArea(this);
		}
	}
}

void Area::removeAnimal(const Animal* animal)
{
	if (animal != nullptr)
	{
		int animalIndex = isAnimalExists(animal);

		// In case the animal exists, we should reduce the array of animals according to the index of the removed animal
		if(animalIndex != -1)
		{
			while (animalIndex < numOfAnimals - 1)
			{
				animals[animalIndex++] = animals[animalIndex + 1];
			}			

			numOfAnimals--;
		}
	}
}
void Area::removeWorker(const Worker* worker)
{
	if (worker != nullptr)
	{
		int workerIndex = isWorkerExists(worker);

		// In case the worker exists, we should reduce the array of workers according to the index of the removed worker
		if(workerIndex != -1)
		{
			while (workerIndex < numOfWorkers - 1)
			{
				workers[workerIndex++] = workers[workerIndex + 1];
			}			

			numOfWorkers--;
		}
	}
}

int Area::isWorkerExists(const Worker* worker)
{
	for (int i = 0; i < numOfWorkers; i++)
	{
		if(workers[i] == worker)
			return i;
	}

	return -1;
}

int Area::isAnimalExists(const Animal* animal)
{
	for (int i = 0; i < numOfAnimals; i++)
	{
		if(animals[i] == animal)
			return i;
	}

	return -1;
}

ostream& operator<<(ostream& os, const Area& area)
{
	if (&area != nullptr)
	{
		os << "Name: " << area.getName() << ", Max number of animals: " << area.getMaxNumberOfAnimals() << ", Number of animals: " << area.getNumOfAnimals()
			<< ", Max number of workers: " << area.getMaxNumberOfWorkers() << ", Number of workers: " << area.getNumOfWorkers() << ", Area manager: {" << *area.getAreaManager() << "}, Animals: {";

		const Animal*const* animals = area.getAllAnimals();

		for (int i = 0; i < area.getNumOfAnimals(); i++)
		{
			os << "{" << *(animals[i]) << "}, ";
		}

		os << '\b' << '\b';

		os << "}, Workers: {";

		const Worker*const* workers = area.getAllworkers();

		for (int i = 0; i < area.getNumOfWorkers(); i++)
		{
			os << "{" << *(workers[i]) << "}, ";
		}

		os << '\b' << '\b';

		os << "}";
	}

	return os;
}