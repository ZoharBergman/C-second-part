#include "Zebra.h"

Zebra::Zebra(const char *name, float weight, int birthYear, int numOfStrips) : 
							Animal(weight, birthYear, name), numOfStrips(numOfStrips){}

void Zebra::toOs(ostream& os) const
{
	os << ", Number of strips: " << this->getNumOfStrips();
}