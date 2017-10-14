#include "Keeper.h"

const char* Keeper::ANIMALS_NAMES[] = {"Lion", "Penguin", "Elephant", "Giraffe", "Zebra", "Horse", "Zebroid"};

Keeper::Keeper(const char *name, int salary, eAnimal specialty, Area* area) : Worker(name, salary, area), specialty(specialty) {};

void Keeper::toOs(ostream& os) const
{
	os << ", Speciality: " << ANIMALS_NAMES[this->getSpecialty()];
}