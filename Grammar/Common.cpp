#include "Common.h"


void SyntaxTree_print(SyntaxTree* st, int depth)
{
	const char* symbols[] = { 
	"kw_main_rule", "tmp_state", "tmp_moves", 
	"kw_players", "tmp_players_list", 
	"kw_state", "kw_int", "kw_bool", 
	"identifier", "integer", "boolean", "syntax_char", 
	"instrubtion",
	"tmp",

	"game", "main_rule", "players", "players_list", "player", "state", "moves",
	"data_set", "var_list", "var_declaration", "var_type", "var_definition",
	"instruction_block", "instruction_list",
	"m_rule_list", "m_rule",
	"payoff_list", "payoff",
	"move_list", "move", "players_scope",
	"identifier_list" };

	for (int i = 0; i < depth; i++) printf("  ");
	printf("%s: ", symbols[st->type]);

	if (st->children_num == 0)
	{
		printf("%s\n", st->text);
		return;
	}
	printf("\n");

	for (int i = 0; i < st->children_num; i++)
		SyntaxTree_print(st->children[i], depth + 1);
}