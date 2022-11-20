#include "MainRule.h"

MainRule::MainRule(std::list<EndRule*> end_rules)
	: end_rules(end_rules)
{}

bool MainRule::Run()
{
	for (EndRule* rule : end_rules)
		if (rule->Run())
			return true;

	return false;
}
