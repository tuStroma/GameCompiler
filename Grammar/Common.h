#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifndef __COMMON_H__
#define __COMMON_H__

typedef enum Type
{
	kw_main_rule, tmp_state, tmp_moves, 
	kw_players, 
	tmp_players_list, 
	kw_state, kw_int, kw_bool, 
	identifier, integer, boolean, syntax_char,
	instruction,
	tmp,


	game, main_rule, players, players_list, player, state, moves,
	data_set, var_list, var_declaration, var_type, var_definition,
	instruction_block, instruction_list,
	m_rule_list, m_rule,
	payoff_list, payoff
} Type;


typedef struct SyntaxTree SyntaxTree;
struct SyntaxTree{
	Type type;
	char* text;

	int children_num;
	SyntaxTree** children;
};

void SyntaxTree_print(SyntaxTree* st, int depth);

#endif // ifndef __COMMON_H__