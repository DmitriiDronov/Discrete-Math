#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <list>
#include <memory>
#include <vector>

class Graph
{
private:
    int numVertices;
    std::shared_ptr<std::list<int>> adjList;
public:
    Graph(int vertices);
    void addEdge(int src, int dest);
};

class MatrixOfIncidence
{
private:
    std::vector<std::vector<short int>> matrix;
    //row and columns
    int peaks, edges;
public:
    MatrixOfIncidence(int numOfPeaks, int numOfEdges);
};

//need to create virual class for both matrices
class AdjacencyMatrix
{
};

#endif