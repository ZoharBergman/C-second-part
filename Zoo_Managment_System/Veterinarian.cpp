#include "Veterinarian.h"

Veterinarian::Veterinarian(const char *name, int salary, int yearsOfExperience, Area* area) : 
	Worker(name, salary, area), yearsOfExperience(yearsOfExperience){};

void Veterinarian::toOs(ostream& os) const
{
	os << ", Years of experience: " << this->getYearsOfExperience();
}