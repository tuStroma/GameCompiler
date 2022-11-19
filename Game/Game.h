#pragma once
#include "DataSet/DataSet.h"
#include "Player/Player.h"
#include "Instructions/InstructionBlock.h"
#include "GameComponents/State.h"

class Game
{
private:
	PlayersSet* players;
	State* state;


public:
	Game();

	void setPlayers(PlayersSet* players);

	void print();
};

