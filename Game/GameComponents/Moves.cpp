#include "Moves.h"

bool Moves::existsInMap(std::string move_name)
{
	return moves.find(move_name) != moves.end();
}

Moves::Moves(std::list<Move*> moves)
{
	for (Move* move : moves)
	{
		this->moves[move->getMoveName()] = move;
	}
}

DataSet* Moves::getMoveData(std::string move_name)
{
	if (!existsInMap(move_name))
	{
		std::cout << "Execution Warning: Move \"" << move_name << "\" does not exist\n";
		return NULL;
	}

	return moves.at(move_name)->getMoveData();
}
