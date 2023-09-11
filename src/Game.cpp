#include "Game.h"

Game::Game()
{
	this->bPlay=false;
	this->bGameover=false;
}
Game::~Game(){}

void Game::init()
{
	this->bPlay=true;
	this->bGameover=true;
	srand(time(NULL));

	Weapon w;
	w.setName("Espada corta");
	Dice d;
	d.ROLLS=3;
	d.FACES=6;
	d.MOD=1;
	w.setDamageDice(d);
	cPlayer.getInv().addItem(w.clone());
	Armor a;
	a.setName("Armadura de placas");
	a.setAC(6);
	cPlayer.getInv().addItem(a.clone());
}
void Game::menuMain()
{
	clear();
	refresh();
	switch(cUi.menuStart())
	{
		case '1':
			newgame();
			break;
		case '2':
			this->bGameover=false;
			cUi.addPost("<Partida cargada>");
			cPlayer.load();
			break;
		case '3':
			this->bPlay=false;
			break;
	}
}
void Game::draw()
{
	clear();
	refresh();
	cUi.displayStatus(cPlayer.to_string());
	cUi.displayPosts();
}
void Game::input()
{
	switch(getch())
	{
		case 'q':
		case 'Q':
			this->bGameover=true;
			break;
		case 'i':
		case 'I':
			cUi.displayInventory(cPlayer.getInv().to_string());
			break;
		case 27://Esc
			cPlayer.save();
			break;
	}
}
void Game::update()
{}
void Game::exit()
{
	clear();
	mvprintw(getmaxy(stdscr)/2-1,getmaxx(stdscr)/2-4,"Good bye");
	refresh();
	getch();
}
void Game::newgame()
{
	this->bGameover=false;
	cUi.createNewCharacter();
	cPlayer.load();
	cUi.addPost("Estas vivo.");
}
