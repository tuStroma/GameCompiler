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

InstructionAssignBool::InstructionAssignBool(void* to, ExpressionBool* expr)
	: InstructionAssign(to), expression(expr)
{}

Instruction* InstructionAssignBool::Run()
{
	*(bool*)to = expression->evaluate();
	return next;
}
