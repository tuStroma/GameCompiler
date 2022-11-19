#include "Game.h"


Game::Game()
{}

void Game::setPlayers(PlayersSet * players)
{
	this->players = players;
}

void Game::print()
{
	players->print();
	std::cout << '\n';

	state->print();
}
