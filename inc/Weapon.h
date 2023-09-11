#ifndef WEAPON_H
#define WEAPON_H

#include "Roll.h"
#include "Item.h"

class Weapon: public Item
{
public:
	Weapon();
	~Weapon();
	Weapon* clone()const;
	std::string getTag() override;
	//Getters and setters
	inline Dice getDamageDice(){return this->eDamageDice;}
	inline unsigned short int getRange(){return this->iRange;}
	inline void setDamageDice(Dice e){this->eDamageDice=e;}
	inline void setRange(unsigned short int i){this->iRange=i;}
private:
	Dice eDamageDice;
	unsigned short int iRange;
};

#endif
