#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ITEM_TYPES
{
	ARMOR=1,
	WEAPON
};
class Item
{
public:
	Item();
	~Item();
	virtual Item* clone()const=0;
	inline virtual std::string getTag(){return "";};
	//Getters and setters
	inline std::string getName(){return this->sName;}
	inline unsigned short int getType(){return this->iType;}
	inline unsigned int getValue(){return this->iValue;}
	inline void setName(std::string s){this->sName=s;}
	inline void setType(unsigned short int i){this->iType=i;}
	inline void setValue(unsigned int i){this->iValue=i;}
private:
	std::string sName;
	unsigned short int iType;
	unsigned int iValue;
};

#endif
