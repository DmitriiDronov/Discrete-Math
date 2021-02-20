#include "menuUtils.hpp"
#include "Graph.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <string>

//here will be nested switch statements depending on the user choice
void handleChoice(const int choice) 
{
	//for the beauty we should clear here the screen
	clearScreen(); //this can be a problem, because now software is OS dependable. fix? maybe define statens here can help
	unsigned int innerChoice{ 0 };
	
	//used for graph creation 
	unsigned int nodes{ 0 };
	unsigned int edges{ 0 };
	unsigned int vertices{ 0 };
	switch (choice)
	{
	case 1:
		std::cout << "1. The matrix of incidence\n2. The adjacency matrix\n3. The adjacency list" << std::endl;
		std::cin >> innerChoice;
		clearScreen();
		switch (innerChoice)
		{
		case 1:
			std::cout << "Enter nodes quanity: ";
			std::cin >> nodes;

			std::cout << "Enter edges quanity: ";
			std::cin >> edges;
			if (nodes == 0 && edges == 0)
				MatrixOfIncidence zeroMx(0, 0);
			else
				MatrixOfIncidence matrix(edges, nodes);
			break;
		case 2:
			std::cout << "Enter the number of vertices: ";
			std::cin >> vertices;
			if (vertices == 0)
				AdjacencyMatrix zeroMx(vertices);
			else
				AdjacencyMatrix adjacencyMatrix(vertices);
			break;
		case 3:
			std::cout << "Enter the number of vertices: ";
			if (vertices == 0)
				Graph zeroGrList(vertices);
			else
				Graph grList(vertices);
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
			break;
		}
	case 2:
		break;
		std::cout << std::endl;
	case 3:
		break;
		std::cout << std::endl;
	case 4:
		std::cout << "1. Print lists\n2. Print Incidence Matrixes\n3. Print adjacency Matrixes\n";
		std::cin >> innerChoice;
		switch (innerChoice)
		{
		case 1:
			//not very efficient, but we have no choice
			for (int i{ 0 }; i < Graphs().size(); ++i)
				std::cout << Graphs().at(i);
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
			break;
		}
		pause();
		break;
	default:
		std::cout << "Invalid choice" << std::endl;
		break;
	}
}

void clearScreen() 
{
#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
	system("clear");
#endif
}

void pause()
{
	std::cin.ignore();
	std::cout << std::endl << "Press any key to continue...";
	std::string dummy;
	std::getline(std::cin, dummy);
}