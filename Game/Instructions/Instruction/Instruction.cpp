#include "Instruction.h"

Instruction::Instruction(Instruction* next)
	: next(next)
{}

Instruction* Instruction::Run()
{
	return next;
}
