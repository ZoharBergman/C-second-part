//
//  Area.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __AREA_H
#define __AREA_H

#include <iostream>
#include "AreaManager.h"
#include "Worker.h"
#include "Animal.h"

//class Animal;
using namespace std;

class Area
{

private:
	char *name;
	int numOfAnimals;
	int maxNumberOfAnimals;
	int numOfWorkers;
	int maxNumberOfWorkers;
	AreaManager* areaManager;
	Animal** animals;
	Worker** workers;

	const static int NOT_FOUND = -1;

	Area(const Area& area);
	const Area& operator=(const Area& area);

public:

	Area(const char *name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager* areaManager = nullptr);
	~Area();	

	inline const char* getName() const { return name; }

	inline long getNumOfAnimals() const { return numOfAnimals; }
	inline long getMaxNumberOfAnimals() const { return maxNumberOfAnimals; }

	inline long getNumOfWorkers() const { return numOfWorkers; }
	inline long getMaxNumberOfWorkers() const { return maxNumberOfWorkers; }

	inline const AreaManager* getAreaManager() const { return areaManager; }
	inline AreaManager* getAreaManager() { return areaManager; }
	void setAreaManager(AreaManager* areaManager);

	void addAnimal(Animal* animal) throw (const char*);
	void addWorker(Worker* worker) throw (const char*);

	void removeAnimal(const Animal* animal) throw (const char *);
	void removeWorker(const Worker* worker) throw (const char *);

	const Animal*const* getAllAnimals() const { return animals; }
	const Worker*const* getAllworkers() const { return workers; }

	Animal*const* getAllAnimals() { return animals; }
	Worker*const* getAllworkers() { return workers; }

	const Area& operator+=(Animal* animal) throw (const char *) { addAnimal(animal); return *this; }

	bool operator<(const Area& other) const { return this->getMaxNumberOfAnimals() < other.getMaxNumberOfAnimals(); }

	bool operator>(const Area& other) const { return this->getMaxNumberOfAnimals() > other.getMaxNumberOfAnimals(); }

	bool operator==(const Area& other) const { return strcmp(this->getName(), other.getName()) == 0; }

	friend ostream& operator<<(ostream& os, const Area& area);

private:
	int isWorkerExists(const Worker* worker);
	int isAnimalExists(const Animal* animal);
};


#endif /* __AREA_H */
