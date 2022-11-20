#include "State.h"

State::State(DataSet* data, InstructionBlock* setup)
	: data(data), setup(setup)
{}

DataSet* State::getData()
{
	return data;
}

void State::setupState()
{
	setup->RunBlock();
}

void State::print()
{
	data->print();
	// TODO: print setup instructions
}
