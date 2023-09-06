#ifndef UI_H
#define UI_H

#include <locale.h>
#include <ncurses.h>
#include <string>
#include <fstream>
#include <vector>

#include "Roll.h"

enum class MY_COLORS
{
	RED=1,
	BLUE,
	YELLOW
};
struct Post
{
	std::string TEXT;
	unsigned short int COLOR;
};

class Ui
{
public:
	Ui();
	~Ui();
	//Functions
	void createNewCharacter();
	//Posts system
	void addPost(std::string text,unsigned short int color=0);
	//Menus
	char menuStart();
	char menuPause();
	//Displayers info
	void displayStatus(std::string character);
	void displayStats(WINDOW* win,unsigned int y,unsigned int x,unsigned short int stats[]);
	void displaySkills(WINDOW* win,unsigned int y,unsigned int x,unsigned short int skills[]);
	void displayPosts();
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
	WINDOW* winPost;
	std::vector<Post> ePosts;
};

#endif
