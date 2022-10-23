#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

// Class contains set of variables,
// they are stored in the main table
// and referenced by name
class DataSet
{
private:

	// Stores mixed data of set
	void* data = NULL;
	int data_size = 0;
	int bits_taken = 0;

	// Maps data in 'data' table with its name
	std::unordered_map<std::string, int> map;

	bool exist(std::string name);

public:
	// Allocates memory for 'data' table
	DataSet(int size);
	~DataSet();

	bool defineVariable(std::string name, int size);

	void* getValuePtr(std::string name);

};

