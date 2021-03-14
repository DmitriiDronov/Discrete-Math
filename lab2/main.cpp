#include "../lab1/menuUtils.hpp"
#include <iostream>
#include <list>
#include <climits>
#include <iomanip>

typedef std::vector<std::list<std::pair<int, int>>> AdjList;
typedef std::vector<std::pair<int, int>> ShortestDistances;

std::vector<AdjList>& adjListCollector();
AdjList createAdjList(int vertices, int edges);
void printAdjList(const AdjList& list);
void printAdjListCollector(const std::vector<AdjList>& adjListCollector);

void PrintNegativeCycle(const std::vector<std::pair<int, int>> shortestDistances, 
                        const int vertex, const int startVertex);
int bellmanFord(const AdjList list, const int vertices, 
                const int startVertice, ShortestDistances& shortestDistances);

int main(void)
{
    int choice = 0;
    unsigned int index{ 0 };
    int vertices{ 0 }, edges{ 0 };
    do 
    {
        Menu menu = {{1, "Input an adjacency list",},
                    {2, "Display data",},
                    {3, "Find shortest path"},
                    {0, "Exit"},};
        clearScreen();
        PrintMenu(menu);
    
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the number of vertices: ";
            std::cin >> vertices;
            std::cout << "Enter the nubmer of edges: ";
            std::cin >> edges; 
            adjListCollector().push_back(createAdjList(vertices, edges));
            break;
        case 2:
            printAdjListCollector(adjListCollector());
            pause();
            break;
        case 3:
            std::cout << "Enter an index of matrix you want to procceed with: ";
            std::cin >> index;
            if (!adjListCollector().empty())
            {
                if (!adjListCollector().at(index).empty())
                {
                    AdjList list = adjListCollector().at(index);
                    printAdjList(list);
                    ShortestDistances shortestDistances(vertices + 1);
                    int startVertex{ 0 };
                    std::cout << "Enter a start vertex: ";
                    std::cin >> startVertex;
                    int returnVal = bellmanFord(list, vertices, startVertex, shortestDistances);
                    if (returnVal == -1)
                        std::cout << "No negative cycles." << std::endl;
                    else
                    {
                        std::cout << "Negative cycles exist." << std::endl;
                        // PrintNegativeCycle(shortestDistances, 
                        // shortestDistances.at(returnVal).second, returnVal);
                        break;
                    }
                printf("\n\nVertex    Shortest Distance to Vertex %d     Parent Vertex-\n", startVertex);
                for (int i = 1; i <= vertices; ++i) 
                {
                printf("%d \t  %d \t\t\t\t    %d\n", i, shortestDistances[i].first,
                                                shortestDistances[i].second);
                }
            }
            pause();
            break;
        case 0:
            return EXIT_SUCCESS;
        default:
            break;
            }
        }   
    } while (choice != 0);
    return EXIT_SUCCESS;
}

AdjList createAdjList(int vertices, int edges)
{
    AdjList adjacencyList(vertices + 1);

    int v1{ 0 }, v2{ 0 }, weight{ 0 };
    std::cout << "Enter pairs(V1->V2) of weight W: " << std::endl;
    for (int i{ 1 }; i <= edges; ++i)
    {
        std::cout << "Enter V1, V2 and W separated by space: ";
        std::cin >> v1 >> v2 >> weight;
        adjacencyList.at(v1).push_back(std::make_pair(v2, weight));
    }
    return adjacencyList;
}

std::vector<AdjList>& adjListCollector()
{
    static std::vector<AdjList> collector;
    return collector;
}

void printAdjList(const AdjList& list)
{
    for (unsigned int i{ 1 }; i < list.size(); ++i)
    {
        auto it = list.at(i).cbegin();
        std::cout << "AdjList[" << i << "]";
        while (it != list.at(i).cend())
        {
            std::cout << " -> " << it->first << "(" << it->second << ")";
            ++it;
        }
        std::cout << std::endl;
    }
}

void printAdjListCollector(const std::vector<AdjList>& adjListCollector)
{
    for (AdjList list : adjListCollector)
        printAdjList(list);
}

int bellmanFord(const AdjList list, const int vertices, 
                const int startVertice, ShortestDistances& shortestDistances)
{
    int i { 0 }, j{ 0 };
    std::list<std::pair<int, int>>::const_iterator traverse; 
    // Initialisation
    for (i = 0; i <= vertices; ++i) 
    {
        shortestDistances.at(i).first = INT_MAX;
        shortestDistances.at(i).second = -1;
    }
     
    // Setting distance to source = 0
    shortestDistances.at(startVertice).first = 0;
    shortestDistances.at(startVertice).second = 0;
     
    // The Algorithm that computes Shortest Distances
    // Runs 'vertices - 1' times = O(|V|)
    for (i = 1; i <= vertices - 1; ++i) 
    {    
        // Runs as many times as the edges = O(|E|)
        // The code ahead basically explores the whole of Adjcency List,
        // covering one edge once, so the runtime of the code in this 
        // block is O(|E|)
        for (j = 1; j <= vertices; ++j) 
        {    
            auto traverse = list.at(j).cbegin();
             
            while (traverse != list.at(j).cend()) 
            {
                if (shortestDistances[j].first == INT_MAX) 
                {
                    ++traverse;
                    continue;
                }
                // Checking for Relaxation
                if ((*traverse).second + shortestDistances.at(j).first < 
                    shortestDistances.at((*traverse).first).first) 
                {
                    // Relaxation
                    shortestDistances.at((*traverse).first).first = (*traverse).second
                                        + shortestDistances.at(j).first;
                    shortestDistances.at((*traverse).first).second = j;
                }
                ++traverse;
            }
        }
    }
     
    // Checking for Negative Cycles
    for (j = 1; j <= vertices; ++j) 
    {
        traverse = list.at(j).cbegin();
        while (traverse != list.at(j).cend()) 
        {
            // Checking for further relaxation
            if ((*traverse).second + shortestDistances.at(j).first < 
                shortestDistances.at((*traverse).first).first) 
            {
                // Negative Cycle found as further relaxation is possible
                return j;
            }
            ++traverse;
        }
    }
    return -1;
}

void PrintNegativeCycle(const std::vector<std::pair<int, int>> shortestDistances, 
                        const int vertex, const int startVertex)
{
    if (vertex == startVertex) 
        std::cout << vertex << " ";
    else if (shortestDistances.at(vertex).second == 0) 
    {
        PrintNegativeCycle(shortestDistances, startVertex, startVertex);
        std::cout << vertex << " ";
    } 
    else 
    {
        PrintNegativeCycle(shortestDistances, shortestDistances.at(vertex).second, startVertex);
        std::cout << vertex << " ";
    }
}