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

MOVES {
	yylval.t = SyntaxTree_init(moves, yytext, 0);
	
	return KW_MOVES;
}


INT {
	yylval.t = SyntaxTree_init(kw_int, yytext, 0);
	
	return KW_INT;
}

BOOL {
	yylval.t = SyntaxTree_init(kw_bool, yytext, 0);
	
	return KW_BOOL;
}

RETURN {
	yylval.t = SyntaxTree_init(kw_return, yytext, 0);
	
	return KW_RETURN;
}

IF {
	yylval.t = SyntaxTree_init(kw_if, yytext, 0);
	
	return KW_IF;
}

WHILE {
	yylval.t = SyntaxTree_init(kw_while, yytext, 0);
	
	return KW_WHILE;
}


"==" { return OPERATOR_EQUAL; }

"!=" { return OPERATOR_NOT_EQUAL; }

"<=" { return OPERATOR_LESS_EQUAL; }

">=" { return OPERATOR_GREATER_EQUAL; }

"&&" { return OPERATOR_AND; }

"||" { return OPERATOR_OR; }


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



TMP {
	yylval.t = SyntaxTree_init(tmp, yytext, 0);
	
	return TMP;
}



[a-zA-Z_][a-zA-Z0-9_]* {
	yylval.t = SyntaxTree_init(identifier, yytext, 0);
	
	return IDENTIFIER;
}


[\[\]{}<>()+\-*/=,;%$#\.] {
	yylval.t = SyntaxTree_init(syntax_char, yytext, 0);
	
	return yytext[0];
}


[ \t\n] { }

%%
