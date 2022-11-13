#pragma once
#include <iostream>

#include "Instruction/Instruction.h"
#include "Instruction/InstructionAssign.h"
#include "Instruction/InstructionReturn.h"
#include "../DataSet/DataSet.h"

class InstructionBlock
{
private:

	Instruction* entry_point;

	//void* return_ptr = NULL;
	//VAR_TYPE return_type;

	Variable* return_value;

public:
	InstructionBlock(Instruction* entry, VAR_TYPE return_type);
	void RunBlock();

	void setEntryPoint(Instruction* entry_point);

	Variable* getReturnVariable();
};

