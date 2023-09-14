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
	this->cCamera.setWindow(newwin(getmaxy(stdscr)-6,getmaxx(stdscr)-30,0,0));
	this->cPost.setWindow(newwin(5,getmaxx(stdscr)-30,getmaxy(stdscr)-5,0));
}
Ui::~Ui()
{
	delwin(winStatus);
	endwin();
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
//Camera system
void Ui::displayCamera()
{
	box(this->cCamera.getWindow(),0,0);

	wrefresh(this->cCamera.getWindow());
}
