#pragma once

#include "Context.h"
#include <iostream>

class Searcher
{
public:
	Searcher() { m_solutionFinded = false; };
	void receiveContext(Context recContext);
	Coordinate makeMovement();
	void think();
private:
	Context m_currentPlace;
	bool m_solutionFinded;
};

