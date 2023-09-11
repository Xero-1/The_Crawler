#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor: public Item
{
public:
	Armor();
	~Armor();
	Armor* clone()const;
	std::string getTag() override;
	//Getters and setters
	inline unsigned short int getAC(){return this->iAC;}
	inline void setAC(unsigned short int i){this->iAC=i;}
private:
	unsigned short int iAC;
};

#endif
