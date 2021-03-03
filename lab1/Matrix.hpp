#ifndef MATRIX_HPP_H
#define MATRIX_HPP_H
#include "Graph.hpp"

class Graph;
class MatrixOfIncidence;

// base abstract class
// provides some common functionality for derived classes
class Matrix
{
public:
    virtual ~Matrix() {};
    // edits a matrix
    virtual void edit();
    // transforms 'Matrix' object
    // to the 'Graph' object
    virtual Graph toAdjacencyList() = 0;
    // prints the 'Matrix' object to Standart Output(stdout)
    //
    // How to use example:
    // std::cout << Matrix object;
    friend std::ostream& operator<<(std::ostream &os, const Matrix &rhs);
protected:
    std::vector<std::vector<short int>> matrix;
};

class AdjacencyMatrix : public Matrix
{
public:
    AdjacencyMatrix(int numOfVertices);
    // Constructs 'AdjacencyMatrix' object
    // from the vector
    AdjacencyMatrix(std::vector<std::vector<short int>> matrix);
    // transforms 'AdjacencyMatrix' object
    //to the 'Graph' object
    Graph toAdjacencyList() override;
    MatrixOfIncidence toMatrixOfIncidence();
private:
    size_t vertices;
};

class MatrixOfIncidence : public Matrix
{
public:
    MatrixOfIncidence(int numOfPeaks, int numOfEdges);
    MatrixOfIncidence(std::vector<std::vector<short int>> mx);
    // transforms 'AdjacencyMatrix' object
    // to the 'Graph' object
    Graph toAdjacencyList() override;
    // transforms 'MatrixOfIncidence' object
    // to the 'AdjacencyMatrix'
    // it is used in toAdjacencyList() method
    AdjacencyMatrix toAdjacencyMatrix();
private:
    // row and columns
    size_t peaks, edges;
};

#endif