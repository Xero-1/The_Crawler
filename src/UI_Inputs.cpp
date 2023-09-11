#include "Ui.h"

void Ui::makeTerminalNormal()
{
	echo();
	curs_set(TRUE);
	refresh();
}
void Ui::makeTerminalGame()
{
	noecho();
	curs_set(FALSE);
	refresh();
}
std::string Ui::getString(WINDOW* win,unsigned int y,unsigned int x,std::string msg)
{
	makeTerminalNormal();
	char s[1024];

	mvwprintw(win,y,x,msg.c_str());
	wgetstr(win,s);
	makeTerminalGame();
	return s;
}
bool Ui::getConfirmation(WINDOW* win,unsigned int y,unsigned int x,std::string msg)
{
	makeTerminalNormal();
	bool b=false;
	char keyPressed;

	mvwprintw(win,y,x,msg.c_str());
	do
	{
		keyPressed=getch();
		if(keyPressed=='y' || keyPressed=='Y')
			b=true;
	}while(keyPressed!='y' && keyPressed!='Y' && keyPressed!='n' && keyPressed!='N');

	makeTerminalGame();
	return b;
}
unsigned int Ui::getNumber(WINDOW* win,unsigned int y,unsigned int x,std::string msg)
{
	makeTerminalNormal();
	unsigned int i=0;
	char keyPressed;
	std::string s;

	mvwprintw(win,y,x,msg.c_str());
	do
	{
		keyPressed=getch();
		if(keyPressed>=48 && keyPressed<58)
			s.push_back(keyPressed);
	}while(keyPressed!='\n');
	if(!s.empty())
		i=std::stoi(s);

	makeTerminalGame();
	return i;
}
