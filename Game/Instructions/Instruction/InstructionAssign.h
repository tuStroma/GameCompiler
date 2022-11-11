#pragma once

#include "Instruction.h"
#include "Expression/ExpressionInt.h"
#include "Expression/ExpressionBool.h"

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

class InstructionAssignBool : public InstructionAssign
{
private:
	ExpressionBool* expression;

public:
	InstructionAssignBool(void* to, ExpressionBool* expr);
	Instruction* Run() override;
};
