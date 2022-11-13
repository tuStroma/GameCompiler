#pragma once

#include <iostream>
#include <string>

class Instruction
{
protected:
	Instruction* next;

public:
	Instruction();
	Instruction(Instruction* next);

	virtual void setNext(Instruction* next);

	virtual Instruction* Run();

};

