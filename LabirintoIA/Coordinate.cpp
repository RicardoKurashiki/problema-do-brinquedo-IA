#include "Coordinate.h"

Coordinate::Coordinate() 
{
	m_line = m_column = 0;
}

Coordinate::Coordinate(int startLine, int startColumn)
{
	m_line = startLine;
	m_column = startColumn;
}

void Coordinate::move(char direction)
{
	switch (direction)
	{
	case 'N':
		--m_line;
		break;
	case 'S':
		++m_line;
		break;
	case 'W':
		--m_column;
		break;
	case 'E':
		++m_column;
		break;
	default:
		break;
	}
}