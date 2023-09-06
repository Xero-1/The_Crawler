#ifndef GAME_H
#define GAME_H

#include <ctime>
#include "Ui.h"
#include "Character.h"

class Game
{
public:
	Game();
	~Game();
	//Functions
	void init();
	void menuMain();
	void draw();
	void input();
	void update();
	void exit();
	void newgame();
	//Getters and setters
	inline bool getPlay(){return this->bPlay;}
	inline bool getGameover(){return this->bGameover;}
private:
	bool bPlay;
	bool bGameover;
	Character cPlayer;
	Ui cUi;
};

#endif
