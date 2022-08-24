#pragma once

#include <stack>
#include "Context.h"

class Controller
{
public:
	std::stack<Context> stackContext;
	void addContext(Context c);
	Context move(char movement);
};