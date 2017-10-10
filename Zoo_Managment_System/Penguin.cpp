#include "Penguin.h"

const char* Penguin::eSeaFoodText[] = {"Shrimp", "Crab", "Fish", "Calamari"};

Penguin::Penguin(const char *name, float weight, int birthYear, eSeaFood favoriteFood) : 
									Animal(weight, birthYear, name), favoriteFood(favoriteFood){}

void Penguin::toOs(ostream& os) const
{
	os << ", Favorite food: " << eSeaFoodText[this->getFavoriteFood()];
}