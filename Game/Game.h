#pragma once
#include "DataSet/DataSet.h"
#include "Instructions/InstructionBlock.h"

class Game
{
private:
	DataSet* state;

public:
	Game(DataSet* state);
};

