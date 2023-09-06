#include "Game.h"

int main()
{
	Game game;
	game.init();
	while(game.getPlay())
	{
		game.menuMain();
		while(!game.getGameover())//Basic game loop
		{
			game.draw();
			game.input();
			game.update();
		}
	}
	game.exit();

	return 0;
}
