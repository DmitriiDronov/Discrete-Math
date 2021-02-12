#include "Graph.hpp"
#include <iostream>
#include "menuUtils.hpp"

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

MatrixOfIncidence::MatrixOfIncidence(int numOfPeaks, int numOfEdges) :
    peaks(numOfPeaks), edges(numOfEdges)
{
    short int num{0};
    for (int i{0}; i < peaks; ++i)
    {
        std::vector<short int> vec;
        for (int j{0}; j < edges; ++j)
        {
            do
            {
                std::cout << "[" << i << "]" << "[" << j << "] = ";
                std::cin >> num;
                if (num != 1 && num != -1 && num != 0)
                    std::cout << "Invalid number" << std::endl;
                else
                    vec.push_back(num);
            } while (num != 1 && num != -1 && num != 0);
        }
        matrix.push_back(vec);
    }
}