#include "Game.h"

Game::Game(PlayersSet* players, State* state, MainRule* main_rule, Moves* moves)
	: players(players), state(state), main_rule(main_rule), moves(moves)
{}

void Game::print()
{
	players->print();
	std::cout << '\n';

	state->print();
}
