#include <iostream>
#include "Grammar/Common.h"
#include "Grammar/Parser.tab.h"
extern "C" SyntaxTree* parser_main(int argc, char* argv[]);


int main(int argc, char* argv[])
{
	char* tab[2];
	char str[20] = "Source/source.txt";
	tab[1] = str;
	SyntaxTree* st = parser_main(2, tab);
	SyntaxTree_print(st, 0);


	return 0;
}