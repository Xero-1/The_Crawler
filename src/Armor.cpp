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
std::string Armor::getTag()
{
	std::string s=getName();
	s+="<+"+std::to_string(iAC)+">";
	return s;
}
