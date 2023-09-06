#include "Creature.h"

Creature::Creature()
{
	this->sName="";
	this->fHpMax=0;
	this->fHpCurrent=0;
	this->iDefence=0;
	this->iLevel=0;
	this->iExp=0;
}
Creature::~Creature(){}

void Creature::save(std::ofstream& file)
{
	file<<this->sName<<"\n";
	file<<this->fHpMax<<"\n";
	file<<this->fHpCurrent<<"\n";
	file<<this->iDefence<<"\n";
	file<<this->iLevel<<"\n";
	file<<this->iExp<<"\n";
}
void Creature::load(std::ifstream& file)
{
	getline(file,sName);
	file>>fHpMax;
	file>>fHpCurrent;
	file>>iDefence;
	file>>iLevel;
	file>>iExp;
}
