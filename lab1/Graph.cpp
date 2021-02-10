#include "Graph.hpp"
#include <iostream>

Graph::Graph(int vertices) :
    numVertices(vertices)
{
    try
    {
        this->adjList = std::make_shared<std::list<int>>(numVertices);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}