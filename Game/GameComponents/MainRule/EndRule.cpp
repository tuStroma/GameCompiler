#include "EndRule.h"

bool EndRule::existInMap(std::string player_class)
{
	return payoff_map.find(player_class) != payoff_map.end();
}

EndRule::EndRule(std::string rule_name, InstructionBlock* rule_condition, std::list<Payoff*> payoff_list, PlayersSet* players)
	: rule_name(rule_name), rule_condition(rule_condition), players(players)
{

	for (Payoff* payoff : payoff_list)
	{
		payoff_map[payoff->getClassName()] = payoff;
	}

	std::list<Player*> players_list = players->getPlayersList();
	for (Player* player : players_list)
	{
		if (!existInMap(player->getType()))
			std::cout << "Error: No payoff definition for player \"" << player->getType() << "\"\n";
	}
}

bool EndRule::Run()
{
	rule_condition->RunBlock();
	bool result = rule_condition->getReturnVariable()->getValueBool();

	if (result)
	{
		std::list<Player*> players_list = players->getPlayersList();
		for (Player* player : players_list)
		{
			std::string player_class = player->getType();
			if (existInMap(player_class))
			{
				players->setNextPlayer(player);
				Payoff* payoff = payoff_map.at(player->getType());
				payoff->sendPayoff(player);
			}
			else std::cout << "Execution Error: Not found player \"" << player_class << "\" in payoff list \n";
		}

		return true;
	}

	return false;
}
