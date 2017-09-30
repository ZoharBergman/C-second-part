#include "Lion.h"

Lion::Lion(const char *name, float weight, int birthYear, eManeColor maneColor) :
								Animal(weight, birthYear, name), maneColor(maneColor){}

void Lion::toOs(ostream& os) const
{
	os << ", Mane color: " << eManeColorText[this->getManeColor()];
}