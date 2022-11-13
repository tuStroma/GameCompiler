#pragma once
#include <list>
#include <string>

#include "../Grammar/Common.h"
#include "Game.h"

class Compiler
{
private:

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

	// Extract INSTRUCTION_BLOCK
	SyntaxTree* get_DATA_SET_from_INSTRUCTION_BLOCK(SyntaxTree* state);
	SyntaxTree* get_INSTRUCTION_LIST_from_INSTRUCTION_BLOCK(SyntaxTree* state);

	// Extract INSTRUCTION_LIST
	SyntaxTree* get_INSTRUCTION_LIST_from_INSTRUCTION_LIST(SyntaxTree* state);
	SyntaxTree* get_INSTRUCTION_from_INSTRUCTION_LIST(SyntaxTree* state);

	// Extract INSTRUCTION
	SyntaxTree* get_INSTRUCTION_type_from_INSTRUCTION(SyntaxTree* state);

	// Extract ASSIGN_INSTR
	SyntaxTree* get_VAR_REFERENCE_from_ASSIGN_INSTR(SyntaxTree* state);
	SyntaxTree* get_EXPR_from_ASSIGN_INSTR(SyntaxTree* state);

	// Extract VAR_REFERENCE
	SyntaxTree* get_SCOPE_from_VAR_REFERENCE(SyntaxTree* state);
	SyntaxTree* get_IDENTIFIER_from_VAR_REFERENCE(SyntaxTree* state);

	// Extract EXPR
	SyntaxTree* get_VAR_REFERENCE_from_EXPR(SyntaxTree* state);
	SyntaxTree* get_VAR_DEFINITION_from_EXPR(SyntaxTree* state);
	SyntaxTree* get_EXPR_from_EXPR(SyntaxTree* state);





	// Data functions

	void setVariable(DataSet* data_set, std::string type, std::string name, std::string value);


	// Main components //

	// Takes STATE part of syntax tree as an input
	// Structure of STATE is:
	//
	// DATA_SET -> VAR_LIST -> VAR_DECLARATION
	//						|
	//                      -> VAR_DECLARATION
	//                         VAR_LIST
	DataSet* createDataSet(SyntaxTree* input_data_set);


	// Instructions //

	InstructionBlock* createInstructionBlock(SyntaxTree* input_instruction_block, DataSet* state, DataSet* move, VAR_TYPE return_type);

	Instruction* createInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var);
	Instruction* createAssignInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move);
	Instruction* createReturnInstruction(SyntaxTree* input_instruction, DataSet* local, DataSet* state, DataSet* move, Variable* return_var);

	ExpressionInt* createIntExpression(SyntaxTree* input_expression, DataSet* local, DataSet* state, DataSet* move);
	ExpressionBool* createBoolExpression(SyntaxTree* input_expression, DataSet* local, DataSet* state, DataSet* move);

	void* getIdentifierReference(SyntaxTree* var_reference, VAR_TYPE required_type, DataSet* local, DataSet* state, DataSet* move);
	DataSet* getScope(Type type, DataSet* local, DataSet* state, DataSet* move);

public:
	// Takes as an input all syntax tree
	// Its main parts are:
	//
	// MAIN_RULE
	// STATE 
	// MOVES
	Game* createGame(SyntaxTree* input_game);
};

