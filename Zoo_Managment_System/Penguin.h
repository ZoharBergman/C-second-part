//
//  Penguin.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright � 2017 Almog Segal. All rights reserved.
//

#ifndef __PENGUIN_H
#define __PENGUIN_H

#include "Animal.h"

class Penguin : public Animal
{
public:
	const static enum eSeaFood { SHRIMP, CRAB, FISH, CALAMARI };
	const static char* eSeaFoodText[];

private:
    
    eSeaFood favoriteFood;
    Penguin(const Penguin& penguin);
    const Penguin& operator=(const Penguin& penguin);

public:
    
	Penguin(const char *name, float weight, int birthYear, eSeaFood favoriteFood);        
    
	inline eSeaFood getFavoriteFood() const { return favoriteFood; }
	void setFavoriteFood(eSeaFood favoriteFood) { this->favoriteFood = favoriteFood; }
    
    virtual void toOs(ostream& os) const;
    
};


#endif /* __PENGUIN_H */