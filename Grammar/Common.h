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
	kw_state, kw_int, kw_bool, kw_return,
	kw_if, kw_while,
	identifier, integer, boolean, syntax_char,
	tmp,


	game, main_rule, players, players_list, player, state, moves,
	data_set, var_list, var_list_tail, var_declaration, var_type, var_definition,
	instruction_block, instruction_list,
	instruction, assign_instr, return_instr, if_instr, while_instr,
	expr, expr_ref, expr_literal, expr_add, expr_sub, expr_mul, expr_div, expr_mod,
	expr_equal, expr_not_equal, expr_less_equal, expr_greater_equal, expr_greater, expr_less, expr_and, expr_or,
	var_reference, local_scope, state_scope, move_scope,
	m_rule_list, m_rule,
	payoff_list, payoff,
	move_list, move, players_scope,
	identifier_list, instruction_list_tail
} Type;


typedef struct SyntaxTree SyntaxTree;
struct SyntaxTree{
	Type type;
	char* text;

	int children_num;
	SyntaxTree** children;
};

void SyntaxTree_print(SyntaxTree* st, int depth);
const char* getTypeName(Type type);

#endif // ifndef __COMMON_H__