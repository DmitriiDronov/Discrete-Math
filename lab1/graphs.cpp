#include "graphs.hpp"

std::ostream& operator<<(std::ostream& os, const BaseMatrix mx)
{
    //we need to make matrix representation via string
    std::string matrix{};
    for (unsigned int i{ 0 }; i < mx.matrix.size(); ++i) 
    {
        for (unsigned int j{ 0 }; j < mx.matrix.at(i).size(); ++j)
        {
            matrix += std::to_string(mx.matrix.at(i).at(j));
            matrix += " ";
        }
        matrix += "\n";
    }
    os << matrix;
    return os;
}

IncidenceMatrix::IncidenceMatrix(int rows, int cols) :
    BaseMatrix(rows, cols)
{  return; }

IncidenceMatrix::IncidenceMatrix() :
    BaseMatrix()
{
    return;
}

inline BaseMatrix::BaseMatrix():
    matrix{}, cols(0), rows(0)
{ return; }

BaseMatrix::BaseMatrix(const unsigned int rows, const unsigned int cols)
{
    int userInput{0};
    for (unsigned int i{0}; i < rows; ++i)
    {
        std::vector<int> vec{};
        for (unsigned int j{ 0 }; j < cols; ++j)
        {
            do 
            {
                std::cout << "[" << i << "][" << j << "] = ";
                std::cin >> userInput;
                if (userInput == 1 || userInput == 0 || userInput == -1)
                    break;
            } while (userInput != 0 && userInput != 1 && userInput != -1);
            vec.push_back(userInput);
        }
        this->matrix.push_back(vec);
    }
}

AdjencyMatrix::AdjencyMatrix()
{
}

AdjencyMatrix::~AdjencyMatrix()
{
}

std::vector<IncidenceMatrix>& incidentMartixes()
{
    static std::vector<IncidenceMatrix> incidentMartixes;
    return incidentMartixes;
}