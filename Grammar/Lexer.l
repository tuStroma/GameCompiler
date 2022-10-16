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

[a-zA-Z_][a-zA-Z0-9_]* {
	yylval.t = SyntaxTree_init(id, yytext, 0);
	//yylval.t = st;
	
	return ID;
}

\+ {
	SyntaxTree* st = SyntaxTree_init(op_add, yytext, 0);
	yylval.t = st;
	
	return '+';
}

\* {
	SyntaxTree* st = SyntaxTree_init(op_mul, yytext, 0);
	yylval.t = st;
	
	return '*';
}

\( {
	SyntaxTree* st = SyntaxTree_init(open, yytext, 0);
	yylval.t = st;
	
	return '(';
}

\) {
	SyntaxTree* st = SyntaxTree_init(close, yytext, 0);
	yylval.t = st;
	
	return ')';
}


. { }

%%
