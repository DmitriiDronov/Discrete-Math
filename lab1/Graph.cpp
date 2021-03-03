#include "Graph.hpp"
#include <iostream>
#include <iomanip>
#include "menuUtils.hpp"
#include <algorithm>

std::vector<Graph>& Graphs()
{
    static std::vector<Graph> Graphs;
    return Graphs;
}

Graph::Graph(size_t vertices) :
    numVertices(vertices)
{
    try
    {
        this->adjList = std::make_shared<AdjacencyList>();
        // the vertice to input
        int vertice{ 0 };
        for (unsigned int i{ 0 }; i < numVertices; ++i)
        {
            clearScreen();
            std::list<unsigned int> list;
            std::cout << "Enter vertices to vertice " << i << std::endl;
            std::cout << "If you want to stop, enter -1" << std::endl;
            for (unsigned int j { 0 }; j < vertices; ++j)
            {
                std::cin >> vertice;
                if (vertice < 0)
                    break;
                auto findResult = std::find(std::begin(list), std::end(list), vertice);
                // means there is no such value
                if (findResult == std::end(list))
                    list.push_back(vertice);
            }
        this->adjList->push_back(list);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Unable to create a graph\n";
        abort();
    }
}

Graph::Graph(AdjacencyMatrix matrix)
{
    *this = matrix.toAdjacencyList();
}

Graph::Graph(std::shared_ptr<AdjacencyList> adjListPtr, int vertices) :
    numVertices(vertices), adjList(adjListPtr) 
{ }

std::ostream& operator<<(std::ostream &os, const Graph &rhs)
{
    for (unsigned int i { 0 }; i < rhs.adjList->size(); ++i)
    {
        os << i << ": ";
        for (auto elem : rhs.adjList->at(i))
            os << elem << "-";
        os << "end" << std::endl;
    }
    os << std::endl;
    return os;
}

// TODO: Implement a 'Graph' method which
// transforms 'Graph' object to the 
// 'MatrixOfIncidence' object
// https://stackoverflow.com/questions/22380139/how-do-you-transform-adjacency-matrices-to-incidence-matrices-and-vice-versa
MatrixOfIncidence Graph::toMatrixOfIncidence()
{
    return MatrixOfIncidence(0, 0);
}

AdjacencyMatrix Graph::toAdjacencyMatrix()
{
    size_t vertices = this->numVertices;
    // we need to fill the matrix, so we can
    // later insert in it
    std::vector<std::vector<short int>> matrix;
    // fill with 0
    for (unsigned int i{ 0 }; i < vertices; ++i)
    {
        std::vector<short int> temp;
        for (unsigned int j{ 0 }; j < vertices; ++j)
        {
            temp.push_back(0);
        }
        matrix.push_back(temp);
    }
    try
    {
        for (unsigned int i{0}; i < vertices; ++i)
        {
            for (auto el : this->adjList->at(i))
            {
                el -= 1;
                matrix.at(i).at(el) = 1;
            }
            std::cout << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Unable to convert Adjacency list to the" 
        << "Adjacency Matrix" << std::endl;
    }
    
    
    return AdjacencyMatrix(matrix);
}