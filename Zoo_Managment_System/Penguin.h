//
//  Penguin.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __PENGUIN_H
#define __PENGUIN_H

#include "Animal.h"

enum eSeaFood { SHRIMP, CRAB, FISH, CALAMARI };

class Penguin : public Animal
{
private:
    
    eSeaFood favoriteFood;
    Penguin(const Penguin& penguin);
    const Penguin& operator=(const Penguin& penguin);

public:
    
	Penguin(const char *name, float weight, int birthYear, eSeaFood favoriteFood);        
    
    inline eSeaFood getFavoriteFood() const;
    void setFavoriteFood(eSeaFood favoriteFood);
    
    friend ostream& operator<<(ostream& os, const Penguin& penguin);
    
};


#endif /* __PENGUIN_H */