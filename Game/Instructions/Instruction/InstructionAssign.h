#pragma once

#include "Instruction.h"
#include "Expression/ExpressionInt.h"

class InstructionAssign : public Instruction
{
protected:
	void* to;

	InstructionAssign(void* to);
};


class InstructionAssignInt : public InstructionAssign
{
private:
	ExpressionInt* expression;

public:
	InstructionAssignInt(void* to, ExpressionInt* expr);
	Instruction* Run() override;
};
