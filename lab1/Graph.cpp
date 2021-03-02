#include "Graph.hpp"
#include <iostream>
#include <iomanip>
#include "menuUtils.hpp"

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
        unsigned int vertice{ 0 };

        for (unsigned int i{ 0 }; i < vertices; ++i)
        {
            clearScreen();
            std::list<unsigned int> list;
            for (unsigned int j{ 0 }; j < vertices; ++j)
            {
                do
                {
                    clearScreen();
                    std::cout << "If you want to stop entering values, input a value"
                    << " greater then " << vertices << std::endl;
                    std::cout << "Enter vertices correstonding to vertice " 
                    << i << std::endl;
                    std::cin >> vertice;
                    list.push_back(vertice);
                } while (vertice >= 0 && vertice <= vertices);
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

inline Graph::Graph(AdjacencyMatrix matrix)
{
    *this = matrix.toAdjacencyList();
}

Graph::Graph(std::shared_ptr<AdjacencyList> adjListPtr, int vertices) :
    numVertices(vertices), adjList(adjListPtr) 
{}

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

// TODO: Implement a 'Graph' method which
// transforms 'Graph' object to the 
// 'AdjacencyMatrix' object
// https://www.geeksforgeeks.org/convert-adjacency-list-to-adjacency-matrix-representation-of-a-graph/
// TO TEST
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
                std::cout << "[" << i << "]" << "[" << el << "]";
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