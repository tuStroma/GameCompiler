#include "InstructionAssign.h"

InstructionAssign::InstructionAssign(void* to)
	: to(to)
{}

InstructionAssignInt::InstructionAssignInt(void* to, ExpressionInt* expr)
	: InstructionAssign(to), expression(expr)
{}

Instruction* InstructionAssignInt::Run()
{
	*(int*)to = expression->evaluate();
	return next;
}
