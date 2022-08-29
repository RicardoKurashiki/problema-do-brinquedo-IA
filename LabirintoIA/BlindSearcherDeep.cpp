#include "BlindSearcherDeep.h"

BlindSearcherDeep::BlindSearcherDeep()
{
	m_lastMovement = 'Z';
}

void BlindSearcherDeep::receiveContext(Context recContext)
{
	removeMovePossibilitie(recContext, m_lastMovement);
	m_contextHistory.push_back(recContext);
}

Coordinate BlindSearcherDeep::makeMovement()
{
	Coordinate coord;
	char movementChosen;

	while (m_contextHistory.back().getMovements().empty())
		m_contextHistory.pop_back();

	Context lastContext = m_contextHistory.back();

	movementChosen = lastContext.getMovements()[0];
	coord = lastContext.getPosition();
	coord.move(movementChosen);

	/**
	 * Quando o algoritmo fizer um movimento, armazenar (N, S, W, E) e excluir como possibilidade do contexto gerado por ele.
	 * Também remover do contexto final do momento o movimento realizado por ele.
	 */

	m_contextHistory.pop_back();

	removeMovePossibilitie(lastContext, movementChosen);

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

void BlindSearcherDeep::handle()
{

}

void BlindSearcherDeep::removeMovePossibilitie(Context& context, char move)
{
	std::size_t charPosition = context.getMovements().find(move);

	if (charPosition != std::string::npos)
	{
		std::string newPosMovs = context.getMovements();
		newPosMovs.erase(charPosition, 1);
		context.setMovements(newPosMovs);
	}
}
