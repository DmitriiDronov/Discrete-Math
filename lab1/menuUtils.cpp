#include "menuUtils.hpp"
#include "Graph.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <string>

// nested switch statements depending on the user choice
void handleChoice(const int choice) 
{
	// for the beauty we should clear here the screen
	clearScreen();
	unsigned int innerChoice{ 0 };
	
	// used for graph creation 
	unsigned int nodes{ 0 };
	unsigned int edges{ 0 };
	unsigned int vertices{ 0 };
	unsigned int index{ 0 };
	switch (choice)
	{
	// input a graph
	case 1:
		std::cout << "1. The matrix of incidence\n2. The adjacency matrix\n3. The adjacency list" << std::endl;
		std::cin >> innerChoice;
		clearScreen();
		switch (innerChoice)
		{
		// input incidence matrix
		case 1:
			std::cout << "Enter nodes quanity: ";
			std::cin >> nodes;

			std::cout << "Enter edges quanity: ";
			std::cin >> edges;
			if (nodes != 0 && edges != 0)
			{
				MatrixOfIncidence incMatrix(edges, nodes);
				Graphs().push_back(incMatrix.toAdjacencyList());	
			}
			else
				std::cerr << "Zero matrix can't be created" << std::endl;
			break;
		// input adjacency matrix
		case 2:
			std::cout << "Enter the number of vertices: ";
			std::cin >> vertices;
			if (vertices != 0)
			{
				AdjacencyMatrix adjacencyMatrix(vertices);
				Graphs().push_back(adjacencyMatrix.toAdjacencyList());
			}
			else
				std::cerr << "Zero matrix can't be created" << std::endl;
			break;
		// input adjacency list
		case 3:
			std::cout << "Enter the number of vertices: ";
			std::cin >> vertices;
			if (vertices != 0)
			{
				Graph grList(vertices);
				Graphs().push_back(grList);
			}
			else
				std::cerr << "Zero matrix creation" << std::endl;
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
			break;
		}
	// edit a graph
	case 2:
		printGraphs(Graphs());
		std::cout << "Enter a graph index you want to edit: ";
		std::cin >> index;

		break;
		std::cout << std::endl;
	// display data
	case 3:
		std::cout << "1. Print lists\n2. Print Incidence Matrixes\n3. Print adjacency Matrixes\n";
		std::cin >> innerChoice;
		switch (innerChoice)
		{
		case 1:
			for (unsigned int i{ 0 }; i < Graphs().size(); ++i)
				std::cout << Graphs().at(i);
			break;
		case 2:
			for (unsigned int i{ 0 }; i < Graphs().size(); ++i)
				std::cout << Graphs().at(i).toMatrixOfIncidence();
			break;
		case 3:
			for (unsigned int i{ 0 }; i < Graphs().size(); ++i)
				std::cout << Graphs().at(i).toAdjacencyMatrix();
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
			break;
		}
		pause();
		break;
	case 0:
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
	// clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	// std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
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

void printGraphs(std::vector<Graph>& graphs)
{
    size_t size = graphs.size();
    for (unsigned int i{ 0 }; i < size; ++i)
    {
        std::cout << i << "th graph" << std::endl << graphs.at(i);
    }
}