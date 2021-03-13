#include "../lab1/Matrix.hpp"
#include "../lab1/menuUtils.hpp"
#include <iostream>

std::vector<AdjacencyMatrix>& adjacencyMatrixesCollector();
AdjacencyMatrix createAdjacencyMatrix();
void printMatrixes(std::vector<AdjacencyMatrix>& adjacencyMatrixesCollector);

int main(void)
{
    int choice = 0;
    do 
    {
        Menu menu = {{1, "Input an adjacency matrix",},
                    {2, "Display data",},
                    {3, "Find shortest path"},
                    {0, "Exit"},};
        clearScreen();
        PrintMenu(menu);
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            adjacencyMatrixesCollector().push_back(createAdjacencyMatrix());
            break;
        case 2:
            printMatrixes(adjacencyMatrixesCollector());
            break;
        case 3:
            break;
        case 0:
            return EXIT_SUCCESS;
            break;
        default:
            break;
        }   
    } while(choice != 0);
    return EXIT_SUCCESS;
}

std::vector<AdjacencyMatrix>& adjacencyMatrixesCollector()
{
    static std::vector<AdjacencyMatrix> collector;
    return collector;
}

AdjacencyMatrix createAdjacencyMatrix() 
{
    unsigned int vertices{ 0 };
    std::cout << "Enter a number of vertices: ";
    std::cin >> vertices;
    return AdjacencyMatrix(vertices);
}

void printMatrixes(std::vector<AdjacencyMatrix>& adjacencyMatrixesCollector)
{
    for (auto& item : adjacencyMatrixesCollector)
        std::cout << item;
    pause();
}