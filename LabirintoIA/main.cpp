#include <iostream>
#include <vector>
#include <string>
#include "Labyrinth.h"
#include "Searcher.h"

using namespace std;

int main()
{
	// PRINT INICIAL
	cout << "--- LABIRINTO ---" << endl;
	cout << "IAC - PUCPR" << endl;
	cout << "Carlos Eduardo Marques Assuncao Torres" << endl;
	cout << "Milena Heloisa de Amorim Silverio" << endl;
	cout << "Ricardo Godoi Kurashiki" << endl;

	Coordinate searcherMovement;
	Context labyrinthContext;

	Labyrinth labyrinth = Labyrinth();
	Searcher searcher = Searcher();

	// Joga para o método de busca o contexto inicial.
	labyrinthContext = labyrinth.getCurrentContext();
	searcher.receiveContext(labyrinthContext);

	while (!labyrinth.solutionFound())
	{
		// Método de busca seleciona que movimento fazer.
		searcherMovement = searcher.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// Método de busca recebe o contexto devolvido.
		searcher.receiveContext(labyrinthContext);
		// Método de busca "pensa" qual o próximo movimento.
		searcher.think();
	}

	cout << "Jogo finalizado\n";
}



















	//// COORDENADAS
	//Offset coords;

	//// VETOR DO LABIRINTO
	//vector<string> labirinto = {
	//	"XXXXXXXXXXXXXXXXXXXXX",
	//	"X     X     X     X X",
	//	"XX XX XXXXX X X X   X",
	//	"X   X       XXX XXX X",
	//	"X X X XXXXXXX   X   X",
	//	"X X   X   X X X   X X",
	//	"X XXXXX X X   XXXXX X",
	//	"X X     X XXX  X    X",
	//	"X X X X X   XX XX XXX",
	//	"X X XXX X X     X   X",
	//	"E X X X X XXXXX XXX X",
	//	"X     X X   X X X   X",
	//	"X XXXXX XXX X XXX X X",
	//	"X X       X X   X X X",
	//	"X   XXX X X XXX X X S",
	//	"XXX X X X X X X X XXX",
	//	"X X   X X   X   X   X",
	//	"X XXX XXXXXXXXX XXX X",
	//	"X                 X X",
	//	"XXXXXXXXXXXXXXXXXXXXX"
	//};

	//vector<string> labirinto_layout = labirinto;

	//// PROCURA PELA ENTRADA
	//for (int y = 0; y < labirinto.size() - 1; ++y)
	//{
	//	for (int x = 0; x < labirinto[y].size() - 1; ++x)
	//	{
	//		if (labirinto[x][y] == 'E')
	//		{
	//			coords = Offset(x, y);
	//			labirinto[coords.getX()][coords.getY()] = '*';
	//			labirinto_layout[coords.getX()][coords.getY()] = '*';
	//			cout << "Entrada: (" << coords.getX() << ", " << coords.getY() << ")" << endl << endl;
	//		}
	//	}
	//}

	//bool isSearching = true;

	//while (isSearching)
	//{
	//	// CIMA
	//	if (isValid(labirinto[coords.getX() - 1][coords.getY()]))
	//	{
	//		if (isFinished(labirinto[coords.getX() - 1][coords.getY()]))
	//		{
	//			isSearching = false;
	//			coords.move('N');
	//			labirinto[coords.getX()][coords.getY()] = '*';
	//			labirinto_layout[coords.getX()][coords.getY()] = '*';
	//			break;
	//		}
	//		coords.move('N');
	//		labirinto[coords.getX()][coords.getY()] = '*';
	//		labirinto_layout[coords.getX()][coords.getY()] = '*';
	//	}
	//	// BAIXO
	//	else if (isValid(labirinto[coords.getX() + 1][coords.getY()]))
	//	{
	//		if (isFinished(labirinto[coords.getX() + 1][coords.getY()]))
	//		{
	//			isSearching = false;
	//			coords.move('S');
	//			labirinto[coords.getX()][coords.getY()] = '*';
	//			labirinto_layout[coords.getX()][coords.getY()] = '*';
	//			break;
	//		}
	//		coords.move('S');
	//		labirinto[coords.getX()][coords.getY()] = '*';
	//		labirinto_layout[coords.getX()][coords.getY()] = '*';
	//	}
	//	// DIREITA
	//	else if (isValid(labirinto[coords.getX()][coords.getY() + 1]))
	//	{
	//		if (isFinished(labirinto[coords.getX()][coords.getY() + 1]))
	//		{
	//			isSearching = false;
	//			coords.move('E');
	//			labirinto[coords.getX()][coords.getY()] = '*';
	//			labirinto_layout[coords.getX()][coords.getY()] = '*';
	//			break;
	//		}
	//		coords.move('E');
	//		labirinto[coords.getX()][coords.getY()] = '*';
	//		labirinto_layout[coords.getX()][coords.getY()] = '*';
	//	}
	//	// ESQUERDA
	//	else if (isValid(labirinto[coords.getX()][coords.getY() - 1]))
	//	{
	//		if (isFinished(labirinto[coords.getX()][coords.getY() - 1]))
	//		{
	//			isSearching = false;
	//			coords.move('W');
	//			labirinto[coords.getX()][coords.getY()] = '*';
	//			labirinto_layout[coords.getX()][coords.getY()] = '*';
	//			break;
	//		}
	//		coords.move('W');
	//		labirinto[coords.getX()][coords.getY()] = '*';
	//		labirinto_layout[coords.getX()][coords.getY()] = '*';
	//	}
	//	else
	//	{
	//		labirinto_layout[coords.getX()][coords.getY()] = ' ';
	//		coords.undo();
	//	}
	//	// Descomentar codigo abaixo para ver o algoritmo
	//	// for (int i = 0; i < labirinto_layout.size(); ++i) cout << labirinto_layout[i] << endl;
	//	// cout << endl;
	//}

	//cout << "Resultado do programa:" << endl << endl;
	//for (int i = 0; i < labirinto_layout.size(); ++i) cout << labirinto_layout[i] << endl;
	//cout << endl << "Saida: (" << coords.getX() << ", " << coords.getY() << ")" << endl;