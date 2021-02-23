#ifndef MATRIX_HPP_H
#define MATRIX_HPP_H
#include "Graph.hpp"
class Graph;

//this is abstract interface class
class Matrix
{
public:
    virtual void edit();
    virtual Graph toAdjacencyList() = 0;
    friend std::ostream& operator<<(std::ostream &os, const Matrix &rhs);
protected:
    std::vector<std::vector<short int>> matrix;
};

class AdjacencyMatrix : public Matrix
{
private:
    int vertices;
public:
    AdjacencyMatrix(int numOfVertices);
    AdjacencyMatrix(std::vector<std::vector<short int>> matrix);
    Graph toAdjacencyList() override;
};

class MatrixOfIncidence : public Matrix
{
private:
    //row and columns
    int peaks, edges;
public:
    MatrixOfIncidence(int numOfPeaks, int numOfEdges);
    Graph toAdjacencyList() override;
    AdjacencyMatrix toAdjacencyMatrix();
};

#endif