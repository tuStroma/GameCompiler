%{

#include <stdio.h>
#include "Common.h"

FILE *yyin;
int yyerror();
SyntaxTree* SyntaxTree_init(Type type, const char* text, int children);

extern int yylex();

SyntaxTree* root;

%}

%union symval {
	struct SyntaxTree* t;
};

%token <t> ELEM
%type <t> LIST


%%

LIST: ELEM {
	SyntaxTree* st = SyntaxTree_init(List, "", 1);
	yylval.t = st;
	
	st->children[0] = $1;
	
	$$ = st;
	root = st;
}

| LIST ELEM {
	SyntaxTree* st = SyntaxTree_init(List, "", 2);
	yylval.t = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
	
	$$ = st;
	root = st;
}

%%

SyntaxTree* parser_main(int argc, char *argv[])
{
	FILE *fp = NULL;
	if (argc == 2)
	{
		fopen_s(&fp, argv[1], "rb");

		if (fp == NULL)
		{
			perror("Failed to open file");
			return NULL;
		}
		else
		{
			yyin = fp;
		}
	}

	yyparse();

	if (fp != NULL)
	{
		fclose(fp);
	}

	return root;
}

int yyerror(const char *p) {

	printf("%s\n", p);
	return 0;
}

SyntaxTree* SyntaxTree_init(Type type, const char* text, int children)
{
	SyntaxTree* st = (SyntaxTree*)malloc(sizeof(SyntaxTree));
	if (st == NULL) { printf("Memry allocation error\n"); exit(-1); }

	st->children =(SyntaxTree**) malloc(sizeof(SyntaxTree) * children);
	if (st->children == NULL) { printf("Memry allocation error\n"); exit(-1); }

	st->type = type;
	st->children_num = children;
	
	st->text = calloc(strlen(text) + 1, 1);
	strcpy_s(st->text, strlen(text) + 1, text);

	return st;
}
