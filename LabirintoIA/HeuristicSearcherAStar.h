#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "Searcher.h"

class HeuristicSearcherAStar : public Searcher
{
public:
	HeuristicSearcherAStar();
	void receiveContext(Context recContext);
	Coordinate makeMovement();
	void handle();
	void setObjectiveCoordinate(Coordinate objectiveCoordinate);
private:
	void removeMovePossibilitie(Context& context, char move);
	void calculatedDistanceFromObjective(Context context);

	std::vector<Context> m_contextHistory;
	std::vector<int> m_distanceFromObjective;
	char m_lastMovement;
	Coordinate m_objectiveCoordinate;
	int m_minElementIndex;
	std::vector<int>::iterator m_minElementIt;
};

