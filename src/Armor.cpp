#include "Armor.h"

Armor::Armor()
{
	this->iAC=0;
}
Armor::~Armor(){}

Armor* Armor::clone() const
{
	return new Armor(*this);
}
