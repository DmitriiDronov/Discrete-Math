#include <iostream>
#include "menuUtils.hpp"

//entry point
int main()
{

    int choice{ 0 };
    do
    {
        clearScreen();
        PrintMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        handleChoice(choice);
    } while (choice != 0);
}