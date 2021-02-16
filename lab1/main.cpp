#include "Graph.hpp"
#include "menuUtils.hpp"

int main(void)
{
    Graph gr(3);
    std::cout << gr; 
    AdjacencyMatrix adj(3);
    MatrixOfIncidence inc(3, 3);
    std::cout << adj << std::endl << inc << std::endl;
    int choice = 0;
    do 
    {
        clearScreen();
        PrintMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        handleChoice(choice);    
    } while(choice != 0);
    return 0;
}