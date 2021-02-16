#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <list>
#include <memory>
#include <vector>
#include <iostream>
#include "Matrix.hpp"

class Graph
{
private:
    int numVertices;
    std::shared_ptr<std::list<int>> adjList;
public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    friend std::ostream& operator<<(std::ostream &os, const Graph &rhs);
    MatrixOfIncidence toMatrixOfIncidence();
    AdjacencyMatrix toAdjacencyMatrix();
};

#endif