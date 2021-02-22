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
        this->adjList = std::make_shared<std::vector<std::list<int>>>();
        //number of verices to input
        unsigned int numOfInputs{ 0 };
        // the vertice to input
        unsigned int vertice{ 0 };

        for (int i{ 0 }; i < vertices; ++i)
        {
            clearScreen();
            std::cout << "Enter how many vertices you want to input in vertice " << i + 1<< ": " << std::endl;
            std::cin >> numOfInputs;

            std::list<int> list;
            for (int j{ 0 }; j < numOfInputs; ++j)
            {
                std::cout << "Enter vertices correstonding to vertice " << i + 1 << std::endl;
                std::cin >> vertice;
                list.push_back(vertice);
            }
            adjList->push_back(list);
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }
    
}

Graph::Graph(AdjacencyMatrix matrix)
{
    *this = matrix.toAdjacencyList();
}

inline Graph::Graph(std::shared_ptr<AdjacencyList> adjListPtr, int vertices) :
    numVertices(vertices), adjList(adjListPtr) 
{
    return;
}

std::ostream& operator<<(std::ostream &os, const Graph &rhs)
{
    for (int i { 0 }; i < rhs.adjList->size(); ++i)
    {
        os << i + 1 << ": ";
        for (auto elem : rhs.adjList->at(i))
            os << elem << "-";
        os << "end" << std::endl;
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