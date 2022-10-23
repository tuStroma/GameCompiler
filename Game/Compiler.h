#pragma once
#include <list>

#include "../Grammar/Common.h"
#include "Game.h"

class Compiler
{
private:

	bool nullCheck(SyntaxTree* ptr, std::string warning);

	// Extrctors
	SyntaxTree* extract(SyntaxTree* ptr, int index, std::string warning);

	SyntaxTree* get_STATE_from_GAME(SyntaxTree* game);
	SyntaxTree* get_DATA_SET_from_STATE(SyntaxTree* state);
	SyntaxTree* get_VAR_LIST_from_DATA_SET(SyntaxTree* data_set);
	SyntaxTree* get_VAR_DECLARATION_from_VAR_LIST(SyntaxTree* var_list);
	SyntaxTree* get_VAR_LIST_from_VAR_LIST(SyntaxTree* var_list);

	// Extract VAR_DECLARATION
	std::string get_type_from_VAR_DECLARATION(SyntaxTree* var_declaration);
	std::string get_identifier_from_VAR_DECLARATION(SyntaxTree* var_declaration);
	std::string get_value_from_VAR_DECLARATION(SyntaxTree* var_declaration);


	// Data functions

	void setVariable(DataSet* data_set, std::string type, std::string name, std::string value);


	// Main components

	// Takes STATE part of syntax tree as an input
	// Structure of STATE is:
	//
	// DATA_SET -> VAR_LIST -> VAR_DECLARATION
	//						|
	//                      -> VAR_DECLARATION
	//                         VAR_LIST
	DataSet* createDataSet(SyntaxTree* input_state);

public:
	// Takes as an input all syntax tree
	// Its main parts are:
	//
	// MAIN_RULE
	// STATE 
	// MOVES
	Game* createGame(SyntaxTree* input_game);
};

