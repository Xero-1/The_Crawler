#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <fstream>
#include "Weapon.h"

class Creature
{
public:
	Creature();
	~Creature();
	void save(std::ofstream& file);
	void load(std::ifstream& file);
	//Getters and setters
	inline std::string getName(){return this->sName;}
	inline float getHpMax(){return this->fHpMax;}
	inline float getHpCurrent(){return this->fHpCurrent;}
	inline virtual unsigned int getDefence(){return this->iDefence;}
	inline unsigned int getLevel(){return this->iLevel;}
	inline unsigned int getExp(){return this->iExp;}
	inline Weapon getWeapon(){return this->cWeapon;}
	inline unsigned int getPositionY(){return this->iPositionY;}
	inline unsigned int getPositionX(){return this->iPositionX;}
	inline void setName(std::string s){this->sName=s;}
	inline void setHpMax(float f){this->fHpMax=f;}
	inline void setHpCurrent(float f){this->fHpCurrent=f;}
	inline void setDefence(unsigned int i){this->iDefence=i;}
	inline void setLevel(unsigned int i){this->iLevel=i;}
	inline void setExp(unsigned int i){this->iExp=i;}
	inline void setWeapon(Weapon weapon){this->cWeapon=weapon;}
	inline void setPositionY(unsigned int positionY){this->iPositionY=positionY;}
	inline void setPositionX(unsigned int positionX){this->iPositionX=positionX;}
private:
	std::string sName;
	float fHpMax;
	float fHpCurrent;
	unsigned int iDefence;
	unsigned int iLevel;
	unsigned int iExp;
	Weapon cWeapon;
	unsigned int iPositionY;
	unsigned int iPositionX;
};

#endif
