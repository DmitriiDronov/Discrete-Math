#include "Graph.hpp"
#include "menuUtils.hpp"

int main(void)
{
    //MatrixOfIncidence mx(2, 2);
    // AdjacencyMatrix adjMx(2);
    // Graph gr = adjMx.toAdjacencyList();
    // std::cout << gr;
    int choice = 0;
    do 
    {
        //clearScreen();
        PrintMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        handleChoice(choice);    
    } while(choice != 0);
    return 0;
}