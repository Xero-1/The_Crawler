#ifndef UI_H
#define UI_H

#include <locale.h>
#include <fstream>

#include "Post.h"
#include "Menu.h"
#include "Camera.h"
#include "Roll.h"

enum class MY_COLORS
{
	RED=1,
	BLUE,
	YELLOW
};

class Ui
{
public:
	Ui();
	~Ui();
	//Functions
	inline Post& getPost(){return this->cPost;}
	inline Menu& getMenu(){return this->cMenu;}
	void createNewCharacter();
	//Camera system
	void displayCamera();
	//Displayers info
	void displayStatus(std::string character);
	void displayStats(WINDOW* win,unsigned int y,unsigned int x,unsigned short int stats[]);
	void displaySkills(WINDOW* win,unsigned int y,unsigned int x,unsigned short int skills[]);
	void displayInventory(std::string inventory);
	//Inputs
	void makeTerminalNormal();
	void makeTerminalGame();
	std::string getString(WINDOW* win,unsigned int y,unsigned int x,std::string msg);
	bool getConfirmation(WINDOW* win,unsigned int y,unsigned int x,std::string msg);
	unsigned int getNumber(WINDOW* win,unsigned int y,unsigned int x,std::string msg);	
	//Screen manipulation
	void clearPart(WINDOW* win,unsigned int startY,unsigned int X,unsigned int endY,unsigned int endX);
	void printListStrings(WINDOW* win,unsigned int y,unsigned int x,std::string tittle,std::string list[],unsigned int size);
private:
	WINDOW* winStatus;
	Post cPost;
	Menu cMenu;
	Camera cCamera;
};

#endif
