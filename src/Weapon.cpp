#include "Weapon.h"

Weapon::Weapon()
{
	this->eDamageDice.ROLLS=0;
	this->eDamageDice.FACES=0;
	this->eDamageDice.MOD=0;
	this->iRange=0;
}
Weapon::~Weapon(){}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}
std::string Weapon::getTag()
{
	std::string s=getName();
	s+="<"+std::to_string(eDamageDice.ROLLS)+"D"+std::to_string(eDamageDice.FACES);
	eDamageDice.MOD>=0?
		s+="+"+std::to_string(eDamageDice.MOD):s+=std::to_string(eDamageDice.MOD);
	s+=">";
	return s;
}
