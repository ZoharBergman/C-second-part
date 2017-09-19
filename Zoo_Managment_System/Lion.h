//
//  Lion.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __LION_H
#define __LION_H

#include "Animal.h"

enum eManeColor { WHITE, BROWN, YELLOW, RED, ORANGE };

class Lion : public Animal
{
private:
    
    eManeColor maneColor;
    Lion(const Lion& lion);
    const Lion& operator=(const Lion& lion);

public:
    
	Lion(const char *name, float weight, int birthYear, eManeColor maneColor);        
    
    inline eManeColor getManeColor() const;
    
    friend ostream& operator<<(ostream& os, const Lion& lion);
    
};


#endif /* __LION_H */