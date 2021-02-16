#ifndef MATRIX_HPP_H
#define MATRIX_HPP_H
#include "Graph.hpp"

//this is abstract interface class
class Matrix
{
public:
    virtual void edit() = 0;
    virtual Graph toAdjacencyList() = 0;
};

class MatrixOfIncidence : public Matrix
{
private:
    std::vector<std::vector<short int>> matrix;
    //row and columns
    int peaks, edges;
public:
    MatrixOfIncidence(int numOfPeaks, int numOfEdges);
    friend std::ostream& operator<<(std::ostream& os, const MatrixOfIncidence& rhs);
    void edit(void) override;
    Graph toAdjacencyList() override;
};

class AdjacencyMatrix : public Matrix
{
private:
    std::vector<std::vector<short int>> matrix;
    int vertices;
public:
    AdjacencyMatrix(int numOfVertices);
    friend std::ostream& operator<<(std::ostream &os, const AdjacencyMatrix &rhs);
    void edit(void) override;
    Graph toAdjacencyList() override;
};

#endif