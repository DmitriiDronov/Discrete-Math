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
    os << std::setw(5) << " ";
    for (int i{1}; i <= rhs.matrix.size(); ++i)
        os << std::setw(5) << "V" << i;

    os << std::endl;
    for (int i{0}; i < rhs.matrix.size(); ++i)
    {
        os << std::setw(5) << "E" << i+1;
        for (int j{0}; j < rhs.matrix.at(i).size(); ++j)
        {
            os << std::setw(5) << rhs.matrix.at(i).at(j);
        }
        os << std::endl;
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

//To test
void AdjacencyMatrix::edit()
{
    clearScreen();
    std::cout << *this;

    int choice{ 0 };
    unsigned int n{ 0 }, m{ 0 };
    unsigned int val{ 0 };
    do
    {
        std::cout << "Enter element position to edit [n][m]: ";
        std::cin >> n >> m;
        std::cout << "Enter a new value: ";
        std::cin >> val;
        if (val != 0 || val != 1)
            std::cout << "Please enter a value 0 or 1" << std::endl;
        else
            this->matrix.at(n).at(m) = val;
        clearScreen();
        std::cout << *this;
        std::cout << "If you want to stop editing press 0, if not enter 1" << std::endl;
        std::cin >> choice;
    } while (choice != 0);
    
    return;
}

//To test
Graph AdjacencyMatrix::toAdjacencyList()
{
    std::shared_ptr<AdjacencyList> adjList;
    try
    {
        adjList = std::make_shared<AdjacencyList>();
        //we need to fill vector with empty lists
        for (int i{ 0 }; i < this->vertices; ++i)
        {
            std::list<int> temp;
            adjList->push_back(temp);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for (int i{ 0 }; i < this->matrix.size(); ++i)
    {
        for(int j{ 0 }; j < this->matrix.at(i).size(); ++i)
        {
            if (this->matrix.at(i).at(j) == 1)
                adjList->at(i).push_back(j);
        }
    }
    return Graph(adjList, this->vertices);
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