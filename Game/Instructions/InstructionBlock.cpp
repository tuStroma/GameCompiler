#include "InstructionBlock.h"

InstructionBlock::InstructionBlock(Instruction* entry, VAR_TYPE return_type)
	: entry_point(entry)//, return_type(return_type)
{
	return_value = new Variable(return_type);
}

void InstructionBlock::RunBlock()
{
	Instruction* instr = entry_point;

	while (instr)
		instr = instr->Run();

	// TODO: get return value
}

void InstructionBlock::setEntryPoint(Instruction* entry_point)
{
	this->entry_point = entry_point;
}

Variable* InstructionBlock::getReturnVariable()
{
	return return_value;
}
