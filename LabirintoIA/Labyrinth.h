#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Context.h"

class Labyrinth
{
public:
	Labyrinth(std::vector<std::string> labyrinthLayout);
	void receiveMovement(Coordinate movementPlace);
	Context getCurrentContext();
	Context getGoalContext();
	bool solutionFound();
	void showSolution(std::vector<Context> contexts);

private:
	void updateContext();
	Coordinate findSpot(char spot);
	std::vector<std::string> m_labyrinth;
	std::vector<std::string> l_labyrinth;
	Context m_currentContext;
	Context m_goalContext;
};

