#pragma once
#include <list>
#include <string>

#include "../Grammar/Common.h"
#include "Game.h"

class Compiler
{
private:
	Game* game_object;
	PlayersSet* players_set;
	State* state;


	bool nullCheck(SyntaxTree* ptr, std::string warning);

	// Extrctors
	SyntaxTree* extract(SyntaxTree* ptr, int index, std::string warning);
	SyntaxTree* getElement(SyntaxTree* ptr, Type from, Type get);
	SyntaxTree* getSingleElement(SyntaxTree* ptr, Type from);


	// Extract GAME
	SyntaxTree* get_STATE_from_GAME(SyntaxTree* game);

	// Extract STATE
	SyntaxTree* get_DATA_SET_from_STATE(SyntaxTree* state);
	SyntaxTree* get_INSTRUCTION_BLOCK_from_STATE(SyntaxTree* state);

	// Extract DATA_SET
	SyntaxTree* get_VAR_LIST_from_DATA_SET(SyntaxTree* data_set);

	// Extract VAR_LIST
	SyntaxTree* get_VAR_DECLARATION_from_VAR_LIST(SyntaxTree* var_list);
	SyntaxTree* get_VAR_LIST_from_VAR_LIST(SyntaxTree* var_list);

	// Extract VAR_DECLARATION
	std::string get_type_from_VAR_DECLARATION(SyntaxTree* var_declaration);
	std::string get_identifier_from_VAR_DECLARATION(SyntaxTree* var_declaration);
	std::string get_value_from_VAR_DECLARATION(SyntaxTree* var_declaration);



	// Data functions

	void setVariable(DataSet* data_set, std::string type, std::string name, std::string value);


	// Main components //


	State* createState(SyntaxTree* input_state);

	// Takes STATE part of syntax tree as an input
	DataSet* createDataSet(SyntaxTree* input_data_set);

	// Players
	PlayersSet* createPlayers(SyntaxTree* input_players);
	void addPlayerClass(SyntaxTree* input_player_class, std::list<Player*>& players);


	// Main Rule //

	MainRule* createMainRule(SyntaxTree* input_main_rule);
	EndRule* createEndRule(SyntaxTree* input_end_rule);
	Payoff* createPayoff(SyntaxTree* input_payoff);


	// Moves //

	Moves* createMoves(SyntaxTree* input_moves);
	Move* createMove(SyntaxTree* input_move);
	std::list<std::string> createPlayersScope(SyntaxTree* input_players_scope);
	std::list<std::string> getPlayersClasses();


	// Instructions //

	InstructionBlock* createInstructionBlock(SyntaxTree* input_instruction_block, DataSet* state, DataSet* move, VAR_TYPE return_type);

	Instruction* createInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var, std::list<Instruction*>& last_instructions);
	Instruction* createAssignInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move);
	Instruction* createReturnInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var);
	Instruction* createIfInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var, std::list<Instruction*>& last_instructions);
	Instruction* createWhileInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var, std::list<Instruction*>& last_instructions);
	Instruction* createNextPlayerInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move);

	Instruction* createInstructionGraph(SyntaxTree* input_instruction_list, DataSet* local, DataSet* state, DataSet* move, Variable* return_variable, std::list<Instruction*>& predecessors);
	ExpressionInt* createIntExpression(SyntaxTree* input_expression, DataSet* local, DataSet* state, DataSet* move);
	ExpressionBool* createBoolExpression(SyntaxTree* input_expression, DataSet* local, DataSet* state, DataSet* move);

	void* getIdentifierReference(SyntaxTree* var_reference, VAR_TYPE required_type, DataSet* local, DataSet* state, DataSet* move);
	DataSet* getScope(Type type, DataSet* local, DataSet* state, DataSet* move);

public:
	// Takes as an input all syntax tree
	Game* createGame(SyntaxTree* input_game);
	Game* createGame(std::string source);
};

