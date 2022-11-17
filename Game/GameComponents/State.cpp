#include "State.h"

State::State(DataSet* data, InstructionBlock* setup)
	: data(data), setup(setup)
{}

void State::setupState()
{
	setup->RunBlock();
}

void State::print()
{
	data->print();
	// TODO: print setup instructions
}
