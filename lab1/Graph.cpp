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
        abort();
    }
    
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