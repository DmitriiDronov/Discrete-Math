#include "menuUtils.hpp"
#include "graphs.hpp"

//here will be nested switch statements depending on the user choice
void handleChoice(const int choice) 
{
	//for the beauty we should clear here the screen
	clearScreen(); //this can be a problem, because now software is OS dependable. fix? maybe define statens here can help
	unsigned int innerChoice{ 0 };
	
	unsigned int nodes{ 0 };
	unsigned int edges{ 0 };
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
			{
				IncidenceMatrix zeroMx;
				incidentMartixes().push_back(zeroMx);
			}
			else
			{
				IncidenceMatrix matrix(edges, nodes);
				incidentMartixes().push_back(matrix);
			}
			break;
		case 2:
			std::cout << std::endl;
			break;
		case 3:
			std::cout << std::endl;
			break;
		default:
			break;
		}
	case 2:
		break;
		std::cout << std::endl;
	case 3:
		break;
		std::cout << std::endl;
	case 4:
		std::cout << "1. Print all\n2. Print Incidence Matrixes\n3. Print another...\n";
		std::cin >> innerChoice;
		switch (innerChoice)
		{
		case 1:
			break;
		case 2:
			for (unsigned int i{ 0 }; i < incidentMartixes().size(); ++i)
			{
				std::cout << incidentMartixes().at(i);
				std::cout << "------------------------\n";
			}
			break;
		case 3:
			break;
		default:
			std::cout << "Invalid choice\n";
			break;
		}
		pause();
		break;
	default:
		std::cout << "Invalid choice\n";
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