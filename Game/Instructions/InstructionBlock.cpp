#include "InstructionBlock.h"

InstructionBlock::InstructionBlock(Instruction* entry)
	: entry_point(entry)
{}

void InstructionBlock::RunBlock()
{
	Instruction* instr = entry_point;

	while (instr)
		instr = instr->Run();

	// TODO: get return value
}
