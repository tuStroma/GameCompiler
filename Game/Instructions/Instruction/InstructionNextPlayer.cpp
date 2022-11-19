#include "InstructionNextPlayer.h"
//
InstructionNextPlayer::InstructionNextPlayer(PlayersSet* players, std::string type, ExpressionInt* id_expr)
	: players(players), player_type(type), player_id(id_expr)
{}

Instruction* InstructionNextPlayer::Run()
{
	players->setNextPlayer(player_type, player_id->evaluate());
	return next;
}
//*/