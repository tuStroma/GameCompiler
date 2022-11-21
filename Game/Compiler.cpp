#include "Compiler.h"

#include "../Grammar/Common.h"
#include "../Grammar/Parser.tab.h"

extern "C" SyntaxTree * parser_main(char* file_path);

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

State* Compiler::createState(SyntaxTree* input_state)
{
	DataSet* state_data = createDataSet(get_DATA_SET_from_STATE(input_state));
	InstructionBlock* setup = createInstructionBlock(get_INSTRUCTION_BLOCK_from_STATE(input_state), state_data, NULL, VAR_TYPE::VOID);

	return new State(state_data, setup);
}


// Main components

Game* Compiler::createGame(SyntaxTree* input_game)
{
	SyntaxTree* players_st = extract(input_game, 0, "PLAYERS from GAME");
	SyntaxTree* state_st = get_STATE_from_GAME(input_game);
	SyntaxTree* main_rule_st = extract(input_game, 2, "MAIN_RULE from GAME");
	SyntaxTree* moves_st = extract(input_game, 3, "MOVES from GAME");



	players_set = createPlayers(players_st);

	state = createState(state_st);

	MainRule* main_rule = createMainRule(main_rule_st);

	Moves* moves = createMoves(moves_st);


	state->setupState();
	main_rule->Run();
	state->print();
	players_set->print();



	game_object = new Game(players_set, state, main_rule, moves);

	return game_object;
}

Game* Compiler::createGame(std::string source)
{
	SyntaxTree* st = parser_main(const_cast<char*>(source.c_str()));
	SyntaxTree_print(st, 0);

	std::cout << "\n\n";

	Compiler compiler = Compiler();
	
	return compiler.createGame(st);
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

PlayersSet* Compiler::createPlayers(SyntaxTree* input_players)
{
	SyntaxTree* players_list_st = extract(input_players, 0, "PLAYERS_LIST from PLAYERS");

	std::list<Player*> players = std::list<Player*>();

	while (true)
	{
		SyntaxTree* player_class_st = extract(players_list_st, 0, "PLAYER from PLYERS_LIST");
		addPlayerClass(player_class_st, players);

		if (players_list_st->children_num == 2)
			players_list_st = extract(players_list_st, 1, "PLAYERS_LIST from PLYERS_LIST");

		else break;
	}


	return new PlayersSet(players);
}

void Compiler::addPlayerClass(SyntaxTree* input_player_class, std::list<Player*>& players)
{
	std::string identifier = extract(input_player_class, 0, "IDENTIFIER from PLAYER_CLASS")->text;
	int class_size = std::stoi(extract(input_player_class, 1, "CLASS_SIZE from PLAYER_CLASS")->text);

	for (int i = 0; i < class_size; i++)
		players.push_back(new Player(identifier, i));
}

MainRule* Compiler::createMainRule(SyntaxTree* input_main_rule)
{
	SyntaxTree* end_rule_list_st = extract(input_main_rule, 0, "MAIN_RULE_LIST from MAIN_RULE");

	std::list<EndRule*> end_rule_list;

	while (true)
	{
		SyntaxTree* end_rule_st = extract(end_rule_list_st, 0, "END_RULE from END_RULE_LIST");
		EndRule* end_rule = createEndRule(end_rule_st);
		end_rule_list.push_back(end_rule);

		if (end_rule_list_st->children_num == 2)
			end_rule_list_st = extract(end_rule_list_st, 1, "END_RULE_LIST from END_RULE_LIST");

		else break;
	}

	return new MainRule(end_rule_list);
}

EndRule* Compiler::createEndRule(SyntaxTree* input_end_rule)
{
	SyntaxTree* identifier_st = extract(input_end_rule, 0, "IDENTIFIER from END_RULE");
	SyntaxTree* rule_condition_st = extract(input_end_rule, 1, "INSTRUCTION_BLOCK from END_RULE");
	SyntaxTree* payoff_list_st = extract(input_end_rule, 2, "PAYOFF_LIST from END_RULE");

	std::string rule_name = identifier_st->text;
	InstructionBlock* rule_condition = createInstructionBlock(rule_condition_st, state->getData(), NULL, VAR_TYPE::BOOL);

	std::list<Payoff*> payoff_list;

	while (true)
	{
		SyntaxTree* payoff_st = extract(payoff_list_st, 0, "PAYOFF from PAYOFF_LIST");
		Payoff* payoff = createPayoff(payoff_st);
		payoff_list.push_back(payoff);

		if (payoff_list_st->children_num == 2)
			payoff_list_st = extract(payoff_list_st, 1, "PAYOFF_LIST from PAYOFF_LIST");

		else break;
	}

	return new EndRule(rule_name, rule_condition, payoff_list, players_set);
}

Payoff* Compiler::createPayoff(SyntaxTree* input_payoff)
{
	SyntaxTree* identifier_st = extract(input_payoff, 0, "IDENTIFIER from PAYOFF");
	SyntaxTree* payoff_st = extract(input_payoff, 1, "INSTRUCTION_BLOCK from PAYOFF");

	std::string player_class = identifier_st->text;
	InstructionBlock* payoff_block = createInstructionBlock(payoff_st, state->getData(), NULL, VAR_TYPE::INT);

	return new Payoff(player_class, payoff_block);
}

Moves* Compiler::createMoves(SyntaxTree* input_moves)
{
	SyntaxTree* move_list_st = extract(input_moves, 0, "MOVE_LIST from MOVES");

	std::list<Move*> move_list;

	while (true)
	{
		SyntaxTree* move_st = extract(move_list_st, 0, "MOVE from MOVE_LIST");
		Move* move = createMove(move_st);
		move_list.push_back(move);

		if (move_list_st->children_num == 2)
			move_list_st = extract(move_list_st, 1, "MOVE_LIST from MOVE_LIST");

		else break;
	}

	return new Moves(move_list);
}

Move* Compiler::createMove(SyntaxTree* input_move)
{
	SyntaxTree* identifier_st = extract(input_move, 0, "IDENTIFIER from MOVE");
	SyntaxTree* players_scope_st = extract(input_move, 1, "PLAYERS_SCOPE from MOVE");
	SyntaxTree* move_data_st = extract(input_move, 2, "DATA_SET from MOVE");
	SyntaxTree* validation_st = extract(input_move, 3, "INSTRUCTION_BLOCK from MOVE");
	SyntaxTree* execution_st = extract(input_move, 4, "INSTRUCTION_BLOCK from MOVE");

	std::string name = identifier_st->text;
	std::list<std::string> players_scope = createPlayersScope(players_scope_st);
	DataSet* move_data = createDataSet(move_data_st);
	InstructionBlock* validation = createInstructionBlock(validation_st, state->getData(), move_data, VAR_TYPE::BOOL);
	InstructionBlock* move_execution = createInstructionBlock(execution_st, state->getData(), move_data, VAR_TYPE::VOID);

	return new Move(name, players_scope, move_data, validation, move_execution);
}

std::list<std::string> Compiler::createPlayersScope(SyntaxTree* input_players_scope)
{
	if (input_players_scope->children_num == 0) // Add all player classes
		return getPlayersClasses();


	SyntaxTree* identifier_list_st = extract(input_players_scope, 0, "IDENTIFIER_LIST from PLAYERS_SCOPE");

	std::list<std::string> players_scope; 
	
	while (true)
	{
		SyntaxTree* identifier_st = extract(identifier_list_st, 0, "IDENTIFIER from IDENTIFIER_LIST");
		players_scope.push_back(identifier_st->text);

		if (identifier_list_st->children_num == 2)
			identifier_list_st = extract(identifier_list_st, 1, "IDENTIFIER_LIST from IDENTIFIER_LIST");

		else break;
	}

	return players_scope;
}

std::list<std::string> Compiler::getPlayersClasses()
{
	std::list<std::string> all_classes;

	std::list<Player*> players_list = players_set->getPlayersList();
	for (Player* player : players_list)
	{
		bool exists = false;
		for (std::string from_scope : all_classes)
		{
			if (player->getType() == from_scope)
			{
				exists = true;
				break;
			}
		}

		if (!exists)
			all_classes.push_back(player->getType());
	}

	return all_classes;
}

InstructionBlock* Compiler::createInstructionBlock(SyntaxTree* input_instruction_block, DataSet* state, DataSet* move, VAR_TYPE return_type)
{
	SyntaxTree* local_data = getElement(input_instruction_block, Type::instruction_block, Type::data_set);
	SyntaxTree* instruction_list = extract(input_instruction_block, 1, "INSTRUCTION_LIST from INSTRUCTION_BLOCK");	// REFACTOR

	// Create local DataSet
	DataSet* local = createDataSet(local_data);

	InstructionBlock* instruction_block = new InstructionBlock(NULL, return_type);

	// Create Instruction graph
	std::list<Instruction*> last_instructions;
	Instruction* entry = createInstructionGraph(instruction_list, local, state, move, instruction_block->getReturnVariable(), last_instructions);

	instruction_block->setEntryPoint(entry);
	
	return instruction_block;
}

Instruction* Compiler::createInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var, std::list<Instruction*>& last_instructions)
{
	SyntaxTree* typed_instruction = getSingleElement(input_instruction, Type::instruction);

	switch (typed_instruction->type)
	{
	case Type::assign_instr: {
		Instruction* instr = createAssignInstruction(typed_instruction, local, state, move);
		last_instructions.push_back(instr);
		return instr;
	}
	case Type::next_player_instr: {
		Instruction* instr = createNextPlayerInstruction(typed_instruction, local, state, move);
		last_instructions.push_back(instr);
		return instr;
	}
	case Type::return_instr: return createReturnInstruction(typed_instruction, local, state, move, return_var);
	case Type::if_instr: return createIfInstruction(typed_instruction, local, state, move, return_var, last_instructions);
	case Type::while_instr: return createWhileInstruction(typed_instruction, local, state, move, return_var, last_instructions);
	default: break;
	}
	
	std::cout << "Warnig: No implementation for instruction type: " << getTypeName(typed_instruction->type) << "\n";

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

Instruction* Compiler::createIfInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var, std::list<Instruction*>& last_instructions)
{
	SyntaxTree* condition_st = extract(input_instruction, 0, "EXPR from IF_INSTR");	// REFACTOR
	SyntaxTree* instruction_list_st = extract(input_instruction, 1, "INSTRUCTION_LIST from IF_INSTR");	// REFACTOR

	ExpressionBool* condition = createBoolExpression(condition_st, local, state, move);
	Instruction* first = createInstructionGraph(instruction_list_st, local, state, move, return_var, last_instructions);

	InstructionConditionalJump* instr = new InstructionConditionalJump(condition, first);

	last_instructions.push_back(instr);

	return instr;
}

Instruction* Compiler::createWhileInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var, std::list<Instruction*>& last_instructions)
{
	SyntaxTree* condition_st = extract(input_instruction, 0, "EXPR from WHILE_INSTR");	// REFACTOR
	SyntaxTree* instruction_list_st = extract(input_instruction, 1, "INSTRUCTION_LIST from WHILE_INSTR");	// REFACTOR

	ExpressionBool* condition = createBoolExpression(condition_st, local, state, move);
	Instruction* first = createInstructionGraph(instruction_list_st, local, state, move, return_var, last_instructions);

	InstructionConditionalJump* while_instr = new InstructionConditionalJump(condition, first);

	for (Instruction* instr : last_instructions)
		instr->setNext(while_instr);

	last_instructions.clear();
	last_instructions.push_back(while_instr);

	return while_instr;
}

Instruction* Compiler::createNextPlayerInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move)
{
	SyntaxTree* identifier_st = extract(input_instruction, 0, "IDENTIFIER from NEXT_PLAYER_INSTR");	// REFACTOR
	SyntaxTree* player_id_expr_st = extract(input_instruction, 1, "EXPR from NEXT_PLAYER_INSTR");	// REFACTOR

	std::string type = identifier_st->text;
	ExpressionInt* id_expr = createIntExpression(player_id_expr_st, local, state, move);

	// No check if NEW_PLYER_INSTR is available in current block

	return new InstructionNextPlayer(players_set, type, id_expr);
}

Instruction* Compiler::createInstructionGraph(SyntaxTree* input_instruction_list, DataSet* local, DataSet* state, DataSet* move, Variable* return_variable, std::list<Instruction*>& predecessors)
{
	Instruction* entry = NULL;
	//Instruction* previous_instr = NULL;
	std::list<Instruction*> last_instructions;

	while (input_instruction_list->type == Type::instruction_list)
	{
		SyntaxTree* instruction_st = getElement(input_instruction_list, Type::instruction_list, Type::instruction);
		input_instruction_list = extract(input_instruction_list, 1, "INSTRUCTION_LIST from INSTRUCTION_LIST");	// REFACTOR

		last_instructions.clear();
		Instruction* next_instr = createInstruction(instruction_st, local, state, move, return_variable, last_instructions);

		if (entry == NULL)
		{
			entry = next_instr;
			predecessors = last_instructions;
		}
		else
		{
			for (Instruction* instr : predecessors)
				instr->setNext(next_instr);

			predecessors.clear();
			predecessors = last_instructions;
		}

	}

	return entry;
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
	case Type::expr_player_index:
	{
		return new ExpressionInt_PlayerIndex(players_set);
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
	case Type::expr_neg:
	{
		SyntaxTree* arg_st = extract(input_expression, 0, "EXPR A from EXPR");
		ExpressionInt* arg = createIntExpression(arg_st, local, state, move);
		return new ExpressionInt_Neg(arg);
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
	default: 
		std::cout << "Error: Invalid operator \"" << getTypeName(input_expression->type) << "\" in INT expression\n";
		break;
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
	case Type::expr_not:
	{
		SyntaxTree* arg_st = extract(input_expression, 0, "EXPR from EXPR");
		ExpressionBool* arg = createBoolExpression(arg_st, local, state, move);
		return new ExpressionBool_Not(arg);
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
	default:
		std::cout << "Error: Invalid operator \"" << getTypeName(input_expression->type) << "\" in BOOL expression\n"; 
		break;
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
