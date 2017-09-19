#include "Veterinarian.h"

Veterinarian::Veterinarian(const char *name, int salary, const Area* area, int yearsOfExperience) : 
												Worker(name, salary, area), yearsOfExperience(yearsOfExperience){};

ostream& operator<<(ostream& os, const Veterinarian& veterinarian)
{
	os << (Worker&)veterinarian << ", Years of experience: " << veterinarian.getYearsOfExperience();
	return os;
}