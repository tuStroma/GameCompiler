#include "Game.h"

Game::Game(PlayersSet* players, State* state, MainRule* main_rule, Moves* moves)
	: players(players), state(state), main_rule(main_rule), moves(moves)
{
	state_data = state->getData();

	moves_map = moves->getMovesDataMap();
}

void Game::setPlayer(IPlayer* i_player, std::string player_class, int player_id)
{
	players->setPlayer(i_player, player_class, player_id);
}

void Game::startGame()
{
	state->setupState();

	bool finished = false;
	while (!finished)
	{
		nextMove();
		finished = main_rule->Run();
	}
}

void Game::nextMove()
{
	while (true)
	{
		std::string move_name = players->makeMove(state_data, moves_map);
		if (moves->makeMove(move_name))	// Break if valid move was executed
			break;
	}

}

void Game::print()
{
	players->print();
	std::cout << '\n';

	state->print();
}
