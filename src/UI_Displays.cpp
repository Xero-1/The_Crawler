#include "Ui.h"

//Screen manipulation
void Ui::clearPart(WINDOW* win,unsigned int startY,unsigned int startX,unsigned int endY,unsigned int endX)
{
	for(int i=startY;i<=endY;i++)
		for(int j=startX;j<=endX;j++)
			mvwaddch(win,i,j,' ');
	wrefresh(win);
}
void Ui::printListStrings(WINDOW* win,unsigned int y,unsigned int x,std::string tittle,std::string list[],unsigned int size)
{
	mvwprintw(win,y,x,tittle.c_str());
	for(int i=0;i<size;i++)
		mvwprintw(win,y+1+i,x,"%d]%s",i+1,list[i].c_str());
	wrefresh(win);
}
//Displayers inf
void Ui::displayStats(WINDOW* win,unsigned int y,unsigned int x,unsigned short int stats[])
{
	std::string statsNames[]={"Fuerza","Destreza","Constitución","Inteligencia","Sabiduría","Carisma"};
	printListStrings(win,y,x,"ATRIBUTOS",statsNames,6);
	short int mod=0;
	for(int i=0;i<6;i++)
	{
		if(stats[i]<=3)
			mod=-2;
		else if(stats[i]>=4 && stats[i]<=6)
			mod=-1;
		else if(stats[i]>=7 && stats[i]<=14)
			mod=0;
		else if(stats[i]>=15 && stats[i]<=17)
			mod=1;
		else
			mod=2;
		mvwprintw(win,y+1+i,x+21,"%d",stats[i]);
		mvwprintw(win,y+1+i,x+24,"<");
		mod<0?
			mvwprintw(win,y+1+i,x+25,"%d>",mod) : mvwprintw(win,y+1+i,x+25,"+%d>",mod);
	}
	wrefresh(win);
}
void Ui::displaySkills(WINDOW* win,unsigned int y,unsigned int x,unsigned short int skills[])
{
	std::string skillsNames[]={"Alerta","Comunicación","Manipulación","Erudición","Subterfugio","Supervivencia"};
	printListStrings(win,y,x,"HABILIDADES",skillsNames,6);
	for(int i=0;i<6;i++)
	{
		mvwprintw(win,y+1+i,x+21,"%d",skills[i]);
	}
	wrefresh(win);
}
void Ui::displayInventory(std::string inventory)
{
	unsigned int size=std::stoi(inventory.substr(0,inventory.find('\n')));
	inventory.erase(0,inventory.find('\n')+1);
	if(!size)
	{
		addPost("Tu inventario esta vacio.");
	}else
	{
		addPost("Inventario:");
		for(int i=0;i<size;i++)
		{
			addPost(std::to_string(i+1)+"]"+inventory.substr(0,inventory.find('\n')));
			inventory.erase(0,inventory.find('\n')+1);
		}
	}	
}
void Ui::displayStatus(std::string character)
{
	std::string name=character.substr(0,character.find('\n'));
	character.erase(0,character.find('\n')+1);
	std::string race=character.substr(0,character.find('\n'));
	character.erase(0,character.find('\n')+1);
	std::string profession=character.substr(0,character.find('\n'));
	character.erase(0,character.find('\n')+1);
	float hpMax=std::stof(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	float hpCurrent=std::stof(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	float mpMax=std::stof(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	float mpCurrent=std::stof(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	unsigned int movement=std::stoi(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	unsigned short int stats[6];
	for(int i=0;i<6;i++)
	{
		stats[i]=std::stoi(character.substr(0,character.find('\n')));
		character.erase(0,character.find('\n')+1);
	}
	unsigned short int skills[6];
	for(int i=0;i<6;i++)
	{
		skills[i]=std::stoi(character.substr(0,character.find('\n')));
		character.erase(0,character.find('\n')+1);
	}
	unsigned int defence=std::stoi(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	unsigned int attack=std::stoi(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	unsigned int instinct=std::stoi(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	unsigned int gold=std::stoi(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	unsigned int level=std::stoi(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);
	unsigned int exp=std::stoi(character.substr(0,character.find('\n')));
	character.erase(0,character.find('\n')+1);

	wclear(winStatus);
	//color normal
	mvwprintw(winStatus,0,1,name.c_str());
	mvwprintw(winStatus,1,1,"%s - %s",race.c_str(),profession.c_str());
	mvwprintw(winStatus,5,1,"MOV=%d",movement);
	mvwprintw(winStatus,5,16,"INS=%d",instinct);
	mvwprintw(winStatus,7,1,"ARMA=");
	//color yellow
	wattron(winStatus,COLOR_PAIR(int(MY_COLORS::YELLOW)));
	mvwprintw(winStatus,2,1,"NIVEL=%d",level);
	mvwprintw(winStatus,2,10,"PE=%d",exp);
	wattron(winStatus,A_REVERSE);
	mvwprintw(winStatus,2,16,"ORO=%d",gold);
	wattroff(winStatus,A_REVERSE);
	wattroff(winStatus,COLOR_PAIR(int(MY_COLORS::YELLOW)));
	//color red
	wattron(winStatus,COLOR_PAIR(int(MY_COLORS::RED)));
	mvwprintw(winStatus,3,1,"PV=%d/%d",int(hpCurrent),int(hpMax));
	wattron(winStatus,A_REVERSE);
	mvwprintw(winStatus,4,1,"ATQ=%d",attack);
	wattroff(winStatus,A_REVERSE);
	wattroff(winStatus,COLOR_PAIR(int(MY_COLORS::RED)));
	//color blue
	wattron(winStatus,COLOR_PAIR(int(MY_COLORS::BLUE)));
	mvwprintw(winStatus,3,16,"POD=%d/%d",int(mpCurrent),int(mpMax));
	wattron(winStatus,A_REVERSE);
	mvwprintw(winStatus,4,16,"DEF=%d",defence);
	wattroff(winStatus,A_REVERSE);
	wattroff(winStatus,COLOR_PAIR(int(MY_COLORS::BLUE)));
	//Adding some lines
	mvwvline(winStatus,0,0,ACS_VLINE,getmaxy(winStatus));
	mvwhline(winStatus,8,1,ACS_HLINE,getmaxx(winStatus));
	mvwhline(winStatus,16,1,ACS_HLINE,getmaxx(winStatus));
	
	displayStats(winStatus,8,2,stats);
	displaySkills(winStatus,16,2,skills);
	wrefresh(winStatus);
}
