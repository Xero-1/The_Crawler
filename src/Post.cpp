#include "Post.h"

Post::Post(){}
Post::~Post()
{
	delwin(win);
}

//Functions
void Post::reset()
{
	this->postsColor.clear();
	this->postsText.clear();
}
void Post::addPost(std::string text,unsigned short int color)
{
	while(!text.empty())
	{
		this->postsColor.push_back(color);
		this->postsText.push_back(text.substr(0,getmaxx(win)));
		text.erase(0,getmaxx(win));
		if(postsColor.size()>getmaxy(win))
		{
			this->postsColor.erase(postsColor.begin()+0);
			this->postsText.erase(postsText.begin()+0);
		}
	}
}
void Post::display()
{
	mvhline(getmaxy(stdscr)-getmaxy(win)-1,0,ACS_HLINE,getmaxx(win));
	unsigned int size=postsColor.size();
	for(int i=0;i<size;i++)
	{
		wattron(win,COLOR_PAIR(postsColor[i]));
		mvwprintw(win,0+i,0,postsText[i].c_str());
		wattroff(win,COLOR_PAIR(postsColor[i]));
	}
	wrefresh(win);
}
