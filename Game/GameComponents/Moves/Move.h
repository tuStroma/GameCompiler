#pragma once

#include <string>
#include <list>

#include"../../Instructions/InstructionBlock.h"

class Move
{
private:
	std::string name;
	std::list<std::string> players_scope;

	DataSet* move_data;
	InstructionBlock* validation;
	InstructionBlock* move_execution;

public:
	Move(std::string name, std::list<std::string> players_scope, DataSet* move_data, InstructionBlock* validation, InstructionBlock* move_execution);

};

