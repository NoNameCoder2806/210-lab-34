// COMSC-210 | Lab 34 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries and headers
#include <iostream>
#include <vector>
#include "Edge.h"
#include "Graph.h"
using namespace std;

// Main() function
int main()
{
    // Creates a vector of graph edges / weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0, 1, 1000},
        {1, 4, 500},
        {3, 4, 700},
        {2, 3, 1100},
        {1, 2, 800},
        {1, 3, 600},
        {0, 5, 900},
        {5, 6, 400},
        {6, 2, 700},
        {3, 7, 800},
        {7, 8, 300},
        {8, 4, 600},
        {9, 0, 1200},
        {10, 5, 200},
        {9, 11, 500},
        {11, 10, 400}
    };

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();
    
    // Create a starting vertex
    int start = 0;

    // DFS implementation
    graph.dfs(start);
    cout << endl;

    // BFS implementation
    graph.bfs(start);
    cout << endl;

    // Create a vector the store the shortest paths
    int source = 0;
    vector<int> shortestPaths = graph.djikstra(graph.adjList, source);

    // Display a message
    cout << "Shortest path from " << graph.locationNames[source] << "(" << source << "): ";
    cout << endl;

    // Display all the shortest paths
    for (int i = 0; i < shortestPaths.size(); i++)
    {
        // Display the distances
        cout << "    --> " << graph.locationNames.at(i) << "(" << i << "): ";
        cout << shortestPaths.at(i) << "m" << endl;
    }

    // Enter a new line
    cout << endl;

    // Create a new vector to store the minimum spanning tree
    vector<Edge> mst = graph.kruskal(edges);

    // Display the minimum spanning tree
    cout << "Jurassic Park Minimum Spanning Tree For All Locations:" << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        // 
        cout << "From " << graph.locationNames.at(mst.at(i).src) << " (" << mst.at(i).src << ") ";
        cout << "To "
    }

    // 

    return 0;
}
