#pragma once

#include "Instruction.h"
#include "Expression/ExpressionInt.h"

class InstructionAssign : public Instruction
{
protected:
	void* to;
};


class InstructionAssignInt : public InstructionAssign
{
private:
	ExpressionInt* expression;

public:
	Instruction* Run() override;
};
