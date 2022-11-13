#pragma once

#include "Instruction.h"
#include "Expression/ExpressionBool.h"

class InstructionConditionalJump : public Instruction
{
private:
	Instruction* if_true;
	ExpressionBool* condition;

public:
	InstructionConditionalJump(ExpressionBool* condition, Instruction* if_true);

	Instruction* Run() override;
};

