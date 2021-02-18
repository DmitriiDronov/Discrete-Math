#include "menuUtils.hpp"
#include <iomanip>
#include "Graph.hpp"
#include "Matrix.hpp"

MatrixOfIncidence::MatrixOfIncidence(int numOfPeaks, int numOfEdges) :
    Matrix(), peaks(numOfPeaks), edges(numOfEdges)
{
    clearScreen();
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

std::ostream& operator<<(std::ostream& os, const Matrix& rhs)
{
    for (int i{0}; i < rhs.matrix.size(); ++i)
        os << std::setw(5) << "V" << i;
    for (int i{0}; i < rhs.matrix.size(); ++i)
    {
        os << std::setw(5) << "E" << i;
        for (int j{0}; j < rhs.matrix.at(i).size(); ++j)
        {
            os << std::setw(5) << rhs.matrix.at(i).at(j);
        }
    }
    return os;
}

AdjacencyMatrix::AdjacencyMatrix(int numOfVertices) :
    Matrix(), vertices(numOfVertices)
{
    clearScreen();
    short int num{0};
    for (int i{0}; i < numOfVertices; ++i)
    {
        std::vector<short int> vec;
        for (int j{0}; j < numOfVertices; ++j)
        {
            do
            {
                std::cout << "[" << i << "]" << "[" << j << "] = ";
                std::cin >> num;
                if (num != 1 && num != 0)
                    std::cout << "Invalid number" << std::endl;
                else
                    vec.push_back(num);
            } while (num != 1 && num != 0);
        }
        matrix.push_back(vec);
    }
}

//TODO
void AdjacencyMatrix::edit()
{
    return;
}

//TODO
Graph AdjacencyMatrix::toAdjacencyList()
{
    return Graph(0);
}

//TODO
void MatrixOfIncidence::edit()
{
    return;
}

//TODO
Graph MatrixOfIncidence::toAdjacencyList()
{
    return Graph(0);
}