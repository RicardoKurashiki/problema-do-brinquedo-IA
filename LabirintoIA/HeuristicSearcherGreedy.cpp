#include "HeuristicSearcherGreedy.h"

HeuristicSearcherGreedy::HeuristicSearcherGreedy()
{
	gridValues.clear();
	m_lastMovement = 'Z';
}

void HeuristicSearcherGreedy::receiveContext(Context recContext)
{
	removeMovePossibilities(recContext, m_lastMovement);
	m_contextHistory.push_back(recContext);
}

void HeuristicSearcherGreedy::receiveGoalContext(Context goalContext) 
{
	m_goalContext = goalContext;
}

Coordinate HeuristicSearcherGreedy::makeMovement()
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

	for (char m : contextMovements)
	{
		switch (m)
		{
		case 'N':
			nextCoord = Coordinate(contextPos.getLine(), contextPos.getColumn() - 1);
			gridValues.push_back(heuristic(m_goalContext.getPosition(), nextCoord));
			break;
		case 'S':
			nextCoord = Coordinate(contextPos.getLine(), contextPos.getColumn() + 1);
			gridValues.push_back(heuristic(m_goalContext.getPosition(), nextCoord));
			break;
		case 'E':
			nextCoord = Coordinate(contextPos.getLine() + 1, contextPos.getColumn());
			gridValues.push_back(heuristic(m_goalContext.getPosition(), nextCoord));
			break;
		case 'W':
			nextCoord = Coordinate(contextPos.getLine() - 1, contextPos.getColumn());
			gridValues.push_back(heuristic(m_goalContext.getPosition(), nextCoord));
			break;
		default:
			break;
		}
	}

	double minValue = (double)INT_MAX;
	for (int i = 0; i < gridValues.size(); i++)
	{
		if (gridValues[i] < minValue)
			minValue = gridValues[i];
	}

	for (int i = 0; i < gridValues.size(); i++)
	{
		if (minValue == gridValues[i])
		{
			movementChosen = contextMovements[i];
			break;
		}
	}
	/*
	//ESCOLHAS FEITAS PELO PROGRAMA
	for (int i = 0; i < gridValues.size(); i++)
	{
		std::cout << contextMovements[i] << ": " << gridValues[i] << std::endl;
	}

	std::cout << "ESCOLHI IR PARA " << movementChosen << " COM VALOR DE " << minValue << std::endl;
	*/

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

void HeuristicSearcherGreedy::handle()
{

}

void HeuristicSearcherGreedy::removeMovePossibilities(Context& context, char move)
{
	std::size_t charPosition = context.getMovements().find(move);

	if (charPosition != std::string::npos)
	{
		std::string newPosMovs = context.getMovements();
		newPosMovs.erase(charPosition, 1);
		context.setMovements(newPosMovs);
	}
}

double HeuristicSearcherGreedy::heuristic(Coordinate goal, Coordinate move)
{
	return (abs(goal.getLine() - move.getLine()) + abs(goal.getColumn() - move.getColumn()));
}