#pragma once
#include "Searcher.h"
#include <vector>

class HeuristicSearcherGreedy : public Searcher
{
public:
	HeuristicSearcherGreedy();
	void receiveContext(Context recContext);
	void receiveGoalContext(Context goalContext);
	Coordinate makeMovement();
	void handle();
	std::vector<Context> m_contextHistory;
private:
	void removeMovePossibilities(Context& context, char move);
	double heuristic(Coordinate goal, Coordinate move);
	char m_lastMovement;
	std::vector<double> gridValues;
	Context m_goalContext;
};

