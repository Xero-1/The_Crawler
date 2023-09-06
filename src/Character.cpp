#include "Character.h"

Character::Character(): Creature()
{
	this->sRace="";
	this->sProfession="";
	this->fMpMax=0;
	this->fMpCurrent=0;
	this->iMovement=0;
	for(int i=int(STATS::STRENGTH);i<int(STATS::MAX);i++)
		this->iStats[i]=0;
	for(int i=int(SKILLS::ALERT);i<int(SKILLS::MAX);i++)
		this->iSkills[i]=0;
	this->iAttack=0;
	this->iInstinct=0;
	this->iGold=0;
}
Character::~Character(){}

short int Character::getStatMOD(unsigned short int stat)
{
	short int mod=0;
	if(iStats[stat]<=3)
		mod=-2;
	else if(iStats[stat]>=4 && iStats[stat]<=6)
		mod=-1;
	else if(iStats[stat]>=7 && iStats[stat]<=14)
		mod=0;
	else if(iStats[stat]>=15 && iStats[stat]<=17)
		mod=1;
	else
		mod=2;
	return mod;
}
unsigned int Character::getDefence()
{
	return Creature::getDefence()+cArmor.getAC();
}
std::string Character::to_string()
{
	std::string s=
		getName()+"\n"+
		this->sRace+"\n"+
		this->sProfession+"\n"+
		std::to_string(getHpMax())+"\n"+
		std::to_string(getHpCurrent())+"\n"+
		std::to_string(this->fMpMax)+"\n"+
		std::to_string(this->fMpCurrent)+"\n"+
		std::to_string(this->iMovement)+"\n";
	for(int i=int(STATS::STRENGTH);i<int(STATS::MAX);i++)
		s+=std::to_string(this->iStats[i])+"\n";
	for(int i=int(SKILLS::ALERT);i<int(SKILLS::MAX);i++)
		s+=std::to_string(this->iSkills[i])+"\n";
	s+=std::to_string(getDefence())+"\n"+
		std::to_string(this->iAttack)+"\n"+
		std::to_string(this->iInstinct)+"\n"+
		std::to_string(this->iGold)+"\n"+
		std::to_string(getLevel())+"\n"+
		std::to_string(getExp())+"\n";
	return s;
}
void Character::save()
{
	std::ofstream file("Save.sav");
	Creature::save(file);
	file<<this->sRace<<"\n";
	file<<this->sProfession<<"\n";
	file<<this->fMpMax<<"\n";
	file<<this->fMpCurrent<<"\n";
	file<<this->iMovement<<"\n";
	for(int i=int(STATS::STRENGTH);i<int(STATS::MAX);i++)
		file<<this->iStats[i]<<"\n";
	for(int i=int(SKILLS::ALERT);i<int(SKILLS::MAX);i++)
		file<<this->iSkills[i]<<"\n";
	file<<this->iAttack<<"\n";
	file<<this->iInstinct<<"\n";
	file<<this->iGold<<"\n";
	file.close();
}
void Character::load()
{
	std::ifstream save("Save.sav");
	if(save.is_open())
	{
		Creature::load(save);
		save.ignore();
		getline(save,sRace);
		getline(save,sProfession);
		save>>fMpMax;
		save>>fMpCurrent;
		save>>iMovement;
		for(int i=int(STATS::STRENGTH);i<int(STATS::MAX);i++)
			save>>iStats[i];
		for(int i=int(SKILLS::ALERT);i<int(SKILLS::MAX);i++)
			save>>iSkills[i];
		save>>iAttack;
		save>>iInstinct;
		save>>iGold;
		save.close();
	}
}
