#pragma once

#include "../DataSet/DataSet.h"
#include "../Instructions/InstructionBlock.h"

class State
{
private:
	DataSet* data;
	InstructionBlock* setup;

public:
	State(DataSet* data, InstructionBlock* setup);

	void setupState();
	void print();
};

