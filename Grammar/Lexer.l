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

[0-9]+ {
	SyntaxTree* st = SyntaxTree_init(Elem, yytext, 0);
	yylval.t = st;
	
	return ELEM;
}

. { }

%%
