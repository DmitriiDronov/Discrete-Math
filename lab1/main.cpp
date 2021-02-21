#include "Graph.hpp"
#include "menuUtils.hpp"

int main(void)
{
    int choice = 0;
    do 
    {
        // clearScreen();
        PrintMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        handleChoice(choice);    
    } while(choice != 0);
    return 0;
}