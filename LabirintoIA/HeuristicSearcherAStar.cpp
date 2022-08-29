#include "HeuristicSearcherAStar.h"

HeuristicSearcherAStar::HeuristicSearcherAStar()
{
	gridValues.clear();
	m_lastMovement = 'Z';
}

void HeuristicSearcherAStar::receiveContext(Context recContext)
{
	removeMovePossibilities(recContext, m_lastMovement);
	m_contextHistory.push_back(recContext);
}


void HeuristicSearcherAStar::receiveGoalContext(Context goalContext)
{
	m_goalContext = goalContext;
}

void  HeuristicSearcherAStar::receiveStartContext(Context startContext) 
{
	m_startContext = startContext;
}

Coordinate HeuristicSearcherAStar::makeMovement()
{
	gridValues.clear();
	char movementChosen = m_lastMovement;
	Coordinate coord;
	Coordinate nextCoord;

	while (m_contextHistory.back().getMovements().empty())
		m_contextHistory.pop_back();

	Context lastContext = m_contextHistory.back();
	Coordinate contextPos = lastContext.getPosition();
	std::string contextMovements = lastContext.getMovements();

	coord = lastContext.getPosition();

	double h_n, g_n;

	for (char m : contextMovements)
	{
		h_n = 0;
		g_n = 0;
		switch (m)
		{
		case 'N':
			nextCoord = Coordinate(contextPos.getLine(), contextPos.getColumn() - 1);
			h_n = heuristic(m_goalContext.getPosition(), nextCoord);
			g_n = heuristic(nextCoord, m_startContext.getPosition());
			gridValues['N'] = (g_n + h_n);
			break;
		case 'S':
			nextCoord = Coordinate(contextPos.getLine(), contextPos.getColumn() + 1);
			h_n = heuristic(m_goalContext.getPosition(), nextCoord);
			g_n = heuristic(nextCoord, m_startContext.getPosition());
			gridValues['S'] = (g_n + h_n);
			break;
		case 'E':
			nextCoord = Coordinate(contextPos.getLine() + 1, contextPos.getColumn());
			h_n = heuristic(m_goalContext.getPosition(), nextCoord);
			g_n = heuristic(nextCoord, m_startContext.getPosition());
			gridValues['E'] = (g_n + h_n);
			break;
		case 'W':
			nextCoord = Coordinate(contextPos.getLine() - 1, contextPos.getColumn());
			h_n = heuristic(m_goalContext.getPosition(), nextCoord);
			g_n = heuristic(nextCoord, m_startContext.getPosition());
			gridValues['W'] = (g_n + h_n);
			break;
		default:
			break;
		}
	}

	double minValue = (double)INT_MAX;
	std::map<char, double>::iterator it;
	for (it = gridValues.begin(); it != gridValues.end(); ++it) {
		if (it->second < minValue)
			minValue = it->second;
	}

	for (it = gridValues.begin(); it != gridValues.end(); ++it)
	{
		if (minValue == it->second)
		{
			movementChosen = it->first;
			break;
		}
	}

	coord.move(movementChosen);

	m_contextHistory.pop_back();

	removeMovePossibilities(lastContext, movementChosen);

	m_contextHistory.push_back(lastContext);

	switch (movementChosen)
	{
	case 'N':
		m_lastMovement = 'S';
		break;
	case 'S':
		m_lastMovement = 'N';
		break;
	case 'W':
		m_lastMovement = 'E';
		break;
	case 'E':
		m_lastMovement = 'W';
		break;
	default:
		break;
	}

	return coord;
}

void HeuristicSearcherAStar::handle()
{

}

void HeuristicSearcherAStar::removeMovePossibilities(Context& context, char move)
{
	std::size_t charPosition = context.getMovements().find(move);

	if (charPosition != std::string::npos)
	{
		std::string newPosMovs = context.getMovements();
		newPosMovs.erase(charPosition, 1);
		context.setMovements(newPosMovs);
	}
}

double HeuristicSearcherAStar::heuristic(Coordinate goal, Coordinate move)
{
	return (abs(goal.getLine() - move.getLine()) + abs(goal.getColumn() - move.getColumn()));
}