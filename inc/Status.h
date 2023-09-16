#ifndef STATUS_H
#define STATUS_H

#include <ncurses.h>
#include "Character.h"

enum class MY_COLORS
{
	RED=1,
	BLUE,
	YELLOW
};

class Status
{
public:
	Status();
	~Status();
	//Functions
	void display();
	void displayStats(WINDOW* w,unsigned int y,unsigned int x);
	void displaySkills(WINDOW* w,unsigned int y,unsigned int x);
	//Getters and setters
	inline WINDOW* getWindow(){return this->win;}
	inline Character* getCharacter(){return this->pCharacter;}
	inline void setWindow(WINDOW* w){this->win=w;}
	inline void setCharacter(Character* p){this->pCharacter=p;}
private:
	WINDOW* win;
	Character* pCharacter;
};

#endif
