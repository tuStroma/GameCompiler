#include "Common.h"


const char* getTypeName(Type type)
{
	switch (type)
	{
	case kw_main_rule:			return "kw_main_rule";
	case tmp_state:				return "tmp_state";
	case tmp_moves:				return "tmp_moves";
	case kw_players:			return "kw_players";
	case tmp_players_list:		return "tmp_players_list";
	case kw_state:				return "kw_state";
	case kw_int:				return "kw_int";
	case kw_bool:				return "kw_bool";
	case kw_return:				return "kw_return";
	case identifier:			return "identifier";
	case integer:				return "integer";
	case boolean:				return "boolean";
	case syntax_char:			return "syntax_char";
	case tmp:					return "tmp";
	case game:					return "game";
	case main_rule:				return "main_rule";
	case players:				return "players";
	case players_list:			return "players_list";
	case player:				return "player";
	case state:					return "state";
	case moves:					return "moves";
	case data_set:				return "data_set";
	case var_list:				return "var_list";
	case var_list_tail:			return "var_list_tail";
	case var_declaration:		return "var_declaration";
	case var_type:				return "var_type";
	case var_definition:		return "var_definition";
	case instruction_block:		return "instruction_block";
	case instruction_list:		return "instruction_list";
	case instruction_list_tail:	return "instruction_list_tail";
	case instruction:			return "instruction";
	case assign_instr:			return "assign_instr";
	case return_instr:			return "return_instr";
	case expr:					return "expr";
	case expr_literal:			return "expr_literal";
	case expr_add:				return "expr_add";
	case expr_sub:				return "expr_sub";
	case expr_mul:				return "expr_mul";
	case expr_div:				return "expr_div";
	case expr_mod:				return "expr_mod";
	case expr_equal:			return "expr_equal";
	case expr_not_equal:		return "expr_not_equal";
	case expr_less_equal:		return "expr_less_equal";
	case expr_greater_equal:	return "expr_greater_equal";
	case expr_greater:			return "expr_greater";
	case expr_less:				return "expr_less";
	case expr_and:				return "expr_and";
	case expr_or:				return "expr_or";
	case var_reference:			return "var_reference";
	case local_scope:			return "local_scope";
	case state_scope:			return "state_scope";
	case move_scope:			return "move_scope";
	case m_rule_list:			return "m_rule_list";
	case m_rule:				return "m_rule";
	case payoff_list:			return "payoff_list";
	case payoff:				return "payoff";
	case move_list:				return "move_list";
	case move:					return "move";
	case players_scope:			return "players_scope";
	case identifier_list:		return "identifier_list";

	default: return "Name not assigned";
	}
}

void SyntaxTree_print(SyntaxTree* st, int depth)
{
	for (int i = 0; i < depth; i++) printf("  ");
	printf("%s: ", getTypeName(st->type));

	if (st->children_num == 0)
	{
		printf("%s\n", st->text);
		return;
	}
	printf("\n");

	for (int i = 0; i < st->children_num; i++)
		SyntaxTree_print(st->children[i], depth + 1);
}