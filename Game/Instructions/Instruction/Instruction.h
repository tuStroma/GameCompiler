#pragma once

#include <iostream>
#include <string>

class Instruction
{
protected:
	Instruction* next;

public:
	Instruction(Instruction* next);
	virtual Instruction* Run();

};

