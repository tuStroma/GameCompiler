#include "InstructionReturn.h"

InstructionReturn::InstructionReturn(Variable* return_var)
	: return_pointer(return_var->getValue())
{}

InstructionReturnInt::InstructionReturnInt(ExpressionInt* expr, Variable* return_var)
	: InstructionReturn(return_var), expr(expr)
{}

InstructionReturnBool::InstructionReturnBool(ExpressionBool* expr, Variable* return_var)
	: InstructionReturn(return_var), expr(expr)
{}


Instruction* InstructionReturnVoid::Run()
{
	return NULL;
}

Instruction* InstructionReturnInt::Run()
{
	*(int*)return_pointer = expr->evaluate();
	return next;
}

Instruction* InstructionReturnBool::Run()
{
	*(bool*)return_pointer = expr->evaluate();
	return next;
}
