//
//  Animal.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <iostream>

using namespace std;

class Animal
{
private:
	// Attributes
    char *name;
    float weight;
    int birthYear;

	// Deleted methods
	Animal(const Animal& animal);
    const Animal& operator=(const Animal& animal);
    
public:
	// Ctor & Dtor
	Animal(float weight, int birthYear, const char *name = nullptr);
	virtual ~Animal() { delete []name; }
    
	// Getters & Setters
	inline const char* getName() const { return name; }
    inline float getWeight() const { return weight; }
    inline int getBirthYear() const { return birthYear; }
    
	// Operators
    friend ostream& operator<<(ostream& os, const Animal& animal);

	// Methods
	virtual void toOs(ostream& os) const {};
};

#endif /* __ANIMAL_H */