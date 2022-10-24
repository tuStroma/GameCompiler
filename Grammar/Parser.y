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



%token <t> 	TMP_MAIN_RULE TMP_STATE TMP_MOVES 
			
			KW_PLAYERS
			KW_STATE KW_INT KW_BOOL 
			IDENTIFIER INTEGER BOOLEAN

%type <t> 	GAME MAIN_RULE PLAYERS STATE MOVES
			PLAYERS_LIST PLAYER
			DATA_SET VAR_LIST VAR_DECLARATION VAR_TYPE VAR_DEFINITION

%start GAME


%%

GAME: MAIN_RULE PLAYERS STATE MOVES {
	SyntaxTree* st = SyntaxTree_init(game, "", 4);
	root = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
	st->children[2] = $3;
	st->children[3] = $4;
}


// Main components

MAIN_RULE: TMP_MAIN_RULE {
	SyntaxTree* st = SyntaxTree_init(main_rule, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}

PLAYERS: KW_PLAYERS '[' PLAYERS_LIST ']'{
	SyntaxTree* st = SyntaxTree_init(players, "", 1);
	$$ = st;
	
	st->children[0] = $3;
}

STATE: KW_STATE DATA_SET {
	SyntaxTree* st = SyntaxTree_init(state, "", 1);
	$$ = st;
	
	st->children[0] = $2;
}

MOVES: TMP_MOVES {
	SyntaxTree* st = SyntaxTree_init(moves, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}


// Players

PLAYERS_LIST: PLAYER {
	SyntaxTree* st = SyntaxTree_init(players_list, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| PLAYER PLAYERS_LIST {
	SyntaxTree* st = SyntaxTree_init(players_list, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
}

PLAYER: IDENTIFIER '[' INTEGER ']' ';' {
	SyntaxTree* st = SyntaxTree_init(player, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}


// Data

DATA_SET: '[' VAR_LIST ']' {
	SyntaxTree* st = SyntaxTree_init(data_set, "", 1);
	$$ = st;
	
	st->children[0] = $2;
}

VAR_LIST: VAR_DECLARATION {
	SyntaxTree* st = SyntaxTree_init(var_list, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| VAR_DECLARATION VAR_LIST {
	SyntaxTree* st = SyntaxTree_init(var_list, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
}

VAR_DECLARATION: VAR_TYPE IDENTIFIER '=' VAR_DEFINITION ';' {
	SyntaxTree* st = SyntaxTree_init(var_declaration, "", 3);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
	st->children[2] = $4;
}

VAR_TYPE: KW_INT {
	SyntaxTree* st = SyntaxTree_init(var_type, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| KW_BOOL {
	SyntaxTree* st = SyntaxTree_init(var_type, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
	
VAR_DEFINITION: INTEGER {
	SyntaxTree* st = SyntaxTree_init(var_definition, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| BOOLEAN {
	SyntaxTree* st = SyntaxTree_init(var_definition, "", 1);
	$$ = st;
	
	st->children[0] = $1;
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
