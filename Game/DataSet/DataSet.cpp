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

bool DataSet::defineVariable(std::string name, int size)
{
	if (bits_taken + size > data_size)
		return false;

	if (exist(name))
		return false;

	map[name] = bits_taken;
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

	int data_index = map.at(name);
	return (char*)data + data_index;
}
