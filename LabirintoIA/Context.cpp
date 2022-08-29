#include "Context.h"

Context::Context()
{
	m_position = Coordinate();
	m_possibleMovements = "";
}

Context::Context(Coordinate coord, std::string posMov)
{
	m_position = coord;
	m_possibleMovements = posMov;
}

Coordinate Context::getPosition()
{
	return m_position;
}

std::string Context::getMovements()
{
	return m_possibleMovements;
}

void Context::setPosition(Coordinate pos)
{
	m_position = pos;
}

void Context::setMovements(std::string posMov)
{
	m_possibleMovements = posMov;
}

void Context::receiveMovement(char movement)
{
	m_position.move(movement);
}