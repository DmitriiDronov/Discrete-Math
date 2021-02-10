#pragma once
#include <iostream>
#include <vector>
#include "graphs.hpp"

//for optimization here inline. We define it in the header file because of linker error.
inline void PrintMenu()
{
    std::cout << "1. Input a graph\n2. Transform from one form to another.\n3. Edit graph\n4. Display data\n0. Exit" << std::endl;
}
void handleChoice(const int choice);
void clearScreen();
void pause();