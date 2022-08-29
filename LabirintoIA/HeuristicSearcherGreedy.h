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
private:
	void removeMovePossibilities(Context& context, char move);
	double heuristic(Coordinate goal, Coordinate move);
	std::vector<Context> m_contextHistory;
	char m_lastMovement;
	std::vector<double> gridValues;
	Context m_goalContext;
};

