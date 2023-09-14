#ifndef POST_H
#define POST_H

#include <string>
#include <vector>
#include <ncurses.h>

class Post
{
public:
	Post();
	~Post();
	//Functions
	void reset();
	void addPost(std::string text,unsigned short int color=0);
	void display();
	//Getters and setters
	inline WINDOW* getWindow(){return this->win;}
	inline void setWindow(WINDOW* w){this->win=w;}
private:
	std::vector<unsigned short int> postsColor;
	std::vector<std::string> postsText;
	WINDOW* win;
};

#endif
