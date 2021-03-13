#include "Graph.hpp"
#include "menuUtils.hpp"

int main(void)
{
    int choice = 0;
    do 
    {
        Menu menu = {{1, "Input a graph",},
                    {2, "Display data",},
                    {0, "Exit"},};
        clearScreen();
        PrintMenu(menu);
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        handleChoice(choice);    
    } while(choice != 0);
    return EXIT_SUCCESS;
}