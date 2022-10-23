#pragma once

#include <iostream>
#include <string>

enum class VAR_TYPE
{
	INT,
	BOOL,

	UNKNOWN

};

VAR_TYPE stringToVarType(std::string type);
std::string VarTypeToString(VAR_TYPE type);

int getTypeSize(std::string type);

std::string getStringValue(void* ptr, VAR_TYPE type);