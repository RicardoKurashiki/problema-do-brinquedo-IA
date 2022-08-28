#include "Searcher.h"

void Searcher::receiveContext(Context recContext)
{
	std::cout << "\n-- Contexto do Labirinto --\n";
	std::cout << "linha: " << recContext.getPosition().getLine() << " | coluna: " << recContext.getPosition().getColumn() << std::endl;
	std::cout << "Possiveis movimentos: " << recContext.getMovements().c_str() << std::endl;
	m_currentPlace = recContext;
}

Coordinate Searcher::makeMovement()
{
	Coordinate movement = m_currentPlace.getPosition();
	char move;

	std::cout << "Movimento: ";
	std::cin >> move;

	movement.move(move);

	return movement;
}

void Searcher::think()
{
	
}
