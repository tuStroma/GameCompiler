#pragma once
#include "ExpressionInt.h"

class ExpressionBool
{
public:
	virtual bool evaluate();
};


// Subclasses for Bool Expression

// Expression represents a refference
// to DataSet by identifier
class ExpressionBool_Id : public ExpressionBool
{
private:
	bool* value_ptr;

public:
	ExpressionBool_Id(bool* ptr);
	bool evaluate() override;
};

// Expression represents a 
// constant value
class ExpressionBool_Value : public ExpressionBool
{
private:
	bool value;

public:
	ExpressionBool_Value(bool val);
	bool evaluate() override;
};

// Expression represents negation 
// of BOOL expression
class ExpressionBool_Not : public ExpressionBool
{
private:
	ExpressionBool* expr;

public:
	ExpressionBool_Not(ExpressionBool* expr);
	bool evaluate() override;
};


// Class agregates two Bool argument operations
class ExpressionBool_TwoBoolArgumentsOperation : public ExpressionBool
{
protected:
	ExpressionBool* expr_a;
	ExpressionBool* expr_b;

public:
	ExpressionBool_TwoBoolArgumentsOperation(ExpressionBool* a, ExpressionBool* b);
};


class ExpressionBool_And : public ExpressionBool_TwoBoolArgumentsOperation
{
public:
	ExpressionBool_And(ExpressionBool* a, ExpressionBool* b) : ExpressionBool_TwoBoolArgumentsOperation(a, b) {}
	bool evaluate() override;
};

class ExpressionBool_Or : public ExpressionBool_TwoBoolArgumentsOperation
{
public:
	ExpressionBool_Or(ExpressionBool* a, ExpressionBool* b) : ExpressionBool_TwoBoolArgumentsOperation(a, b) {}
	bool evaluate() override;
};


// Class agregates two Int argument operations
class ExpressionBool_TwoIntArgumentsOperation : public ExpressionBool
{
protected:
	ExpressionInt* expr_a;
	ExpressionInt* expr_b;

public:
	ExpressionBool_TwoIntArgumentsOperation(ExpressionInt* a, ExpressionInt* b);
};


class ExpressionBool_Equal : public ExpressionBool_TwoIntArgumentsOperation
{
public:
	ExpressionBool_Equal(ExpressionInt* a, ExpressionInt* b) : ExpressionBool_TwoIntArgumentsOperation(a, b) {}
	bool evaluate() override;
};

class ExpressionBool_NotEqual : public ExpressionBool_TwoIntArgumentsOperation
{
public:
	ExpressionBool_NotEqual(ExpressionInt* a, ExpressionInt* b) : ExpressionBool_TwoIntArgumentsOperation(a, b) {}
	bool evaluate() override;
};

class ExpressionBool_GreaterEqual : public ExpressionBool_TwoIntArgumentsOperation
{
public:
	ExpressionBool_GreaterEqual(ExpressionInt* a, ExpressionInt* b) : ExpressionBool_TwoIntArgumentsOperation(a, b) {}
	bool evaluate() override;
};

class ExpressionBool_LessEqual : public ExpressionBool_TwoIntArgumentsOperation
{
public:
	ExpressionBool_LessEqual(ExpressionInt* a, ExpressionInt* b) : ExpressionBool_TwoIntArgumentsOperation(a, b) {}
	bool evaluate() override;
};

class ExpressionBool_Greater : public ExpressionBool_TwoIntArgumentsOperation
{
public:
	ExpressionBool_Greater(ExpressionInt* a, ExpressionInt* b) : ExpressionBool_TwoIntArgumentsOperation(a, b) {}
	bool evaluate() override;
};

class ExpressionBool_Less : public ExpressionBool_TwoIntArgumentsOperation
{
public:
	ExpressionBool_Less(ExpressionInt* a, ExpressionInt* b) : ExpressionBool_TwoIntArgumentsOperation(a, b) {}
	bool evaluate() override;
};
