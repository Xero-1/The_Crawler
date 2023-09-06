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
