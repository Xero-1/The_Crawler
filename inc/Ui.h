#ifndef UI_H
#define UI_H

#include <locale.h>
#include <fstream>

#include "Post.h"
#include "Menu.h"
#include "Camera.h"
#include "Status.h"
#include "Roll.h"

class Ui
{
public:
	Ui();
	~Ui();
	//Functions
	inline Post& getPost(){return this->cPost;}
	inline Menu& getMenu(){return this->cMenu;}
	inline Camera& getCamera(){return this->cCamera;}
	inline Status& getStatus(){return this->cStatus;}
	void createNewCharacter();
	//Displayers info
	void displayInventory(std::string inventory);	
	//Screen manipulation
	void clearPart(WINDOW* win,unsigned int startY,unsigned int X,unsigned int endY,unsigned int endX);
	void printListStrings(WINDOW* win,unsigned int y,unsigned int x,std::string tittle,std::string list[],unsigned int size);
	//Inputs
	void makeTerminalNormal();
	void makeTerminalGame();
	std::string getString(WINDOW* win,unsigned int y,unsigned int x,std::string msg);
	bool getConfirmation(WINDOW* win,unsigned int y,unsigned int x,std::string msg);
	unsigned int getNumber(WINDOW* win,unsigned int y,unsigned int x,std::string msg);
private:
	Status cStatus;
	Post cPost;
	Menu cMenu;
	Camera cCamera;
};

#endif
