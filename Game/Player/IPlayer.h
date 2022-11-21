#pragma once

#include <string>
#include "../DataSet/DataSet.h"

class IPlayer
{
public:
	std::string makeMove(DataSet* move_data, DataSet* state_data);
};

