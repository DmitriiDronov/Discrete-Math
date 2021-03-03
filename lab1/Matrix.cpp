#include "menuUtils.hpp"
#include <iomanip>
#include "Graph.hpp"
#include "Matrix.hpp"

//edits a Matrix 
void Matrix::edit()
{
    int choice{ 0 };
    unsigned int n{ 0 }, m{ 0 };
    int val{ 0 };
    do
    {
        //clearScreen();
        std::cout << *this;
        std::cout << "Enter element position to edit [r][c] separated by space: ";
        std::cin >> n >> m;
        std::cout << "Enter a new value: ";
        std::cin >> val;
        if (val != 0 && val != 1 && val != -1)
            std::cout << "Please enter a value 0/1/-1" << std::endl;
        else
            this->matrix.at(n).at(m) = val;
        std::cout << *this;
        std::cout << "If you want to stop editing press 0, if not enter 1" << std::endl;
        std::cin >> choice;
    } while (choice != 0);

    return;
}

std::ostream& operator<<(std::ostream& os, const Matrix& rhs)
{
    os << std::setw(5) << " ";
    for (unsigned int i{ 0 }; i <= rhs.matrix.size() - 1; ++i)
        os << std::setw(5) << "V" << i;

    os << std::endl;
    for (unsigned int i{ 0 }; i < rhs.matrix.size(); ++i)
    {
        os << std::setw(5) << "E/V" << i;
        for (unsigned int j{ 0 }; j < rhs.matrix.at(i).size(); ++j)
        {
            os << std::setw(5) << rhs.matrix.at(i).at(j);
        }
        os << std::endl;
    }
    return os;
}

MatrixOfIncidence::MatrixOfIncidence(int numOfPeaks, int numOfEdges) :
    Matrix(), peaks(numOfPeaks), edges(numOfEdges)
{
    clearScreen();
    short int num{0};
    for (unsigned int i{0}; i < peaks; ++i)
    {
        std::vector<short int> vec;
        for (unsigned int j{0}; j < edges; ++j)
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

inline AdjacencyMatrix::AdjacencyMatrix(std::vector<std::vector<short int>> matrix) :
    Matrix(), vertices(matrix.at(0).size())
{
    this->matrix = matrix;
}

Graph AdjacencyMatrix::toAdjacencyList()
{
    std::shared_ptr<AdjacencyList> adjList{ nullptr };
    size_t vertices = this->matrix.size();
    try
    {
        adjList = std::make_shared<AdjacencyList>();
        // we need to fill vector with empty lists
        // so it can be iterable and safe to push data
        for (unsigned int i{ 0 }; i < vertices; ++i)
        {
            std::list<unsigned int> temp{};
            adjList->push_back(temp);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Unable to fill an empty adjacency list\n";
    }
    
    //now it should be safe to push back data
    for (unsigned int i{ 0 }; i < vertices; ++i)
    {
        for(unsigned int j{ 0 }; j < this->matrix.at(i).size(); ++j)
        {
            if (this->matrix.at(i).at(j) == 1)
                adjList->at(i).push_back(j);
        }
    }
    return Graph(adjList, this->vertices);
}

//to test 
//https://stackoverflow.com/questions/22380139/how-do-you-transform-adjacency-matrices-to-incidence-matrices-and-vice-versa
AdjacencyMatrix MatrixOfIncidence::toAdjacencyMatrix()
{
    std::vector<std::vector<short int>> adjacency;
    int vertices = this->peaks;

    for (unsigned int edge = 0; edge < this->edges; ++edge)
    {
        std::cout << "Inside loop\n";
        int a = -1, b = -1, vertex = 0;
        for (; vertex < vertices && a == -1; ++vertex) 
        {
            std::cout << "Inside first inner loop\n";
            if (this->matrix.at(edge).at(vertex)) 
                a = vertex;
        }
        for (; vertex < vertices && b == -1; ++vertex) 
        {
            std::cout << "Inside second inner loop\n";
             if (this->matrix.at(edge).at(vertex)) 
                b = vertex;
        }
        if (b == -1)   
            b = a;
        adjacency.at(a).at(b) = adjacency.at(b).at(a) = 1;
    }
    return AdjacencyMatrix(adjacency);
}

// TO test
// I think we need to convert matrix of incidence to adjacency matrix and then convert
// to the adjacency list
inline Graph MatrixOfIncidence::toAdjacencyList()
{
    return this->toAdjacencyMatrix().toAdjacencyList();
}