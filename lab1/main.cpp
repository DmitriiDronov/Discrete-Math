#include "Graph.hpp"
#include "menuUtils.hpp"

int main(void)
{
    Graph gr1(2);
    std::cout << "Graph: \n" << gr1;
    AdjacencyMatrix temp = gr1.toAdjacencyMatrix();
    std::cout << "AdjMatrix: \n" << temp;
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