#include <iostream>

#include "Game/Compiler.h"



int main(int argc, char* argv[])
{

	Game* game = Compiler().createGame("Source/source.txt");
	//game->setPlayer(new IPlayer(), "player", 3);
	//game->startGame();

	return 0;
}