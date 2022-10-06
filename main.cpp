#include <iostream>
extern "C" int parser_main(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	char* tab[2];
	char str[20] = "Source/source.txt";
	tab[1] = str;
	return parser_main(2, tab);
}