#pragma once

#include "Instruction.h"
#include "Expression/ExpressionInt.h"
#include "Expression/ExpressionBool.h"
#include "../../DataSet/DataSet.h"

class InstructionReturn : public Instruction
{
protected:
	void* return_pointer;

public:
	InstructionReturn(Variable* return_var);
};

class InstructionReturnVoid: public Instruction
{
public:
	Instruction* Run() override;
};

class InstructionReturnInt : public InstructionReturn
{
private:
	ExpressionInt* expr;

public:
	InstructionReturnInt(ExpressionInt* expr, Variable* return_var);
	Instruction* Run() override;
};

class InstructionReturnBool : public InstructionReturn
{
private:
	ExpressionBool* expr;

public:
	InstructionReturnBool(ExpressionBool* expr, Variable* return_var);
	Instruction* Run() override;
};
