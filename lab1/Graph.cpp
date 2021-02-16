#include "Graph.hpp"
#include <iostream>
#include <iomanip>
#include "menuUtils.hpp"

std::vector<Graph>& Graphs()
{
    static std::vector<Graph> Graphs;
    return Graphs;
}

Graph::Graph(int vertices) :
    numVertices(vertices)
{
    try
    {
        this->adjList = std::make_shared<std::list<int>>(numVertices);
        unsigned int vertice{0};
        unsigned int numOfInputs{0};
        for (int i{0}; i < numVertices; ++i)
        {
            clearScreen();
            std::cout << "Enter how many vertices you want to input in vertice " << i << ": " << std::endl;
            std::cin >> numOfInputs;
            for (int j = 0; j < numOfInputs; ++j)
            {
                std::cin >> vertice;
                std::cout << "Enter vertices correstonding to vertice " << i << std::endl;
                (adjList.get() + i)->push_back(vertice);
            }
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }
    
}

std::ostream& operator<<(std::ostream &os, const Graph &rhs)
{
    for (int i{0}; i < rhs.numVertices; ++i)
    {
        os << i << ": ";
        for (auto elem : *(rhs.adjList.get() + i))
        {
            os << elem << "-";
        }
    }
    os << std::endl;
    return os;
}

//TODO
MatrixOfIncidence Graph::toMatrixOfIncidence()
{
    return MatrixOfIncidence(0, 0);
}

//TODO
AdjacencyMatrix Graph::toAdjacencyMatrix()
{
    return AdjacencyMatrix(0);
}