#include "Common.h"


void SyntaxTree_print(SyntaxTree* st, int depth)
{
	const char* symbols[] = { "tmp_main_rule", "tmp_state", "tmp_moves", "kw_state", "kw_int", "kw_bool", "identifier", "integer", "boolean", "syntax_char",

	"game", "main_rule", "state", "moves",
	"data_set", "var_list", "var_declaration", "var_type", "var_definition" };

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