#include "Labirinth.h"

Labirinth::Labirinth()
{
	labirinto = {
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
	
	for (int y = 0; y < labirinto.size() - 1; ++y)
	{
		for (int x = 0; x < labirinto[y].size() - 1; ++x)
		{
			if (labirinto[x][y] == 'E')
			{
				contexto.coords = Offset(x, y);
			}
		}
	}
	verifyMovements();
}

Context Labirinth::receiveMovement(char m)
{
	contexto.coords.move(m);
	verifyMovements();
	return contexto;
}

void Labirinth::verifyMovements()
{
	horizontalMovement();
	verticalMovement();
}

void Labirinth::verticalMovement()
{
	// Se a pos Vertical for diferente da ultima pos do labirinto e
	// se a pos embaixo desta for diferente de X
	if ((labirinto.size() - 1 != contexto.coords.getV()) &&
		(labirinto[contexto.coords.getV() + 1][contexto.coords.getH()] != 'X'))
		contexto.movements.push_back('S');
	// Se a pos Vertical nao for igual ao ponto inicial
	// e se a pos de cima for diferente de X
	if ((contexto.coords.getV() != 0) &&
		(labirinto[contexto.coords.getV() - 1][contexto.coords.getH()] != 'X'))
		contexto.movements.push_back('N');
}

void Labirinth::horizontalMovement()
{
	if ((labirinto[contexto.coords.getV()].length() - 1 != contexto.coords.getH()) &&
		(labirinto[contexto.coords.getV()][contexto.coords.getH() + 1] != 'X'))
		contexto.movements.push_back('E');
	if ((contexto.coords.getH() != 0) &&
		(labirinto[contexto.coords.getV()][contexto.coords.getH() - 1] != 'X'))
		contexto.movements.push_back('W');
}