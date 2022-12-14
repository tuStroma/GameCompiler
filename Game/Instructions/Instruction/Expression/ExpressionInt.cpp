#include "ExpressionInt.h"


// Expression constructors

ExpressionInt_Id::ExpressionInt_Id(int* ptr)
{
	value_ptr = ptr;
}

ExpressionInt_Value::ExpressionInt_Value(int val)
{
	value = val;
}

ExpressionInt_PlayerIndex::ExpressionInt_PlayerIndex(PlayersSet* players)
{
	this->players = players;
}

int ExpressionInt_PlayerIndex::evaluate()
{
	return players->getCurrentPlayer()->getId();
}

ExpressionInt_Neg::ExpressionInt_Neg(ExpressionInt* expr)
{
	this->expr = expr;
}

int ExpressionInt_Neg::evaluate()
{
	return -expr->evaluate();
}

ExpressionInt_TwoArgumentsOperation::ExpressionInt_TwoArgumentsOperation(ExpressionInt* a, ExpressionInt* b)
{
	expr_a = a;
	expr_b = b;
}


// Evaluators

int ExpressionInt::evaluate()
{
	return 0;
}

int ExpressionInt_Id::evaluate()
{
	return *value_ptr;
}

int ExpressionInt_Value::evaluate()
{
	return value;
}

int ExpressionInt_Add::evaluate()
{
	return expr_a->evaluate() + expr_b->evaluate();
}

int ExpressionInt_Sub::evaluate()
{
	return expr_a->evaluate() - expr_b->evaluate();
}

int ExpressionInt_Mul::evaluate()
{
	return expr_a->evaluate() * expr_b->evaluate();
}

int ExpressionInt_Div::evaluate()
{
	return expr_a->evaluate() / expr_b->evaluate();
}

int ExpressionInt_Mod::evaluate()
{
	return expr_a->evaluate() % expr_b->evaluate();
}
