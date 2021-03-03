#include "menuUtils.hpp"
#include <iomanip>
#include "Graph.hpp"
#include "Matrix.hpp"

void Matrix::edit()
{
    int choice{ 0 };
    unsigned int n{ 0 }, m{ 0 };
    int val{ 0 };
    do
    {
        clearScreen();
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
    if (peaks > 0)
    {
        char choice{};
        do
        {
            clearScreen();
            std::cout << *this;
            std::cout << "Do you want to edit(Y/n): ";
            std::cin >> choice;
            choice = toupper(choice);
            if (choice == 'Y')
                this->edit();
        } while (choice == 'Y');
    }
}

MatrixOfIncidence::MatrixOfIncidence(std::vector<std::vector<short int>> mx) :
    peaks(mx.size()), edges(mx.at(0).size())
{
    matrix = mx;
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
    if (vertices > 0)
    {
        char choice{};
        do
        {
            clearScreen();
            std::cout << *this;
            std::cout << "Do you want to edit(Y/n): ";
            std::cin >> choice;
            choice = toupper(choice);
            if (choice == 'Y')
                this->edit();
        } while (choice == 'Y');
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

    try
    {
        for (unsigned int i{0}; i < vertices; ++i)
        {
            for (unsigned int j{0}; j < this->matrix.at(i).size(); ++j)
            {
                if (this->matrix.at(i).at(j) == 1)
                    adjList->at(i).push_back(j);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Unable to convert adjacency matrix to adjacency list\n";
    }
    return Graph(adjList, this->vertices);
}

MatrixOfIncidence AdjacencyMatrix::toMatrixOfIncidence()
{
    std::vector<std::vector<short int>> inc{};
    int cols = this->matrix.size();
    int edge = 0;
    try
    {
        for (int col{ 0 }; col < cols; ++col)
        {
            for (int row{ 0 }; row <= col; ++row)
            {
                if (this->matrix.at(col).at(row))
                {
                    inc.push_back(std::vector<short int>(cols, 0));
                    inc.at(edge).at(row) = inc.at(edge).at(col) = 1;
                    ++edge;
                }
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Invalid matrix\n";
    }
    return MatrixOfIncidence(inc);
}

AdjacencyMatrix MatrixOfIncidence::toAdjacencyMatrix()
{
    // we need to fill this vector with 0,
    // so we can safely work with it
    std::vector<std::vector<short int>> adjacency;
    int vertices = this->peaks;
    for (unsigned int i{ 0 }; i < this->peaks; ++i)
    {
        std::vector<short int> temp{};
        for (unsigned int j{ 0 }; j < this->edges; ++j)
        {
            temp.push_back(0);
        }
        adjacency.push_back(temp);
    }

    try
    {
        for (unsigned int edge = 0; edge < this->edges; ++edge)
        {
            int a{-1}, b{-1}, vertex{0};
            for (; vertex < vertices && a == -1; ++vertex)
            {
                if (this->matrix.at(edge).at(vertex))
                    a = vertex;
            }
            for (; vertex < vertices && b == -1; ++vertex)
            {
                if (this->matrix.at(edge).at(vertex))
                    b = vertex;
            }
            if (b == -1)
                b = a;
            adjacency.at(a).at(b) = adjacency.at(b).at(a) = 1;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Invalid matrix\n";
    }
    return AdjacencyMatrix(adjacency);
}

inline Graph MatrixOfIncidence::toAdjacencyList()
{
    return this->toAdjacencyMatrix().toAdjacencyList();
}