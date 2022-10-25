%{

#include "Parser.tab.h"
#include "Common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define fileno _fileno

%}

%option noyywrap

%%


PLAYERS {
	yylval.t = SyntaxTree_init(kw_players, yytext, 0);
	
	return KW_PLAYERS;
}

STATE {
	yylval.t = SyntaxTree_init(kw_state, yytext, 0);
	
	return KW_STATE;
}


MAIN_RULE {
	yylval.t = SyntaxTree_init(main_rule, yytext, 0);
	
	return KW_MAIN_RULE;
}

INT {
	yylval.t = SyntaxTree_init(kw_int, yytext, 0);
	
	return KW_INT;
}

BOOL {
	yylval.t = SyntaxTree_init(kw_bool, yytext, 0);
	
	return KW_BOOL;
}



[0-9]+ {
	yylval.t = SyntaxTree_init(integer, yytext, 0);
	
	return INTEGER;
}


(true)|(false) {
	yylval.t = SyntaxTree_init(boolean, yytext, 0);
	
	return BOOLEAN;
}


TMP_STATE {
	yylval.t = SyntaxTree_init(state, yytext, 0);
	
	return TMP_STATE;
}

TMP_MOVES {
	yylval.t = SyntaxTree_init(moves, yytext, 0);
	
	return TMP_MOVES;
}

TMP_INSTRUCTION {
	yylval.t = SyntaxTree_init(instruction, yytext, 0);
	
	return INSTRUCTION;
}

TMP {
	yylval.t = SyntaxTree_init(tmp, yytext, 0);
	
	return TMP;
}



[a-zA-Z_][a-zA-Z0-9_]* {
	yylval.t = SyntaxTree_init(identifier, yytext, 0);
	
	return IDENTIFIER;
}


[\[\]{}=;] {
	yylval.t = SyntaxTree_init(syntax_char, yytext, 0);
	
	return yytext[0];
}


[ \t\n] { }

%%
