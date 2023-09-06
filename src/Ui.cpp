#include "Ui.h"

Ui::Ui()
{
	setlocale(LC_ALL,"");
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);
	curs_set(FALSE);
	refresh();
	start_color();
	init_pair(int(MY_COLORS::RED),COLOR_RED,COLOR_BLACK);
	init_pair(int(MY_COLORS::BLUE),COLOR_BLUE,COLOR_BLACK);
	init_pair(int(MY_COLORS::YELLOW),COLOR_YELLOW,COLOR_BLACK);
	refresh();
	this->winStatus=newwin(getmaxy(stdscr),30,0,getmaxx(stdscr)-30);
	this->winPost=newwin(getmaxy(stdscr),getmaxx(stdscr)-30,0,0);
}
Ui::~Ui()
{
	delwin(winStatus);
}

//Functions
void Ui::createNewCharacter()
{
	std::string name="";
	std::string race="";
	std::string profession="";
	float hpMax=0;
	float hpCurrent=0;
	float mpMax=0;
	float mpCurrent=0;
	unsigned int movement=0;
	unsigned short int stats[6]={0};
	unsigned short int skills[6]={0};
	unsigned int defence=0;
	unsigned int attack=0;
	unsigned int instinct=0;
	unsigned int gold=0;
	unsigned int level=0;
	unsigned int exp=0;

	box(stdscr,0,0);
	mvprintw(0,1,"CREACIÓN DE PERSONAJE");
	name=getString(stdscr,1,1,"NOMBRE: ");
	/////STATS/////
	do
	{
		clearPart(stdscr,4,1,11,30);
		for(int i=0;i<6;i++)
			stats[i]=roll(3,6,0);
		displayStats(stdscr,3,1,stats);
	}while(getConfirmation(stdscr,11,1,"¿Tirar denuevo?y/n "));
	/////RACE/////
	std::string racesNames[]={"Elfo","Enano","Mediano","Humano"};
	printListStrings(stdscr,3,40,"RAZA:",racesNames,4);
	unsigned short int optRace;
	do
	{
		clearPart(stdscr,9,40,9,getmaxx(stdscr)-2);
		optRace=getNumber(stdscr,9,40,"Elección= ");
	}while(optRace>4 || optRace==0);
	race=racesNames[optRace-1];
	switch(optRace)
	{
		case 1:
			movement=12;
			break;
		case 2:
			movement=9;
			break;
		case 3:
			movement=9;
			break;
		case 4:
			movement=12;
			break;
	}
	/////PROFESSION/////
	std::string professionsNames[]={"Guerrero","Hechicero","Bribón"};
	printListStrings(stdscr,11,40,"CLASE:",professionsNames,3);
	unsigned short int optProfession;
	do
	{
		clearPart(stdscr,16,40,16,getmaxx(stdscr)-2);
		optProfession=getNumber(stdscr,16,40,"Elección= ");
	}while(optProfession>3 || optProfession==0);
	profession=professionsNames[optProfession-1];
	switch(optProfession)
	{
		case 1:
			hpMax=8;
			instinct=1;
			break;
		case 2:
			hpMax=4;
			mpMax=1;
			break;
		case 3:
			hpMax=6;
			break;
	}
	/////SKILLS/////
	unsigned short int skillPoints=4,optSkill;
	do
	{
		clearPart(stdscr,3,60,11,80);
		displaySkills(stdscr,3,60,skills);
		optSkill=getNumber(stdscr,11,60,"Elección= ");
		if(optSkill!=0 && optSkill<=6)
		{
			optSkill--;
			if(skills[optSkill]<1)
			{
				skills[optSkill]=1;
				skillPoints--;
			}
		}
	}while(skillPoints);
	/////SETTING HP,MP,GOLD AND LEVEL/////
	if(stats[2]>14)//Check if the constitution MOD it's good
	{
		stats[2]==18?//Check how much
			hpMax+=2:hpMax+=1;
	}
	if(stats[3]>14)//Check if the intelligence MOD it's good
	{
		stats[3]==18?//Check how much
			mpMax+=2:mpMax+=1;
	}
	defence=10;
	if(stats[1]>14)//Check if the intelligence MOD it's good
	{
		stats[1]==18?//Check how much
			defence+=2:defence+=1;
	}
	hpCurrent=hpMax;
	mpCurrent=mpMax;
	gold=roll(3,6,0)*10;
	level=1;
	exp=0;

	std::ofstream file("Save.sav");
	file<<name<<"\n";//Creature save
	file<<hpMax<<"\n";
	file<<hpCurrent<<"\n";
	file<<defence<<"\n";
	file<<level<<"\n";
	file<<exp<<"\n";
	file<<race<<"\n";//Character save
	file<<profession<<"\n";
	file<<mpMax<<"\n";
	file<<mpCurrent<<"\n";
	file<<movement<<"\n";
	for(int i=0;i<6;i++)
		file<<stats[i]<<"\n";
	for(int i=0;i<6;i++)
		file<<skills[i]<<"\n";
	file<<attack<<"\n";
	file<<instinct<<"\n";
	file<<gold<<"\n";
	file.close();
}
//Menus
char Ui::menuStart()
{
	mvprintw(getmaxy(stdscr)-1,0,"Basado en las reglas de VIEJA ESCUELA:el juego de rol");
	WINDOW* win=newwin(8,22,getmaxy(stdscr)/2-4,getmaxx(stdscr)/2-11);
	box(win,0,0);
	mvwprintw(win,0,5,"THE CRAWLER");
	mvwprintw(win,1,3,"Crawl baby crawl");
	mvwprintw(win,3,1,"1]NUEVA PARTIDA");
	mvwprintw(win,4,1,"2]CARGAR PARTIDA");
	mvwprintw(win,5,1,"3]SALIR");
	wrefresh(win);
	delwin(win);
	return getch();
}
char Ui::menuPause()
{
	WINDOW* win=newwin(5,22,getmaxy(stdscr)/2-2,getmaxx(stdscr)/2-11);
	box(win,0,0);
	mvwprintw(win,0,6,"PAUSA");
	mvwprintw(win,1,1,"1]CONTINUAR");
	mvwprintw(win,2,1,"2]OPCIONES");
	mvwprintw(win,3,1,"3]SALIR");
	wrefresh(win);
	delwin(win);
	return getch();
}
//Displayers info
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
//Post system
void Ui::addPost(std::string text,unsigned short int color)
{
	Post p;
	p.COLOR=color;
	while(!text.empty())
	{
		p.TEXT=text.substr(0,getmaxx(winPost));
		p.COLOR=color;
		ePosts.push_back(p);
		text.erase(0,getmaxx(winPost));
		if(ePosts.size()>getmaxy(winPost)-1)
			ePosts.erase(ePosts.begin()+0);
	}

}
//Displayers info
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
void Ui::displayPosts()
{
	unsigned int size=ePosts.size();
	for(int i=0;i<size;i++)
	{
		wattron(winPost,COLOR_PAIR(ePosts[i].COLOR));
		mvwprintw(winPost,0+i,0,ePosts[i].TEXT.c_str());
		wattroff(winPost,COLOR_PAIR(ePosts[i].COLOR));
	}
	wrefresh(winPost);
}
//Inputs
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
