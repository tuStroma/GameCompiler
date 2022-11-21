#include <iostream>

#include "Grammar/Common.h"
#include "Grammar/Parser.tab.h"
#include "Game/Compiler.h"

extern "C" SyntaxTree* parser_main(char* file_path);


void parse_test()
{
	char path[20] = "Source/source.txt";
	SyntaxTree* st = parser_main(path);
	SyntaxTree_print(st, 0);

	std::cout << "\n\n";

	Compiler compiler = Compiler();
	compiler.createGame(st);
}

void DataSet_test()
{
	int size = 0;
	size += sizeof(bool);
	size += sizeof(int);
	size += sizeof(double);

	std::cout << "Size: " << size << '\n';

	DataSet* ds = new DataSet(size);

	ds->defineVariable("b", VAR_TYPE::UNKNOWN, sizeof(bool));
	ds->defineVariable("i", VAR_TYPE::UNKNOWN, sizeof(int));
	ds->defineVariable("d", VAR_TYPE::UNKNOWN, sizeof(double));

	*(bool*)(ds->getValuePtr("b")) = true;
	*(int*)(ds->getValuePtr("i")) = 7;
	*(double*)(ds->getValuePtr("d")) = 1.5;

	std::cout << "Int: \t" << *(int*)(ds->getValuePtr("i")) << "\nBool: \t" << *(bool*)(ds->getValuePtr("b")) << "\nDouble: \t" << *(double*)(ds->getValuePtr("d")) << '\n';


	//ds->~DataSet();
}


int main(int argc, char* argv[])
{
	//parse_test();
	//DataSet_test();

	Game* game = Compiler().createGame("Source/source.txt");

	return 0;
}