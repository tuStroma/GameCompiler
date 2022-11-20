#pragma once

#include "Moves/Move.h"

class Moves
{
private:
	std::list<Move*> moves;

public:
	Moves(std::list<Move*> moves);
};

