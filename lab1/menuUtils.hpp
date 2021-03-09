#ifndef MENU_UTILS_HPP_
#define MENU_UTILS_HPP_
#include <iostream>
#include <vector>
#include "Graph.hpp"

inline void PrintMenu()
{
    std::cout << 
    "1. Input a graph" << std::endl <<
    "2. Display data" << std::endl <<
    "0. Exit" << std::endl;
}
void handleChoice(const int choice);
void clearScreen();
void pause();
void printGraphs(std::vector<Graph>& graphs);
#endif