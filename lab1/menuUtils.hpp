#ifndef MENU_UTILS_HPP_
#define MENU_UTILS_HPP_
#include <iostream>
#include <vector>
#include "Graph.hpp"
#include <map>

typedef std::map<int, std::string> Menu;

inline void PrintMenu(Menu& menu)
{
    // std::cout << 
    // "1. Input a graph" << std::endl <<
    // "2. Display data" << std::endl <<
    // "0. Exit" << std::endl;
    for (auto &item : menu)
        std::cout << item.first << ". " << item.second << std::endl;
}
void handleChoice(const int choice);
void clearScreen();
void pause();
void printGraphs(std::vector<Graph>& graphs);
#endif