#pragma once

#include <list>
#include "MainRule/EndRule.h"

class MainRule
{
private:
	std::list<EndRule*> end_rules;

public:
	MainRule(std::list<EndRule*> end_rules);

	bool Run();

};

