//
//  Giraffe.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __GIRAFFE_H
#define __GIRAFFE_H

#include "Animal.h"

class Giraffe : public Animal
{

private:
    
    float lengthOfNeck;
    Giraffe(const Giraffe& giraffe);
    const Giraffe& operator=(const Giraffe& giraffe);

public:
    
	Giraffe(const char *name, float weight, int birthYear, float lengthOfNeck);        
    
    inline float getLengthOfNeck() const;
    
    friend ostream& operator<<(ostream& os, const Giraffe& giraffe);
    
};

#endif /* __GIRAFFE_H */