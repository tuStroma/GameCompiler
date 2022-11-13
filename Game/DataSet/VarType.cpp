#include "VarType.h"

VAR_TYPE stringToVarType(std::string type)
{
	if (type == "INT")			return VAR_TYPE::INT;
	else if (type == "BOOL")	return VAR_TYPE::BOOL;

	std::cout << "Error: unknown type:\t" << type << '\n';
	return VAR_TYPE::UNKNOWN;
}

std::string VarTypeToString(VAR_TYPE type)
{
	switch (type)
	{
	case VAR_TYPE::INT:		return "INT";
	case VAR_TYPE::BOOL:	return "BOOL";
	case VAR_TYPE::VOID:	return "VOID";
	default:				return "UNKNOWN";
	}
}

int getTypeSize(std::string type)
{
	if (type == "INT")			return sizeof(int);
	else if (type == "BOOL")	return sizeof(bool);

	else	std::cout << "Error: unknown type:\t" << type << '\n';

	return 0;
}

std::string getStringValue(void* ptr, VAR_TYPE type)
{
	switch (type)
	{
	case VAR_TYPE::INT:		return std::to_string(*(int*)ptr);
	case VAR_TYPE::BOOL:	return (*(bool*)ptr) ? "true" : "false";
	default:				return "";
	}
}
