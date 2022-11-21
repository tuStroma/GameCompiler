#pragma once

#include <string>
#include "../DataSet/DataSet.h"

class IPlayer
{
public:
	virtual std::string makeMove(DataSet* state_data, std::unordered_map<std::string, DataSet*> moves_map);
	virtual void Payoff(int payoff);
};

