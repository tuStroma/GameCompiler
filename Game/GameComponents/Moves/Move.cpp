#include "Move.h"

Move::Move(std::string name, std::list<std::string> players_scope, DataSet* move_data, InstructionBlock* validation, InstructionBlock* move_execution)
	: name(name), players_scope(players_scope), move_data(move_data), validation(validation), move_execution(move_execution)
{}

std::string Move::getMoveName()
{
	return name;
}

DataSet* Move::getMoveData()
{
	return move_data;
}
