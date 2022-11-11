#include "ExpressionBool.h"


// Constructors

ExpressionBool_Id::ExpressionBool_Id(bool* ptr)
{
	value_ptr = ptr;
}

ExpressionBool_Value::ExpressionBool_Value(bool val)
{
	value = val;
}

ExpressionBool_TwoBoolArgumentsOperation::ExpressionBool_TwoBoolArgumentsOperation(ExpressionBool* a, ExpressionBool* b)
{
	expr_a = a;
	expr_b = b;
}

ExpressionBool_TwoIntArgumentsOperation::ExpressionBool_TwoIntArgumentsOperation(ExpressionInt* a, ExpressionInt* b)
{
	expr_a = a;
	expr_b = b;
}


//Evaluators

bool ExpressionBool::evaluate()
{
	return false;
}

bool ExpressionBool_Id::evaluate()
{
	return *value_ptr;
}

bool ExpressionBool_Value::evaluate()
{
	return value;
}

bool ExpressionBool_And::evaluate()
{
	return expr_a->evaluate() && expr_b->evaluate();
}

bool ExpressionBool_Or::evaluate()
{
	return expr_a->evaluate() || expr_b->evaluate();
}

bool ExpressionBool_Equal::evaluate()
{
	return expr_a->evaluate() == expr_b->evaluate();
}

bool ExpressionBool_NotEqual::evaluate()
{
	return expr_a->evaluate() != expr_b->evaluate();
}

bool ExpressionBool_GreaterEqual::evaluate()
{
	return expr_a->evaluate() >= expr_b->evaluate();
}

bool ExpressionBool_LessEqual::evaluate()
{
	return expr_a->evaluate() <= expr_b->evaluate();
}

bool ExpressionBool_Greater::evaluate()
{
	return expr_a->evaluate() > expr_b->evaluate();
}

bool ExpressionBool_Less::evaluate()
{
	return expr_a->evaluate() < expr_b->evaluate();
}
