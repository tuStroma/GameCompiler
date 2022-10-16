#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifndef __COMMON_H__
#define __COMMON_H__

typedef enum Type
{
	tmp_main_rule, tmp_state, tmp_moves, kw_state, kw_int, kw_bool, identifier, integer, boolean, syntax_char,

	game, main_rule, state, moves,
	data_set, var_list, var_declaration, var_type, var_definition
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