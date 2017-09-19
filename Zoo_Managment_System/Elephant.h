//
//  Elephant.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ELEPHANT_H
#define __ELEPHANT_H

#include "Animal.h"
#include "Area.h"

class Elephant : public Animal
{

private:
    
    float sizeOfEars;
    float lengthOfTrunk;
    Elephant(const Elephant& elephant);
    const Elephant& operator=(const Elephant& elephant);

public:
    
	Elephant(const char *name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk);      
    
    inline float getSizeOfEars() const;
    inline float getLengthOfTrunk() const;
    
    friend ostream& operator<<(ostream& os, const Elephant& elephant);
    
};

#endif /* __ELEPHANT_H */