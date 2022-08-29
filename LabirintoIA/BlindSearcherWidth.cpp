#include "BlindSearcherWidth.h"

BlindSearcherWidth::BlindSearcherWidth() 
{
	m_lastMovement = 'X';
}

void BlindSearcherWidth::receiveContext(Context recContext)
{
	removeMovePossibilitie(recContext, m_lastMovement);
	m_contextHistory.push_back(recContext);
}

Coordinate BlindSearcherWidth::makeMovement()
{
	// Tenho apenas um movimento.
	// Realizo o movimento.
	// Recebo um contexto com as seguintes possibilidades (N, S, E)
	// Realizo o movimento N
	// Coloco no meu histórico de contextos
	// Verifico se ainda tenho movimentos disponíveis no primeiro item do meu vector
	// Realizo o movimento S
	// Coloco no meu histórico de contextos
	// Verifico se ainda tenho movimentos disponíveis no primeiro item do meu vector
	// Realizo o movimento E
	// Coloco no meu histórico de contextos
	// Verifico se ainda tenho movimentos disponíveis no primeiro item do meu vector
	// Como não tenho mais movimentos nesse contexto, descarto o primeiro item do meu vector
	// Começo a análise do segundo

	Coordinate coord;
	char movementChosen;

	while (m_contextHistory[0].getMovements().empty())
		m_contextHistory.erase(m_contextHistory.begin());

	movementChosen = m_contextHistory[0].getMovements()[0];
	coord = m_contextHistory[0].getPosition();
	coord.move(movementChosen);

	/**
	 * Quando o algoritmo fizer um movimento, armazenar (N, S, W, E) e excluir como possibilidade do contexto gerado por ele.
	 * Também remover do contexto final do momento o movimento realizado por ele.
	 */
	removeMovePossibilitie(m_contextHistory[0], movementChosen);

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

void BlindSearcherWidth::handle()
{
	
}

void BlindSearcherWidth::removeMovePossibilitie(Context& context, char move)
{
	std::size_t charPosition = context.getMovements().find(move);

	if (charPosition != std::string::npos)
	{
		std::string newPosMovs = context.getMovements();
		newPosMovs.erase(charPosition, 1);
		context.setMovements(newPosMovs);
	}
}
