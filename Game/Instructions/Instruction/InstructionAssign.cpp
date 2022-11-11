#include "InstructionAssign.h"

Instruction* InstructionAssignInt::Run()
{
	*(int*)to = expression->evaluate();
	return next;
}
