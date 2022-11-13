#include "Compiler.h"

// Prints warning and 
	// returns false if 
	// ptr == NULL
bool Compiler::nullCheck(SyntaxTree* ptr, std::string warning)
{
	if (ptr == NULL)
	{
		std::cout << "Warnig: NULL pointer:\t" << warning << '\n';
		return false;
	}
	return true;
}

// Extrctors
SyntaxTree* Compiler::extract(SyntaxTree* ptr, int index, std::string warning)
{
	if (!nullCheck(ptr, warning))
		return NULL;

	if (ptr->children_num <= index)
	{
		std::cout << "Warnig: Children nuber is " << ptr->children_num << ", and index is " << index << ":\t" << warning << '\n';
		return NULL;
	}

	return ptr->children[index];
}

SyntaxTree* Compiler::getElement(SyntaxTree* ptr, Type from, Type get)
{
	std::string warning = (std::string)getTypeName(get) + " from " + (std::string)getTypeName(from);
	if (!nullCheck(ptr, warning))
		return NULL;

	if (ptr->type != from)
	{
		std::cout << "Warnig: Node type is " << getTypeName(ptr->type) << ", and should be " << getTypeName(from) << '\n';
		return NULL;
	}

	for (int i = 0; i < ptr->children_num; i++)
		if (ptr->children[i]->type == get)
			return ptr->children[i];

	std::cout << "Warnig: Not found " << getTypeName(get) << " in " << getTypeName(from) << '\n';
	return NULL;
}
SyntaxTree* Compiler::getSingleElement(SyntaxTree* ptr, Type from)
{
	std::string warning = "single from " + (std::string)getTypeName(from);
	if (!nullCheck(ptr, warning))
		return NULL;

	if (ptr->type != from)
	{
		std::cout << "Warnig: Node type is " << getTypeName(ptr->type) << ", and should be " << getTypeName(from) << '\n';
		return NULL;
	}

	if (ptr->children_num != 1)
	{
		std::cout << "Warnig: While extracting sinle element " << getTypeName(ptr->type) << " has " << getTypeName(from) << " children and should have 1\n";
		return NULL;
	}

	return ptr->children[0];
}

SyntaxTree* Compiler::get_STATE_from_GAME(SyntaxTree* game)
{
	return extract(game, 1, "STATE from GAME");
}
SyntaxTree* Compiler::get_DATA_SET_from_STATE(SyntaxTree* state)
{
	return extract(state, 0, "DATA_SET from STATE");
}
SyntaxTree* Compiler::get_INSTRUCTION_BLOCK_from_STATE(SyntaxTree* state)
{
	return extract(state, 1, "INSTRUCTION_BLOCK from STATE");
}
SyntaxTree* Compiler::get_VAR_LIST_from_DATA_SET(SyntaxTree* data_set)
{
	return extract(data_set, 0, "VAR_LIST from DATA_SET");
}
SyntaxTree* Compiler::get_VAR_DECLARATION_from_VAR_LIST(SyntaxTree* var_list)
{
	return extract(var_list, 0, "VAR_DECLARATION from VAR_LIST");
}
SyntaxTree* Compiler::get_VAR_LIST_from_VAR_LIST(SyntaxTree* var_list)
{
	return extract(var_list, 1, "VAR_LIST from VAR_LIST");
}

// Extract VAR_DECLARATION
std::string Compiler::get_type_from_VAR_DECLARATION(SyntaxTree* var_declaration)
{
	SyntaxTree* var_type = extract(var_declaration, 0, "type from VAR_DECLARATION");
	return extract(var_type, 0, "type from VAR_DECLARATION")->text;
}
std::string Compiler::get_identifier_from_VAR_DECLARATION(SyntaxTree* var_declaration)
{
	return extract(var_declaration, 1, "type from VAR_DECLARATION")->text;
}
std::string Compiler::get_value_from_VAR_DECLARATION(SyntaxTree* var_declaration)
{
	SyntaxTree* var_definition = extract(var_declaration, 2, "type from VAR_DECLARATION");
	return extract(var_definition, 0, "type from VAR_DECLARATION")->text;
}


// Data functions

void Compiler::setVariable(DataSet* data_set, std::string type, std::string name, std::string value)
{
	if (type == "INT")
	{
		int val = std::stoi(value);
		int* value_ptr = (int*)(data_set->getValuePtr(name));
		*value_ptr = val;
	}
	else if (type == "BOOL")
	{
		bool val = value == "true";
		bool* value_ptr = (bool*)(data_set->getValuePtr(name));
		*value_ptr = val;
	}

	else std::cout << "Error: unknown type:\t" << type << '\n';
}


// Main components

Game* Compiler::createGame(SyntaxTree* input_game)
{
	SyntaxTree* state_st = get_STATE_from_GAME(input_game);

	DataSet* state = createDataSet(get_DATA_SET_from_STATE(state_st));
	InstructionBlock* IB = createInstructionBlock(get_INSTRUCTION_BLOCK_from_STATE(state_st), state, NULL, VAR_TYPE::VOID);

	void* ptr = state->getValuePtr("a");
	*(int*)ptr = 7;

	IB->RunBlock();
	state->print();

	Game* game = new Game(state);
	return game;
}

DataSet* Compiler::createDataSet(SyntaxTree* input_data_set)
{
	SyntaxTree* var_list = get_VAR_LIST_from_DATA_SET(input_data_set);

	std::list<SyntaxTree*> declaration_list;

	while (var_list->children_num == 2)
	{
		declaration_list.push_back(get_VAR_DECLARATION_from_VAR_LIST(var_list));
		var_list = get_VAR_LIST_from_VAR_LIST(var_list);
	}

	int size = 0;

	for (SyntaxTree* var : declaration_list)
	{
		std::string type = get_type_from_VAR_DECLARATION(var);
		size += getTypeSize(type);
	}

	DataSet* data_set = new DataSet(size);

	for (SyntaxTree* var : declaration_list)
	{
		std::string type = get_type_from_VAR_DECLARATION(var);
		VAR_TYPE var_type = stringToVarType(type);
		std::string name = get_identifier_from_VAR_DECLARATION(var);
		std::string value = get_value_from_VAR_DECLARATION(var);

		int var_size = getTypeSize(type);
		data_set->defineVariable(name, var_type, var_size);

		setVariable(data_set, type, name, value);

	}

	return data_set;
}

InstructionBlock* Compiler::createInstructionBlock(SyntaxTree* input_instruction_block, DataSet* state, DataSet* move, VAR_TYPE return_type)
{
	SyntaxTree* local_data = getElement(input_instruction_block, Type::instruction_block, Type::data_set);
	SyntaxTree* instruction_list = extract(input_instruction_block, 1, "INSTRUCTION_LIST from INSTRUCTION_BLOCK");	// REFACTOR

	// Create local DataSet
	DataSet* local = createDataSet(local_data);

	InstructionBlock* instruction_block = new InstructionBlock(NULL, return_type);

	// Create Instruction graph
	Instruction* entry = NULL;
	Instruction* previous_instr = NULL;

	while (instruction_list->type == Type::instruction_list)
	{
		SyntaxTree* instruction_st = getElement(instruction_list, Type::instruction_list, Type::instruction);
		instruction_list = extract(instruction_list, 1, "INSTRUCTION_LIST from INSTRUCTION_LIST");	// REFACTOR

		Instruction* next_instr = createInstruction(instruction_st, local, state, move, instruction_block->getReturnVariable());

		if (entry == NULL)
		{
			entry = next_instr;
			previous_instr = next_instr;
		}
		else
		{
			previous_instr->setNext(next_instr);
			previous_instr = next_instr;
		}

	}

	instruction_block->setEntryPoint(entry);
	
	return instruction_block;
	//return new InstructionBlock(entry, return_type);
}

Instruction* Compiler::createInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var)
{
	SyntaxTree* typed_instruction = getSingleElement(input_instruction, Type::instruction);

	switch (typed_instruction->type)
	{
	case Type::assign_instr: return createAssignInstruction(typed_instruction, local, state, move);
	case Type::return_instr: return createReturnInstruction(typed_instruction, local, state, move, return_var);
	default: break;
	}

	return nullptr;
}

Instruction* Compiler::createAssignInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move)
{
	SyntaxTree* variable_reference_st = getElement(input_instruction, Type::assign_instr, Type::var_reference);
	SyntaxTree* expression_st = extract(input_instruction, 1, "EXPR from ASSIGN_INSTR");	// REFACTOR

	SyntaxTree* scope_st = extract(variable_reference_st, 0, "SCOPE from VARIABLE_REFERENCE");	// REFACTOR
	SyntaxTree* identifier_st = extract(variable_reference_st, 1, "IDENTIFIER from VARIABLE_REFERENCE");	// REFACTOR


	DataSet* data_set_to = getScope(scope_st->type, local, state, move);
	if (!data_set_to) return NULL;

	void* to			= data_set_to->getValuePtr(identifier_st->text);
	VAR_TYPE type_to	= data_set_to->getValueType(identifier_st->text);
	if (!to) std::cout << "Warnig: Not found identifier \"" << identifier_st->text << "\" in scope: " << getTypeName(scope_st->type) << '\n';

	switch (type_to)
	{
	case VAR_TYPE::INT: 
	{
		ExpressionInt* expr = createIntExpression(expression_st, local, state, move);
		return new InstructionAssignInt(to, expr);
	}
	case VAR_TYPE::BOOL: 
	{
		ExpressionBool* expr = createBoolExpression(expression_st, local, state, move);
		return new InstructionAssignBool(to, expr);
	}
	default: {
		std::cout << "Warnig: Unknown value type\n";
		return NULL;
	}
	}

	return nullptr;
}

Instruction* Compiler::createReturnInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var)
{
	bool returns_value = input_instruction->children_num == 1;
	SyntaxTree* expression_st = NULL;
	if(returns_value)
		expression_st = extract(input_instruction, 0, "EXPR from RETURN_INSTR");	// REFACTOR

	switch (return_var->getType())
	{
	case VAR_TYPE::VOID: {
		if (returns_value)
		{
			std::cout << "Warnig: Wrong return type, should be VOID\n";
			return NULL;
		}
		return new InstructionReturnVoid();
	}
	case VAR_TYPE::INT: {
		if (!returns_value)
		{
			std::cout << "Warnig: No return value, should be VOID\n";
			return NULL;
		}
		ExpressionInt* expr = createIntExpression(expression_st, local, state, move);
		return new InstructionReturnInt(expr, return_var);
	}
	case VAR_TYPE::BOOL: {
		if (!returns_value)
		{
			std::cout << "Warnig: No return value, should be VOID\n";
			return NULL;
		}
		ExpressionBool* expr = createBoolExpression(expression_st, local, state, move);
		return new InstructionReturnBool(expr, return_var);
	}
	default: break;
	}

	return nullptr;
}

ExpressionInt* Compiler::createIntExpression(SyntaxTree* input_expression, DataSet* local, DataSet* state, DataSet* move)
{
	switch (input_expression->type)
	{
	case Type::expr: 
	{
		SyntaxTree* next_expr = extract(input_expression, 0, "EXPR from EXPR");	// REFACTOR
		return createIntExpression(next_expr, local, state, move);
	}
	case Type::expr_ref:
	{
		SyntaxTree* variable_reference_st = extract(input_expression, 0, "VARIABLE_REFERENCE from EXPR");	// REFACTOR
		void* from = getIdentifierReference(variable_reference_st, VAR_TYPE::INT, local, state, move);
		if (!from) return NULL;

		return new ExpressionInt_Id((int*)from);
	}
	case Type::expr_literal: 
	{
		SyntaxTree* var_def = getElement(input_expression, Type::expr_literal, Type::var_definition);
		std::string string_val = extract(var_def, 0, "type from VAR_DECLARATION")->text;
		return new ExpressionInt_Value(stoi(string_val));
	}
	case Type::expr_add:
	case Type::expr_sub:
	case Type::expr_mul:
	case Type::expr_div:
	case Type::expr_mod:
	{
		SyntaxTree* arg_a_st = extract(input_expression, 0, "EXPR A from EXPR");
		SyntaxTree* arg_b_st = extract(input_expression, 1, "EXPR B from EXPR");

		ExpressionInt* a = createIntExpression(arg_a_st, local, state, move);
		ExpressionInt* b = createIntExpression(arg_b_st, local, state, move);

		switch (input_expression->type)
		{
		case Type::expr_add: return new ExpressionInt_Add(a, b);
		case Type::expr_sub: return new ExpressionInt_Sub(a, b);
		case Type::expr_mul: return new ExpressionInt_Mul(a, b);
		case Type::expr_div: return new ExpressionInt_Div(a, b);
		case Type::expr_mod: return new ExpressionInt_Mod(a, b);
		}
	}
	default: break;
	}

	return nullptr;
}

ExpressionBool* Compiler::createBoolExpression(SyntaxTree* input_expression, DataSet* local, DataSet* state, DataSet* move)
{
	switch (input_expression->type)
	{
	case Type::expr:
	{
		SyntaxTree* next_expr = extract(input_expression, 0, "EXPR from EXPR");	// REFACTOR
		return createBoolExpression(next_expr, local, state, move);
	}
	case Type::expr_ref:
	{
		SyntaxTree* variable_reference_st = extract(input_expression, 0, "VARIABLE_REFERENCE from EXPR");	// REFACTOR
		void* from = getIdentifierReference(variable_reference_st, VAR_TYPE::BOOL, local, state, move);
		if (!from) return NULL;

		return new ExpressionBool_Id((bool*)from);
	}
	case Type::expr_literal:
	{
		SyntaxTree* var_def = getElement(input_expression, Type::expr_literal, Type::var_definition);
		std::string string_val = extract(var_def, 0, "type from VAR_DECLARATION")->text;
		return new ExpressionBool_Value(string_val == "true");
	}
	case Type::expr_and:
	case Type::expr_or:
	{
		SyntaxTree* arg_a_st = extract(input_expression, 0, "EXPR A from EXPR");
		SyntaxTree* arg_b_st = extract(input_expression, 1, "EXPR B from EXPR");

		ExpressionBool* a = createBoolExpression(arg_a_st, local, state, move);
		ExpressionBool* b = createBoolExpression(arg_b_st, local, state, move);

		switch (input_expression->type)
		{
		case Type::expr_and:	return new ExpressionBool_And(a, b);
		case Type::expr_or:		return new ExpressionBool_Or(a, b);
		}
	}
	case Type::expr_equal:
	case Type::expr_not_equal:
	case Type::expr_greater_equal:
	case Type::expr_less_equal:
	case Type::expr_greater:
	case Type::expr_less:
	{
		SyntaxTree* arg_a_st = extract(input_expression, 0, "EXPR A from EXPR");
		SyntaxTree* arg_b_st = extract(input_expression, 1, "EXPR B from EXPR");

		ExpressionInt* a = createIntExpression(arg_a_st, local, state, move);
		ExpressionInt* b = createIntExpression(arg_b_st, local, state, move);

		switch (input_expression->type)
		{
		case Type::expr_equal:			return new ExpressionBool_Equal(a, b);
		case Type::expr_not_equal:		return new ExpressionBool_NotEqual(a, b);
		case Type::expr_greater_equal:	return new ExpressionBool_GreaterEqual(a, b);
		case Type::expr_less_equal:		return new ExpressionBool_LessEqual(a, b);
		case Type::expr_greater:		return new ExpressionBool_Greater(a, b);
		case Type::expr_less:			return new ExpressionBool_Less(a, b);
		}
	}
	default: break;
	}

	return nullptr;
}

void* Compiler::getIdentifierReference(SyntaxTree* var_reference, VAR_TYPE required_type, DataSet* local, DataSet* state, DataSet* move)
{
	SyntaxTree* scope_st = extract(var_reference, 0, "SCOPE from VARIABLE_REFERENCE");	// REFACTOR
	SyntaxTree* identifier_st = extract(var_reference, 1, "IDENTIFIER from VARIABLE_REFERENCE");	// REFACTOR

	DataSet* data_set_from = getScope(scope_st->type, local, state, move);
	if (!data_set_from) return NULL;

	void* from = data_set_from->getValuePtr(identifier_st->text);
	VAR_TYPE type_from = data_set_from->getValueType(identifier_st->text);
	if (!from) std::cout << "Warnig: Not found identifier \"" << identifier_st->text << "\" in scope: " << getTypeName(scope_st->type) << '\n';
	if (type_from != required_type) {
		std::cout << "Warnig: Incorrect variable type, should be " << VarTypeToString(required_type) << "\n";
		return NULL;
	}

	return from;
}

DataSet* Compiler::getScope(Type type, DataSet* local, DataSet* state, DataSet* move)
{
	switch (type)
	{
	case Type::local_scope: return local;
	case Type::state_scope: return state;
	case Type::move_scope: return move;

	default: {
		std::cout << "Warnig: Unknown scope: " << (std::string)getTypeName(type) << '\n';
		return NULL;
	}
	}
}
