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
#include "Area.h"

using namespace std;

class Animal
{
    
private:
    
    char *name;
    float weight;
    int birthYear;
    Area* area;
	Animal(const Animal& animal);
    const Animal& operator=(const Animal& animal);
    
public:
    
	Animal(const char *name, float weight, int birthYear, const Area* area = nullptr);
    ~Animal();        
    
    inline const char* getName() const;
    
    inline float getWeight() const;
    
    inline int getBirthYear() const;
    
    friend ostream& operator<<(ostream& os, const Animal& animal);

};

#endif /* __ANIMAL_H */