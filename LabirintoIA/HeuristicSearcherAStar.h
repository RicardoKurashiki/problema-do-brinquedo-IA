#pragma once
#include "Searcher.h"
#include <vector>
#include <map>

class HeuristicSearcherAStar : public Searcher
{
public:
	HeuristicSearcherAStar();
	void receiveContext(Context recContext);
	void receiveStartContext(Context startContext);
	void receiveGoalContext(Context goalContext);
	Coordinate makeMovement();
	void handle();
	std::vector<Context> m_contextHistory;
private:
	void removeMovePossibilities(Context& context, char move);
	double heuristic(Coordinate goal, Coordinate move);
	char m_lastMovement;
	std::map<char, double> gridValues;
	Context m_startContext;
	Context m_goalContext;
};

