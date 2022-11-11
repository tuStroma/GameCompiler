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
		std::cout << "not found\n";
		return nullptr;
	}

	int data_index = map.at(name).pointer;
	return (char*)data + data_index;
}

VAR_TYPE DataSet::getValueType(std::string name)
{
	if (!exist(name))
	{
		std::cout << "not found\n";
		return VAR_TYPE::UNKNOWN;
	}

	return map.at(name).type;
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
