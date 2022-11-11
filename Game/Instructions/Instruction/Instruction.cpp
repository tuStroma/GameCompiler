#include "Instruction.h"

Instruction::Instruction() 
	:next(NULL)
{}

Instruction::Instruction(Instruction* next)
	: next(next)
{}

void Instruction::setNext(Instruction* next)
{
	this->next = next;
}

Instruction* Instruction::Run()
{
	return next;
}
