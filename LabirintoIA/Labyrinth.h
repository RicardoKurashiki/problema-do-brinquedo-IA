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
	Context getGoalContext();
	bool solutionFound();

private:
	void updateContext();
	Coordinate findSpot(char spot);

	std::vector<std::string> m_labyrinth;
	Context m_currentContext;
	Context m_goalContext;
};

