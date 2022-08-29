#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Context.h"

class Labyrinth
{
public:
	Labyrinth();
	void receiveMovement(Coordinate movementPlace);
	Context getCurrentContext();
	bool solutionFound();

private:
	void updateContext();

	std::vector<std::string> m_labyrinth;
	Context m_currentContext;
};

