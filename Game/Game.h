#pragma once
#include "DataSet/DataSet.h"
#include "Player/Player.h"
#include "Instructions/InstructionBlock.h"
#include "GameComponents/State.h"
#include "GameComponents/MainRule.h"
#include "GameComponents/Moves.h"

class Game
{
private:
	PlayersSet* players;
	State* state;
	MainRule* main_rule;
	Moves* moves;

	// Helping structures
	DataSet* state_data;
	std::unordered_map<std::string, DataSet*> moves_map;

	void nextMove();

public:
	Game(PlayersSet* players, State* state, MainRule* main_rule, Moves* moves);

	void setPlayer(IPlayer* i_player, std::string player_class, int player_id);

	void startGame();

	void print();
};

