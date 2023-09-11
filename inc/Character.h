#ifndef CHARACTER_H
#define CHARACTER_H

#include "Roll.h"
#include "Creature.h"
#include "Armor.h"
#include "Inventory.h"

enum class STATS
{
	STRENGTH=0,
	DEXTERITY,
	CONSTITUTION,
	INTELLIGENCE,
	WISDOM,
	CHARISMA,
	MAX
};
enum class SKILLS
{
	ALERT=0,
	COMMUNICATION,
	HANDLING,
	SCHOLAR,
	QUIBBLE,
	SURVIVAL,
	MAX
};

class Character: public Creature
{
public:
	Character();
	~Character();
	//Functions
	short int getStatMOD(unsigned short int stat);
	unsigned int getDefence() override;
	std::string to_string();
	void save();
	void load();
	//Getters and setters
	inline std::string getRace(){return this->sRace;}
	inline std::string getProfession(){return this->sProfession;}
	inline float getMpMax(){return this->fMpMax;}
	inline float getMpCurrent(){return this->fMpCurrent;}
	inline int getMovement(){return this->iMovement;}
	inline unsigned short int* getStats(){return this->iStats;}
	inline unsigned short int* getSkills(){return this->iSkills;}
	inline unsigned int getAttack(){return this->iAttack;}
	inline unsigned int getInstinct(){return this->iInstinct;}
	inline unsigned int getGold(){return this->iGold;}
	inline Armor getArmor(){return this->cArmor;}
	inline Inventory& getInv(){return this->cInv;}
	inline void setRace(std::string s){this->sRace=s;}
	inline void setProfession(std::string s){this->sProfession=s;}
	inline void setMpMax(float f){this->fMpMax=f;}
	inline void setMpCurrent(float f){this->fMpCurrent=f;}
	inline void setMovement(int i){this->iMovement=i;}
	inline void setStat(unsigned short int stat,unsigned short int i){this->iStats[stat]=i;}
	inline void setSkill(unsigned short int skill,unsigned short int i){this->iSkills[skill]=i;}
	inline void setAttack(unsigned int i){this->iAttack=i;}
	inline void setInstinct(unsigned int i){this->iInstinct=i;}
	inline void setGold(unsigned int i){this->iGold=i;}
	inline void setArmor(Armor armor){this->cArmor=armor;}
private:
	std::string sRace;
	std::string sProfession;
	float fMpMax;
	float fMpCurrent;
	unsigned int iMovement;
	unsigned short int iStats[6];
	unsigned short int iSkills[6];
	unsigned int iAttack;
	unsigned int iInstinct;
	unsigned int iGold;
	Armor cArmor;
	Inventory cInv;
};

#endif
