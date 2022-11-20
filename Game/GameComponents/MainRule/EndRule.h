#pragma once

#include <string>
#include <unordered_map>
#include "Payoff.h"
#include "../../Instructions/InstructionBlock.h"

class EndRule
{
private:
	std::string rule_name;
	InstructionBlock* rule_condition;
	std::unordered_map<std::string, Payoff*> payoff_map;

	PlayersSet* players;

	bool existInMap(std::string player_class);

public:
	EndRule(std::string rule_name, InstructionBlock* rule_condition, std::list<Payoff*> payoff_list, PlayersSet* players);

	bool Run();
};

