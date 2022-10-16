#include "Common.h"


void SyntaxTree_print(SyntaxTree* st, int depth)
{
	const char* symbols[] = { "id", "op_add", "op_mul", "open", "close", "expr" };

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