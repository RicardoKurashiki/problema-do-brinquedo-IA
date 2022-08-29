#include "BlindSearcherWidth.h"

BlindSearcherWidth::BlindSearcherWidth() 
{
	lastMov = 'X';
}

void BlindSearcherWidth::receiveContext(Context recContext)
{
	
}

Coordinate BlindSearcherWidth::makeMovement()
{
	Coordinate value;

	return value;
}

void BlindSearcherWidth::handle()
{
	
}

void BlindSearcherWidth::removeLastMovement(Context& context, char move)
{
	std::size_t charPosition = context.getMovements().find(move);

	if (charPosition != std::string::npos)
	{
		std::string newPosMovs = context.getMovements();
		newPosMovs.erase(charPosition, 1);
		context.setMovements(newPosMovs);
	}
}
