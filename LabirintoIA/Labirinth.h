#pragma once

#include "Context.h"
#include <vector>
#include <string>

class Labirinth
{
	std::vector<std::string> labirinto;
	Context contexto;
	Context receiveMovement(char m);
	void verifyMovements();
	void horizontalMovement();
	void verticalMovement();
};