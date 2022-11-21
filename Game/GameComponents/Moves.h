#pragma once

#include <unordered_map>
#include "Moves/Move.h"

class Moves
{
private:
	std::unordered_map<std::string, Move*> moves;

	bool existsInMap(std::string move_name);

public:
	Moves(std::list<Move*> moves);

	DataSet* getMoveData(std::string move_name);
};

