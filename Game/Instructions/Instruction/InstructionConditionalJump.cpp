#include "InstructionConditionalJump.h"

InstructionConditionalJump::InstructionConditionalJump(ExpressionBool* condition, Instruction* if_true)
	: condition(condition), if_true(if_true)
{}

Instruction* InstructionConditionalJump::Run()
{
	bool result = condition->evaluate();
	if (result)
		return if_true;

	return next;
}
