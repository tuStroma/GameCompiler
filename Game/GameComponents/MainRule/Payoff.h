#pragma once

#include <string>
#include "../../Instructions/InstructionBlock.h"

class Payoff
{
private:
	std::string player_class;
	InstructionBlock* payoff;

public:
	Payoff(std::string player_class, InstructionBlock* payoff);

	void sendPayoff(Player* player);

	std::string getClassName();
};

