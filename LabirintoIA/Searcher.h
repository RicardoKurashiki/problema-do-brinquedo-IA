#pragma once

#include "Context.h"
#include <iostream>

class Searcher
{
public:
	Searcher() {};
	virtual void receiveContext(Context recContext) = 0;
	virtual Coordinate makeMovement() = 0;
	virtual void handle() = 0;
};

