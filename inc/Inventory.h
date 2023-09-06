#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
	inline Item& operator[](unsigned int index){return *this->cItems[index];}
	void addItem(Item* newItem);
	void removeItem(unsigned int index);
	String to_string();
private:
	std::vector<Item*> cItems;
};

#endif
