#include "Payoff.h"

Payoff::Payoff(std::string player_class, InstructionBlock* payoff)
	: player_class(player_class), payoff(payoff)
{}

void Payoff::sendPayoff(Player * player)
{
	payoff->RunBlock();
	int result = payoff->getReturnVariable()->getValueInt();
	player->setPayoff(result);
}

std::string Payoff::getClassName()
{
	return player_class;
}
