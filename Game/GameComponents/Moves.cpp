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

std::unordered_map<std::string, DataSet*> Moves::getMovesDataMap()
{
	std::unordered_map<std::string, DataSet*> moves_map;

	for (std::pair<const std::string, Move*>& kv : moves)
	{
		const std::string& name = kv.first;
		Move* move = kv.second;

		moves_map[name] = move->getMoveData();
	}

	return moves_map;
}

bool Moves::makeMove(std::string move_name)
{
	if (!existsInMap(move_name))
	{
		std::cout << "Execution warning: Move \"" << move_name << "\" does not exist\n";
		return false;
	}
	
	return moves.at(move_name)->makeMove();
}
