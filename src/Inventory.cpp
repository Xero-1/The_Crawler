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
std::string Inventory::to_string()
{
	std::string s=std::to_string(cItems.size())+"\n";
	for(int i=0;i<cItems.size();i++)
		s+=cItems[i]->getTag()+"\n";
	return s;
}
