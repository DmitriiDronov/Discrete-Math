#ifndef MENU_UTILS_HPP_
#define MENU_UTILS_HPP_
#include <iostream>
#include <vector>
#include "Graph.hpp"

//for optimization here inline. We define it in the header file because of linker error.
inline void PrintMenu()
{
    std::cout << 
    "1. Input a graph" << std::endl <<
    "2. Edit graph" << std::endl <<
    "3. Display data" << std::endl << 
    "0. Exit" << std::endl;
}
void handleChoice(const int choice);
void clearScreen();
void pause();
void printGraphs(std::vector<Graph>& graphs);
#endif