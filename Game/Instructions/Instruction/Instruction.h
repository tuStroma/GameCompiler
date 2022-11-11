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

	void setNext(Instruction* next);

	virtual Instruction* Run();

};

