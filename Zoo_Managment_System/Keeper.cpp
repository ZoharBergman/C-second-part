#include "Keeper.h"

Keeper::Keeper(const char *name, int salary, eAnimal specialty, Area* area) : Worker(name, salary, area), specialty(specialty) {};

ostream& operator<<(ostream& os, const Keeper& keeper)
{
	os << (Worker&)keeper << ", Speciality: " << eAnimalsNames[keeper.getSpecialty()];
	return os;
}