#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Labyrinth.h"
#include "Searcher.h"
#include "BlindSearcherDeep.h"
#include "BlindSearcherWidth.h"
#include "HeuristicSearcherGreedy.h"
#include "HeuristicSearcherAStar.h"

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
	int iterationCounter = 0;

	// Altere o valor de updateRate para mudar a velocidade de atualizacao labirinto
	int updateRateWidth = 10; // Uma atualização a cada X ms.
	int updateRateDeep = 10;
	int updateRateGreedy = 10;
	int updateRateAStar = 10;
	// Digite o E no lugar que deseja comecar no labirinto

	vector<string> laby = 
	{
		"XXXXXXXXXXXXXXXXXXXXX",
		"X     X     X     X X",
		"XX XX XXXXX X X X   X",
		"X   X       X   XXX X",
		"X X X XXXXXXX XXX   X",
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

	Labyrinth labyrinth = Labyrinth(laby);
	BlindSearcherDeep deepSearch = BlindSearcherDeep();
	BlindSearcherWidth widthSearch = BlindSearcherWidth();
	HeuristicSearcherGreedy greedySearch = HeuristicSearcherGreedy();
	HeuristicSearcherAStar aStarSearch = HeuristicSearcherAStar();
	

	// Joga para o método de busca o contexto inicial.
	labyrinthContext = labyrinth.getCurrentContext();
	widthSearch.receiveContext(labyrinthContext);

	//// Busca cega por largura
	while (!labyrinth.solutionFound())
	{
		system("cls");
		cout << "BUSCA CEGA POR LARGURA" << endl << endl;
		// Método de busca seleciona que movimento fazer.
		searcherMovement = widthSearch.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// Método de busca recebe o contexto devolvido.
		widthSearch.receiveContext(labyrinthContext);
		// Método de busca "pensa" qual o próximo movimento.
		widthSearch.handle();
		Sleep(updateRateWidth);
		iterationCounter++;
	}

	cout << "Resolveu com " << iterationCounter << " iteracoes.\n";
	cout << "Aperte ENTER para continuar";
	cin.ignore();

	labyrinth = Labyrinth(laby);
	labyrinthContext = labyrinth.getCurrentContext();
	deepSearch.receiveContext(labyrinthContext);
	iterationCounter = 0;
	
	// Busca cega por profundidade
	while (!labyrinth.solutionFound())
	{
		system("cls");
		cout << "BUSCA CEGA POR PROFUNDIDADE" << endl << endl;
		// Método de busca seleciona que movimento fazer.
		searcherMovement = deepSearch.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// Método de busca recebe o contexto devolvido.
		deepSearch.receiveContext(labyrinthContext);
		// Método de busca "pensa" qual o próximo movimento.
		deepSearch.handle();
		Sleep(updateRateDeep);
		iterationCounter++;
	}
	
	cout << "Resolveu com " << iterationCounter << " iteracoes.\n";
	cout << "Aperte ENTER para continuar";
	cin.ignore();

	Context labyrinthGoalContext;

	labyrinth = Labyrinth(laby);
	labyrinthContext = labyrinth.getCurrentContext();
	labyrinthGoalContext = labyrinth.getGoalContext();
	greedySearch.receiveContext(labyrinthContext);
	greedySearch.receiveGoalContext(labyrinthGoalContext);
	iterationCounter = 0;
	
	// Busca heuristica Greedy
	while (!labyrinth.solutionFound())
	{
		system("cls");
		cout << "BUSCA HEURISTICA GREEDY" << endl << endl;
		// Método de busca seleciona que movimento fazer.
		searcherMovement = greedySearch.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// Método de busca recebe o contexto devolvido.
		greedySearch.receiveContext(labyrinthContext);
		// Método de busca "pensa" qual o próximo movimento.
		greedySearch.handle();
		Sleep(updateRateGreedy);
		iterationCounter++;
	}

	cout << "Resolveu com " << iterationCounter << " iteracoes.\n";
	cout << "Aperte ENTER para continuar";
	cin.ignore();

	labyrinth.showSolution(greedySearch.m_contextHistory);
	
	cout << "Aperte ENTER para continuar";
	cin.ignore();

	labyrinth = Labyrinth(laby);
	labyrinthContext = labyrinth.getCurrentContext();
	labyrinthGoalContext = labyrinth.getGoalContext();
	aStarSearch.receiveContext(labyrinthContext);
	aStarSearch.receiveStartContext(labyrinthContext);
	aStarSearch.receiveGoalContext(labyrinthGoalContext);
	iterationCounter = 0;

	// Busca heuristica AStar
	while (!labyrinth.solutionFound())
	{
		system("cls");
		cout << "BUSCA HEURISTICA A*" << endl << endl;
		// Método de busca seleciona que movimento fazer.
		searcherMovement = aStarSearch.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// Método de busca recebe o contexto devolvido.
		aStarSearch.receiveContext(labyrinthContext);
		// Método de busca "pensa" qual o próximo movimento.
		aStarSearch.handle();
		Sleep(updateRateAStar);
		iterationCounter++;
	}

	cout << "Resolveu com " << iterationCounter << " iteracoes.\n";
	cout << "Jogo finalizado.\n";
	cout << "Aperte ENTER para continuar";
	cin.ignore();

	system("cls");
	labyrinth.showSolution(aStarSearch.m_contextHistory);
}