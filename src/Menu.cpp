#include "Menu.h"

Menu::Menu(){}
Menu::~Menu(){}

char Menu::start()
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
char Menu::pause()
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
