	//
//  Donkey.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __HOURSE_H
#define __HOURSE_H

#include "Animal.h"

class Horse : virtual public Animal
{

private:
    
    float sizeOfHorseShoe;
    Horse(const Horse& horse);
    const Horse& operator=(const Horse& horse);

public:
    
	Horse(const char *name, float weight, int birthYear, float sizeOfHorseShoe);        
    
    inline int getSizeOfHorseShoe() const;
    
    friend ostream& operator<<(ostream& os, const Horse& horse);
    
};


#endif /* __HOURSE_H */