#include "DataSet.h"

DataSet::DataSet(int size)
{
	data = malloc(size);
	if (data == NULL)
	{
		std::cout << "Memory allocation error\n";
		exit(1);
	}

	data_size = size;
}

DataSet::~DataSet()
{
	free(data);
}

bool DataSet::exist(std::string name)
{
	return map.find(name) != map.end();
}

bool DataSet::defineVariable(std::string name, VAR_TYPE type, int size)
{
	if (bits_taken + size > data_size)
		return false;

	if (exist(name))
		return false;

	map[name] = variable(bits_taken, type);
	bits_taken += size;

	return true;
}

void* DataSet::getValuePtr(std::string name)
{
	if (!exist(name))
	{
		std::cout << "Warning: Not found identifier \"" << name << "\" in scope\n";
		return nullptr;
	}

	int data_index = map.at(name).pointer;
	return (char*)data + data_index;
}

VAR_TYPE DataSet::getValueType(std::string name)
{
	if (!exist(name))
	{
		std::cout << "Warning: Not found identifier \"" << name << "\" in scope\n";
		return VAR_TYPE::UNKNOWN;
	}

	return map.at(name).type;
}

void DataSet::setInt(std::string name, int value)
{
	if (!exist(name))
	{
		std::cout << "Warning: Not found identifier \"" << name << "\" in scope\n";
		return;
	}
	variable var = map.at(name);

	if (var.type == VAR_TYPE::INT)
		*(int*)((char*)data + var.pointer) = value;

	else
		std::cout << "Warning: Idetifier is not type INT\n";
}

void DataSet::setBool(std::string name, bool value)
{
	if (!exist(name))
	{
		std::cout << "Warning: Not found identifier \"" << name << "\" in scope\n";
		return;
	}
	variable var = map.at(name);

	if (var.type == VAR_TYPE::BOOL)
		*(bool*)((char*)data + var.pointer) = value;

	else
		std::cout << "Warning: Idetifier is not type BOOL\n";
}

void DataSet::print()
{
	for (std::pair<const std::string, variable>& kv : map)
	{
		const std::string& name = kv.first;
		variable& var = kv.second;

		std::cout << VarTypeToString(var.type) << ' ' << name << ' ' << getStringValue(getValuePtr(name), var.type) << '\n';
	}
}


Variable::Variable(VAR_TYPE type)
	: type(type)
{
	switch (type)
	{
	case VAR_TYPE::INT:		value_ptr = malloc(sizeof(int)); break;
	case VAR_TYPE::BOOL:	value_ptr = malloc(sizeof(bool)); break;
	default: value_ptr = NULL;
	}
}

bool Variable::setValueInt(int value)
{
	if (type != VAR_TYPE::INT)
		return false;

	*(int*)value_ptr = value;
	return true;
}

bool Variable::setValueBool(bool value)
{
	if (type != VAR_TYPE::BOOL)
		return false;

	*(bool*)value_ptr = value;
	return true;
}

void* Variable::getValue()
{
	return value_ptr;
}

int Variable::getValueInt()
{
	if (type != VAR_TYPE::INT)
	{
		std::cout << "Warnig: Wrong type requested. Current type: " << VarTypeToString(type) << " \tRequested: INT\n";
		return 0;
	}
	return *(int*)value_ptr;
}

bool Variable::getValueBool()
{
	if (type != VAR_TYPE::BOOL)
	{
		std::cout << "Warnig: Wrong type requested. Current type: " << VarTypeToString(type) << " \tRequested: BOOL\n";
		return 0;
	}
	return *(bool*)value_ptr;
}

VAR_TYPE Variable::getType()
{
	return type;
}
