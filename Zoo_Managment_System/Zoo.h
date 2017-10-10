//
//  Zoo.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 18/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ZOO_H
#define __ZOO_H

#include "Area.h"
#include "Worker.h"
#include "Animal.h"

using namespace std;

class Zoo
{
private:
    const static int NOT_FOUND = -1;

    char* name;
    int maxNumOfAreas;
    int numOfAreas;
    Area** areas;

	Zoo(const Zoo* other);
	const Zoo& operator=(const Zoo& other);

public:
    
    Zoo(const char* name, int maxNumOfAreas);
    ~Zoo();
    
	const char* getName() const { return name; }
    
	int getMaxNumOfAreas() const { return maxNumOfAreas; }
	int getNumOfAreas() const { return numOfAreas; }
    
    void addArea(Area& area) throw (const char *);
    
    void addAnimal(Animal& animal, const char* areaName) throw (const char *);
    
    void addWorker(Worker& worker, const char* areaName) throw (const char *);
    
	const Area*const* getAllAreas() const { return areas; }
	Area*const* getAllAreas() { return areas; }
    
	const Zoo& operator+=(Area& area) throw (const char *) { addArea(area); return *this; }
    
	const Area& operator[](int index) const { return *areas[index]; }
    
    friend ostream& operator<<(ostream& os, const Zoo& zoo);

private:
	int getAreaIndexByName(const char* name) const;
};


#endif /* __ZOO_H */