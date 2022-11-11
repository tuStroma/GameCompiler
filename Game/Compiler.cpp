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

SyntaxTree* Compiler::get_STATE_from_GAME(SyntaxTree* game)
{
	return extract(game, 1, "STATE from GAME");
}
SyntaxTree* Compiler::get_DATA_SET_from_STATE(SyntaxTree* state)
{
	return extract(state, 0, "DATA_SET from GAME");
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
	DataSet* state = createDataSet(get_STATE_from_GAME(input_game));

	void* ptr = state->getValuePtr("a");
	*(int*)ptr = 7;

	state->print();

	Game* game = new Game(state);
	return game;
}

DataSet* Compiler::createDataSet(SyntaxTree* input_state)
{
	SyntaxTree* data_set_st = get_DATA_SET_from_STATE(input_state);
	SyntaxTree* var_list = get_VAR_LIST_from_DATA_SET(data_set_st);

	std::list<SyntaxTree*> declaration_list;

	while (var_list->children_num == 2)
	{
		//if (var_list->children_num == 2)
		//{
			declaration_list.push_back(get_VAR_DECLARATION_from_VAR_LIST(var_list));
			var_list = get_VAR_LIST_from_VAR_LIST(var_list);
		//}
		//else
			//break;
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

InstructionBlock* Compiler::createInstructionBlock(SyntaxTree* input_instruction_block, DataSet* state, DataSet* move)
{
	Instruction* entry = NULL;

	InstructionBlock* instruction_block = new InstructionBlock(entry);

	return instruction_block;
}
