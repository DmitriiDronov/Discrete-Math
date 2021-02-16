#include "Matrix.hpp"
#include "menuUtils.hpp"
#include <iomanip>

MatrixOfIncidence::MatrixOfIncidence(int numOfPeaks, int numOfEdges) :
    peaks(numOfPeaks), edges(numOfEdges)
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

std::ostream& operator<<(std::ostream& os, const MatrixOfIncidence& rhs)
{
    for (int i{0}; i < rhs.peaks; ++i)
        os << std::setw(5) << "V" << i;
    for (int i{0}; i < rhs.edges; ++i)
    {
        os << std::setw(5) << "E" << i;
        for (int j{0}; j < rhs.peaks; ++j)
        {
            os << std::setw(5) << rhs.matrix.at(i).at(j);
        }
    }
}

AdjacencyMatrix::AdjacencyMatrix(int numOfVertices) :
    vertices(numOfVertices)
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

std::ostream& operator<<(std::ostream &os, const AdjacencyMatrix &rhs)
{
    for (int i{0}; i < rhs.vertices; ++i)
        os << std::setw(5) << "V" << i;
    os << std::endl;
    for (int i{0}; i < rhs.vertices; ++i)
    {
        os << std::setw(5) << "V" << i;
        for (int j{0}; j < rhs.vertices; ++j)
        {
            os << std::setw(5) << rhs.matrix.at(i).at(j);
        }
    }
}