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
    
    char* name;
    int maxNumOfAreas;
    int numOfAreas;
    Area** areas;

public:
    
    Zoo(const char* name, int maxNumOfAreas);
    ~Zoo();
    
	const char* getName() const { return name; }
    
	int getMaxNumOfAreas() const { return maxNumOfAreas; }
	int getNumOfAreas() const { return numOfAreas; }
    
    void addArea(Area& area);
    
    void addAnimal(Animal& animal, const char* areaName);
    
    void addWorker(Worker& worker, const char* areaName);
    
	const Area*const* getAllAreas() const { return areas; }
	Area*const* getAllAreas() { return areas; }
    
	const Zoo& operator+(Area& area) { addArea(area); return *this; }
    
	const Area& operator[](int index) const { return *areas[index]; }
    
    friend ostream& operator<<(ostream& os, const Zoo& zoo);
};


#endif /* __ZOO_H */