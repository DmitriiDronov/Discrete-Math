#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <list>
#include <memory>

class Graph
{
private:
    int numVertices;
    std::shared_ptr<std::list<int>> adjList;
public:
    Graph(int vertices);
    void addEdge(int src, int dest);
};

#endif