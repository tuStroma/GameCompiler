#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

#include "VarType.h"

// Class contains set of variables,
// they are stored in the main table
// and referenced by name
class DataSet
{
private:

	struct variable {
		int pointer;
		VAR_TYPE type;


		variable() 
			: pointer(0), type(VAR_TYPE::UNKNOWN)
		{}
		variable(int pointer, VAR_TYPE type)
			: pointer(pointer), type(type)
		{}
	};

	// Stores mixed data of set
	void* data = NULL;
	int data_size = 0;
	int bits_taken = 0;

	// Maps data in 'data' table with its name
	std::unordered_map<std::string, variable> map;

	bool exist(std::string name);

public:
	// Allocates memory for 'data' table
	DataSet(int size);
	~DataSet();

	bool defineVariable(std::string name, VAR_TYPE type, int size);

	void* getValuePtr(std::string name);
	VAR_TYPE getValueType(std::string name);


	void print();

};


class Variable
{
private:
	void* value_ptr;
	VAR_TYPE type;

public:
	Variable(VAR_TYPE type);

	bool setValueInt(int value);
	bool setValueBool(bool value);

	void* getValue();
	int getValueInt();
	bool getValueBool();
	VAR_TYPE getType();
};
