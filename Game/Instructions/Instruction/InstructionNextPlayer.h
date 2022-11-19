#pragma once

#include "../../Player/Player.h"
#include "Instruction.h"
#include "Expression/ExpressionInt.h"

//
class InstructionNextPlayer : public Instruction
{
private:
	PlayersSet* players;
	
	std::string player_type;
	ExpressionInt* player_id;

public:
	InstructionNextPlayer(PlayersSet* players, std::string type, ExpressionInt* id_expr);
	Instruction* Run() override;
};
//*/
