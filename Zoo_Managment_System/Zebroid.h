//
//  Zebroid.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright � 2017 Almog Segal. All rights reserved.
//

#ifndef __ZEBROID_H
#define __ZEBROID_H

#include "Horse.h"
#include "Zebra.h"

class Zebroid : public Horse, public Zebra
{
private:
	Zebroid(const Zebroid& zebroid);
    const Zebroid& operator=(const Zebroid& zebroid);

public:
    
	Zebroid(const char *name, float weight, int birthYear, int numOfStrips, float sizeOfHorseShoe);        
    
    friend ostream& operator<<(ostream& os, const Zebroid& zebroid);
    
};

#endif /* __ZEBROID_H */