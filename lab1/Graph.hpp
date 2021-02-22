#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <list>
#include <memory>
#include <vector>
#include <iostream>
#include "Matrix.hpp"

typedef std::vector<std::list<int>> AdjacencyList;

class Graph
{
private:
    int numVertices;
    std::shared_ptr<AdjacencyList> adjList;
public:
    Graph(int vertices);
    //to test
    Graph(std::shared_ptr<AdjacencyList> adjListPtr, int vertices);
    //to test
    Graph(AdjacencyMatrix matrix);
    void addEdge(int src, int dest);
    friend std::ostream& operator<<(std::ostream &os, const Graph &rhs);
    MatrixOfIncidence toMatrixOfIncidence();
    AdjacencyMatrix toAdjacencyMatrix();
};

std::vector<Graph>& Graphs();

#endif