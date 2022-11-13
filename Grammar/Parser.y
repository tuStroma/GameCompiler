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



%token <t> 	KW_MAIN_RULE TMP_STATE KW_MOVES
			
			KW_PLAYERS
			KW_STATE KW_INT KW_BOOL KW_RETURN
			KW_IF KW_WHILE
			IDENTIFIER INTEGER BOOLEAN 
			OPERATOR_EQUAL OPERATOR_NOT_EQUAL OPERATOR_LESS_EQUAL OPERATOR_GREATER_EQUAL OPERATOR_AND OPERATOR_OR
			TMP

%type <t> 	GAME MAIN_RULE PLAYERS STATE MOVES
			PLAYERS_LIST PLAYER
			DATA_SET VAR_LIST VAR_DECLARATION VAR_TYPE VAR_DEFINITION
			INSTRUCTION_BLOCK INSTRUCTION_LIST
			INSTRUCTION ASSIGN_INSTR RETURN_INSTR IF_INSTR EXPR
			VAR_REFERENCE SCOPE
			M_RULE_LIST M_RULE
			PAYOFF_LIST PAYOFF
			MOVE_LIST MOVE PLAYERS_SCOPE
			IDENTIFIER_LIST
			
%left OPERATOR_OR
%left OPERATOR_AND
%left OPERATOR_EQUAL OPERATOR_NOT_EQUAL
%left OPERATOR_GREATER_EQUAL OPERATOR_LESS_EQUAL '<' '>'
%left '+' '-'
%left '*' '/' '%'

%start GAME


%%

GAME: PLAYERS STATE MAIN_RULE MOVES {
	SyntaxTree* st = SyntaxTree_init(game, "", 4);
	root = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
	st->children[2] = $3;
	st->children[3] = $4;
}


// Main components

PLAYERS: KW_PLAYERS '[' PLAYERS_LIST ']'{
	SyntaxTree* st = SyntaxTree_init(players, "", 1);
	$$ = st;
	
	st->children[0] = $3;
}

STATE: KW_STATE DATA_SET '(' INSTRUCTION_BLOCK ')' {
	SyntaxTree* st = SyntaxTree_init(state, "", 2);
	$$ = st;
	
	st->children[0] = $2;
	st->children[1] = $4;
}

MAIN_RULE: KW_MAIN_RULE '[' M_RULE_LIST ']' {
	SyntaxTree* st = SyntaxTree_init(main_rule, "", 1);
	$$ = st;
	
	st->children[0] = $3;
}

MOVES: KW_MOVES '[' MOVE_LIST ']' {
	SyntaxTree* st = SyntaxTree_init(moves, "", 1);
	$$ = st;
	
	st->children[0] = $3;
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


VAR_LIST: {
	SyntaxTree* st = SyntaxTree_init(var_list_tail, "", 0);
	$$ = st;
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


// INSTRUCTIONS

INSTRUCTION_BLOCK: DATA_SET '{' INSTRUCTION_LIST '}' {
	SyntaxTree* st = SyntaxTree_init(instruction_block, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}

INSTRUCTION_LIST: {
	SyntaxTree* st = SyntaxTree_init(instruction_list_tail, "", 0);
	$$ = st;
}
| INSTRUCTION INSTRUCTION_LIST {
	SyntaxTree* st = SyntaxTree_init(instruction_list, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
}


INSTRUCTION: ASSIGN_INSTR {
	SyntaxTree* st = SyntaxTree_init(instruction, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| RETURN_INSTR {
	SyntaxTree* st = SyntaxTree_init(instruction, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| IF_INSTR {
	SyntaxTree* st = SyntaxTree_init(instruction, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}

ASSIGN_INSTR: VAR_REFERENCE '=' EXPR ';' {
	SyntaxTree* st = SyntaxTree_init(assign_instr, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}

RETURN_INSTR: KW_RETURN ';' {
	SyntaxTree* st = SyntaxTree_init(return_instr, "", 0);
	$$ = st;
}
| KW_RETURN EXPR ';' {
	SyntaxTree* st = SyntaxTree_init(return_instr, "", 1);
	$$ = st;
	
	st->children[0] = $2;
}

IF_INSTR: KW_IF '(' EXPR ')' '{' INSTRUCTION_LIST '}' {
	SyntaxTree* st = SyntaxTree_init(if_instr, "", 2);
	$$ = st;
	
	st->children[0] = $3;
	st->children[1] = $6;
}

EXPR: VAR_REFERENCE {
	SyntaxTree* st = SyntaxTree_init(expr_ref, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| VAR_DEFINITION{
	SyntaxTree* st = SyntaxTree_init(expr_literal, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| '(' EXPR ')'{
	SyntaxTree* st = SyntaxTree_init(expr, "", 1);
	$$ = st;
	
	st->children[0] = $2;
}
| EXPR '+' EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_add, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR '-' EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_sub, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR '*' EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_mul, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR '/' EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_div, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR '%' EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_mod, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}

| EXPR OPERATOR_EQUAL EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_equal, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR OPERATOR_NOT_EQUAL EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_not_equal, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR OPERATOR_GREATER_EQUAL EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_greater_equal, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR OPERATOR_LESS_EQUAL EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_greater_equal, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR '>' EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_greater, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR '<' EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_less, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR OPERATOR_AND EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_and, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}
| EXPR OPERATOR_OR EXPR{
	SyntaxTree* st = SyntaxTree_init(expr_or, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}


VAR_REFERENCE: SCOPE IDENTIFIER {
	SyntaxTree* st = SyntaxTree_init(var_reference, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
}

SCOPE: {
	SyntaxTree* st = SyntaxTree_init(local_scope, "", 0);
	$$ = st;
}
| '$' '.' {
	SyntaxTree* st = SyntaxTree_init(state_scope, "", 0);
	$$ = st;
}
| '#' '.' {
	SyntaxTree* st = SyntaxTree_init(move_scope, "", 0);
	$$ = st;
}

// MAIN_RULE

M_RULE_LIST: M_RULE {
	SyntaxTree* st = SyntaxTree_init(m_rule_list, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| M_RULE '%' M_RULE_LIST {
	SyntaxTree* st = SyntaxTree_init(m_rule_list, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}


M_RULE: IDENTIFIER '(' INSTRUCTION_BLOCK ')' PAYOFF_LIST {
	SyntaxTree* st = SyntaxTree_init(m_rule, "", 3);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
	st->children[2] = $5;
}


PAYOFF_LIST: PAYOFF {
	SyntaxTree* st = SyntaxTree_init(payoff_list, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| PAYOFF PAYOFF_LIST {
	SyntaxTree* st = SyntaxTree_init(payoff_list, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
}

PAYOFF: IDENTIFIER INSTRUCTION_BLOCK{
	SyntaxTree* st = SyntaxTree_init(payoff, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $2;
}


MOVE_LIST: MOVE {
	SyntaxTree* st = SyntaxTree_init(move_list, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| MOVE '%' MOVE_LIST {
	SyntaxTree* st = SyntaxTree_init(move_list, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}

MOVE: IDENTIFIER '<' PLAYERS_SCOPE '>' DATA_SET '(' INSTRUCTION_BLOCK ')' INSTRUCTION_BLOCK{
	SyntaxTree* st = SyntaxTree_init(move, "", 5);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
	st->children[2] = $5;
	st->children[3] = $7;
	st->children[4] = $9;
}

PLAYERS_SCOPE: '*'  {
	SyntaxTree* st = SyntaxTree_init(players_scope, "", 0);
	$$ = st;
}
| IDENTIFIER_LIST {
	SyntaxTree* st = SyntaxTree_init(players_scope, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}

IDENTIFIER_LIST: IDENTIFIER {
	SyntaxTree* st = SyntaxTree_init(identifier_list, "", 1);
	$$ = st;
	
	st->children[0] = $1;
}
| IDENTIFIER ',' IDENTIFIER_LIST {
	SyntaxTree* st = SyntaxTree_init(identifier_list, "", 2);
	$$ = st;
	
	st->children[0] = $1;
	st->children[1] = $3;
}



// TMP { SyntaxTree* st = SyntaxTree_init(tmp, "", 1); $$ = st; st->children[0] = $1; }

%%

SyntaxTree* parser_main(char *file_path)
{
	FILE *fp = NULL;
	
	fopen_s(&fp, file_path, "rb");

	if (fp == NULL)
	{
		perror("Failed to open file");
		return NULL;
	}
	else
	{
		yyin = fp;
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
