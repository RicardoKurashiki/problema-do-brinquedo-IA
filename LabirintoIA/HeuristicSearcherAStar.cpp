#include "HeuristicSearcherAStar.h"

HeuristicSearcherAStar::HeuristicSearcherAStar()
{
	m_lastMovement = 'Z';
	m_minElementIndex = 0;
}

void HeuristicSearcherAStar::receiveContext(Context recContext)
{
	removeMovePossibilitie(recContext, m_lastMovement);
	calculatedDistanceFromObjective(recContext);
	m_contextHistory.push_back(recContext);
}

Coordinate HeuristicSearcherAStar::makeMovement()
{
	Coordinate coord;
	char movementChosen;

	movementChosen = m_contextHistory[m_minElementIndex].getMovements()[0];
	coord = m_contextHistory[m_minElementIndex].getPosition();
	coord.move(movementChosen);

	/**
	 * Quando o algoritmo fizer um movimento, armazenar (N, S, W, E) e excluir como possibilidade do contexto gerado por ele.
	 * Também remover do contexto final do momento o movimento realizado por ele.
	 */
	removeMovePossibilitie(m_contextHistory[m_minElementIndex], movementChosen);

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
	if (m_contextHistory[m_minElementIndex].getMovements().empty())
	{
		std::cout << "Eliminou index: " << m_minElementIndex << std::endl;
		m_contextHistory.erase(m_contextHistory.begin() + m_minElementIndex);
		m_distanceFromObjective.erase(m_distanceFromObjective.begin() + m_minElementIndex);
		m_minElementIndex = std::min_element(m_distanceFromObjective.begin(), m_distanceFromObjective.end()) - m_distanceFromObjective.begin();
	}

	std::cout << " ---- Min Element Properties --- " << std::endl << std::endl;
	std::cout << "Line: " << m_contextHistory[m_minElementIndex].getPosition().getLine() << " | Column: " << m_contextHistory[m_minElementIndex].getPosition().getColumn() << std::endl;
	std::cout << "Movements: " << m_contextHistory[m_minElementIndex].getMovements() << std::endl;
	std::cout << "Index: " << m_minElementIndex << std::endl;
	std::cout << "Distance to objective: " << m_distanceFromObjective[m_minElementIndex] << std::endl;
}

void HeuristicSearcherAStar::removeMovePossibilitie(Context& context, char move)
{
	std::size_t charPosition = context.getMovements().find(move);

	if (charPosition != std::string::npos)
	{
		std::string newPosMovs = context.getMovements();
		newPosMovs.erase(charPosition, 1);
		context.setMovements(newPosMovs);
	}
}

void HeuristicSearcherAStar::calculatedDistanceFromObjective(Context context)
{
	Coordinate contextCoord = context.getPosition();
	
	int lineDistance = abs(contextCoord.getLine() - m_objectiveCoordinate.getLine());
	int columnDistance = abs(contextCoord.getColumn() - m_objectiveCoordinate.getColumn());

	m_distanceFromObjective.push_back(lineDistance + columnDistance);
}

void HeuristicSearcherAStar::setObjectiveCoordinate(Coordinate objectiveCoordinate)
{
	m_objectiveCoordinate = objectiveCoordinate;
}
