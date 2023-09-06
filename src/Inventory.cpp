#include "Inventory.h"

Inventory::Inventory(){}
Inventory::~Inventory()
{
	while(!cItems.empty())
		removeItem(0);
}

void Inventory::addItem(Item* newItem)
{
	this->cItems.push_back(newItem);
}
void Inventory::removeItem(unsigned int index)
{
	delete this->cItems[index];
	this->cItems.erase(cItems.begin()+index);
}
String Inventory::to_string()
{
	std::string s=std::to_string(cItems.size())+"\n";
	return s;
}
