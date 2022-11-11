#pragma once
#include <iostream>

#include "Instruction/Instruction.h"
#include "Instruction/InstructionAssign.h"
#include "../DataSet/DataSet.h"

class InstructionBlock
{
private:

	Instruction* entry_point;

public:
	InstructionBlock(Instruction* entry);
	void RunBlock();

};

