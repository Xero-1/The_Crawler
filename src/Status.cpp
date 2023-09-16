#include "Status.h"

Status::Status(){}
Status::~Status()
{
	delwin(win);
}

//Functions
void Status::display()
{
	wclear(win);
	mvwprintw(win,0,1,pCharacter->getName().c_str());
	mvwprintw(win,1,1,"%s - %s",pCharacter->getRace().c_str(),pCharacter->getProfession().c_str());
	mvwprintw(win,5,1,"MOV=%d",pCharacter->getMovement());
	mvwprintw(win,5,16,"INS=%d",pCharacter->getInstinct());
	mvwprintw(win,7,1,"ARMA=%s",pCharacter->getWeapon().getTag().c_str());
	//COLOR YELLOW
	wattron(win,COLOR_PAIR(int(MY_COLORS::YELLOW)));
	mvwprintw(win,2,1,"NIVEL=%d",pCharacter->getLevel());
	mvwprintw(win,2,10,"PE=%d",pCharacter->getExp());
	wattron(win,A_REVERSE);
	mvwprintw(win,2,16,"ORO=%d",pCharacter->getGold());
	wattroff(win,A_REVERSE);
	wattroff(win,COLOR_PAIR(int(MY_COLORS::YELLOW)));
	//COLOR RED
	wattron(win,COLOR_PAIR(int(MY_COLORS::BLUE)));
	mvwprintw(win,3,1,"PV=%d/%d",int(pCharacter->getHpCurrent()),int(pCharacter->getHpMax()));
	wattron(win,A_REVERSE);
	mvwprintw(win,4,1,"ATQ=%d",pCharacter->getAttack());
	wattroff(win,A_REVERSE);
	wattroff(win,COLOR_PAIR(int(MY_COLORS::BLUE)));
	//COLOR BLUE
	wattron(win,COLOR_PAIR(int(MY_COLORS::BLUE)));
	mvwprintw(win,3,16,"POD=%d/%d",int(pCharacter->getMpCurrent()),int(pCharacter->getMpMax()));
	wattron(win,A_REVERSE);
	mvwprintw(win,4,16,"DEF=%d",pCharacter->getDefence());
	wattroff(win,A_REVERSE);
	wattroff(win,COLOR_PAIR(int(MY_COLORS::BLUE)));
	//ADDING SOME LINES
	mvwvline(win,0,0,ACS_VLINE,getmaxy(win));
	mvwhline(win,8,1,ACS_HLINE,getmaxx(win));
	mvwhline(win,16,1,ACS_HLINE,getmaxx(win));
	
	displayStats(win,8,2);
	displaySkills(win,16,2);
	
	wrefresh(win);
}
void Status::displayStats(WINDOW* w,unsigned int y,unsigned int x)
{
	std::string statsNames[]={"Fuerza","Destreza","Constitución","Inteligencia","Sabiduría","Carisma"};
	mvwprintw(win,y,x,"ATRIBUTOS");
	short int mod=0;
	for(int i=0;i<6;i++)
	{
		mvwprintw(w,y+1+i,x,"%d]%s",i+1,statsNames[i].c_str());
		if(pCharacter->getStats()[i]<=3)
			mod=-2;
		else if(pCharacter->getStats()[i]>=4 && pCharacter->getStats()[i]<=6)
			mod=-1;
		else if(pCharacter->getStats()[i]>=7 && pCharacter->getStats()[i]<=14)
			mod=0;
		else if(pCharacter->getStats()[i]>=15 && pCharacter->getStats()[i]<=17)
			mod=1;
		else
			mod=2;
		mvwprintw(w,y+1+i,x+21,"%d",pCharacter->getStats()[i]);
		mvwprintw(w,y+1+i,x+24,"<");
		mod<0?
			mvwprintw(w,y+1+i,x+25,"%d>",mod) : mvwprintw(w,y+1+i,x+25,"+%d>",mod);
	}
	
	wrefresh(w);
}
void Status::displaySkills(WINDOW* w,unsigned int y,unsigned int x)
{
	std::string skillsNames[]={"Alerta","Comunicación","Manipulación","Erudición","Subterfugio","Supervivencia"};
	mvwprintw(w,y,x,"HABILIDADES");
	for(int i=0;i<6;i++)
	{
		mvwprintw(w,y+1+i,x,"%d]%s",i+1,skillsNames[i].c_str());
		mvwprintw(w,y+1+i,x+21,"%d",pCharacter->getSkills()[i]);
	}
	wrefresh(w);
}
