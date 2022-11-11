#pragma once
#include <iostream>

#include "Instruction/Instruction.h"
#include "../DataSet/DataSet.h"

class InstructionBlock
{
private:
	//DataSet local;
	//DataSet state;

	Instruction* entry_point;

public:
	InstructionBlock(Instruction* entry);
	void RunBlock();

};

