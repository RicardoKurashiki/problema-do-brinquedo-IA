#include "Labyrinth.h"

Labyrinth::Labyrinth()
{
	m_labyrinth = 
	{
		"XXXXXXXXXXXXXXXXXXXXX",
		"X     X     X     X X",
		"XX XX XXXXX X X X   X",
		"X   X       XXX XXX X",
		"X X X XXXXXXX   X   X",
		"X X   X   X X X   X X",
		"X XXXXX X X   XXXXX X",
		"X X     X XXX  X    X",
		"X X X X X   XX XX XXX",
		"X X XXX X X     X   X",
		"E X X X X XXXXX XXX X",
		"X     X X   X X X   X",
		"X XXXXX XXX X XXX X X",
		"X X       X X   X X X",
		"X   XXX X X XXX X X S",
		"XXX X X X X X X X XXX",
		"X X   X X   X   X   X",
		"X XXX XXXXXXXXX XXX X",
		"X                 X X",
		"XXXXXXXXXXXXXXXXXXXXX"
	};

	for (int line = 0; line < m_labyrinth.size() - 1; line++)
	{
		for (int column = 0; column < m_labyrinth[line].size() - 1; column++)
		{
			if (m_labyrinth[line][column] == 'E')
			{
				m_currentContext.setPosition(Coordinate(line, column));
			}
		}
	}

	updateContext();
}

void Labyrinth::receiveMovement(Coordinate movementPlace)
{
	m_currentContext.setPosition(movementPlace);
	updateContext();
}

Context Labyrinth::getCurrentContext()
{
	return m_currentContext;
}

void Labyrinth::updateContext()
{
	std::string possibleMovements = "";
	int line = m_currentContext.getPosition().getLine();
	int column = m_currentContext.getPosition().getColumn();

	/**
	 * Verifica as coordenadas atuais do contexto no labirinto e verifica
	 * as possibilidades de movimentação.
	 */
	if ((line > 0) &&
		(m_labyrinth[line - 1][column] != 'X'))
	{
		possibleMovements.push_back('N');
	}
	if ((line < m_labyrinth.size() - 1) &&
		(m_labyrinth[line + 1][column] != 'X'))
	{
		possibleMovements.push_back('S');
	}
	if ((column > 0) &&
		(m_labyrinth[line][column - 1] != 'X'))
	{
		possibleMovements.push_back('W');
	}
	if ((column < m_labyrinth[0].size()) &&
		(m_labyrinth[line][column + 1] != 'X'))
	{
		possibleMovements.push_back('E');
	}

	m_currentContext.setMovements(possibleMovements);
}

bool Labyrinth::solutionFound()
{
	return m_labyrinth[m_currentContext.getPosition().getLine()][m_currentContext.getPosition().getColumn()] == 'S';
}
