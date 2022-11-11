#pragma once
class ExpressionInt
{
public:
	virtual int evaluate();
};


// Subclasses for Int Expression

// Expression represents a refference
// to DataSet by identifier
class ExpressionInt_Id : public ExpressionInt
{
private:
	int* value_ptr;

public:
	ExpressionInt_Id(int* ptr);
	int evaluate() override;
};

// Expression represents a 
// constant value
class ExpressionInt_Value : public ExpressionInt
{
private:
	int value;

public:
	ExpressionInt_Value(int val);
	int evaluate() override;
};

// Class agregates two argument operations
class ExpressionInt_TwoArgumentsOperation : public ExpressionInt
{
protected:
	ExpressionInt* expr_a;
	ExpressionInt* expr_b;

public:
	ExpressionInt_TwoArgumentsOperation(ExpressionInt* a, ExpressionInt* b);
};

// Expression represents 
// sum
// of two expressions
class ExpressionInt_Add : public ExpressionInt_TwoArgumentsOperation
{
public:
	ExpressionInt_Add(ExpressionInt* a, ExpressionInt* b) : ExpressionInt_TwoArgumentsOperation(a, b) {}
	int evaluate() override;
};

// Expression represents 
// difference
// of two expressions
class ExpressionInt_Sub : public ExpressionInt_TwoArgumentsOperation
{
public:
	ExpressionInt_Sub(ExpressionInt* a, ExpressionInt* b) : ExpressionInt_TwoArgumentsOperation(a, b) {}
	int evaluate() override;
};
