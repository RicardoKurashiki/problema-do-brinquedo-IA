#pragma once

#include <string>
#include "Coordinate.h"

class Context
{
public:
	Context();
	Context(Coordinate coord, std::string posMov);
	Coordinate getPosition();
	std::string getMovements();
	void setPosition(Coordinate pos);
	void setMovements(std::string posMov);
	void receiveMovement(char movement);
private:
	Coordinate m_position;
	std::string m_possibleMovements;
};

