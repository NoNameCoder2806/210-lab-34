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
        {0, 1, 8},
        {1, 4, 2},
        {3, 4, 6},
        {2, 3, 9},
        {1, 2, 4},
        {1, 3, 5}
    };

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();
    
    // Create a starting vertex
    int start = 0;

    // DFS implementation
    cout << "DFS starting from vertex " << start << ": " << endl;
    graph.dfs(start);
    cout << endl;

    // BFS implementation
    cout << "BFS starting from vertex " << start << ": " << endl;
    graph.bfs(start);
    cout << endl;

    return 0;
}
