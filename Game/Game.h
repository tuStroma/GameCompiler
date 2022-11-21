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

public:
	Game(PlayersSet* players, State* state, MainRule* main_rule, Moves* moves);

	void print();
};

