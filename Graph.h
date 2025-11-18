// COMSC-210 | Lab 34 | Dat Hoang Vien
// IDE used: Visual Studio Code

#pragma once

// Libraries
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include "Edge.h"
using namespace std;

// Constants
const int SIZE = 12;

// Creates alias 'Pair' for the pair<int, int> data type
typedef pair<int, int> Pair; // Adjacent vertex, weight

// Graph class
class Graph
{
public:
    // Create a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList; // The list of adjacent vertices of the vertices

    // Create a vector to store the vertex names for Jurassic Park locations
    vector<string> locationNames = {
        "Main Gate / Entrance",                // 0
        "Visitor Center",                      // 1
        "T-Rex Paddock",                       // 2
        "Velociraptor Pen",                    // 3
        "Dilophosaurus Enclosure",             // 4
        "Brachiosaurus Feeding Area",          // 5
        "Gyrosphere Track",                    // 6
        "Maintenance Shed",                    // 7
        "Jurassic Park Lagoon",                // 8
        "Helipad",                             // 9
        "Research Lab",                        // 10
        "Visitor Camps / Rest Areas"           // 11
    };

    // Graph Constructor
    Graph(vector<Edge> const &edges)
    {
        // Resize the vector to hold SIZE elements of type vector<Edge>
        adjList.resize(SIZE);

        // Add edges to the directed graph
        for (auto &edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            // Insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            // For an undirected graph, add an edge from dest to src also
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    // Print the graph's adjacency list
    void printGraph()
    {
        // Display a header
        cout << "Jurassic Park Road Map:" << endl;
        cout << "=======================" << endl;

        // Display all the vertices / locations
        for (int i = 0; i < adjList.size(); i++)
        {
            // Display the sources
            cout << locationNames.at(i) << " (" << i << "):" << endl;
    
            // Display all the destinations and weights
            for (Pair v : adjList[i])
            {
                cout << " --> Pathway to ";
                cout << locationNames.at(v.first) << " (" << v.first << ") - (" << v.second << "m) ";
                cout << endl;
            }
        }

        // Enter a new line
        cout << endl;
    }

    /*
        bfs()
        Breadth first search function
        Arguments:
            - start: the starting vertex
        Return: none
    */
    void bfs(int start)
    {
        // Display a header
        cout << " --- Visitor Layered Exploration Route (BFS) from " << locationNames.at(start) << " (" << start << ") --- " << endl;
        cout << "Purpose: Visiting all nearby attractions level by level before moving" << endl;
        cout << "deeper into the park." << endl;
        cout << "===========================================================================" << endl;

        // Create a queue and a vector
        queue<int> next;                            // Store all the vertices of the next level
        vector<bool> visited(SIZE, false);          // Store all the vertices and whether they were visited
        next.push(start);                           // Add the starting vertex into the queue
        visited.at(start) = true;                   // Mark the starting vertex as visited immediately

        // Iterate and display all the vertices
        while (!next.empty())
        {
            // Get the front element
            int vertex = next.front();

            // Remove the first vertex of the queue
            next.pop();

            // Otherwise, display the vertex
            cout << "Arrived at: " << locationNames.at(vertex) << " (" << vertex << ")" << endl;

            // Iterate and find all the next level vertices of the current vertex
            for (int i = 0; i < adjList.at(vertex).size(); i++)
            {
                int neighbor = adjList.at(vertex).at(i).first;
                int distance = adjList.at(vertex).at(i).second;

                // Announce nearby attractions (even if visited later)
                cout << " --> Nearby attractions: ";
                cout << locationNames.at(neighbor) << " (" << neighbor << ") - (" << distance << "m)";
                cout << endl;

                // Check whether the vertex was previously visited
                if (visited.at(neighbor))
                {
                    // Ignore and don't add to the queue
                    continue;
                }

                // Otherwise, add the vertex to the end of the list
                next.push(neighbor);
                visited.at(neighbor) = true;          // Mark the vertex as visited when enqueued
            }
        }
    }

    /*
        dfs()
        Depth first search function
        Arguments:
            - start: the starting vertex
        Return: none
    */
    void dfs(int start)
    {
        // Display a header
        cout << " --- Visitor Deep Exploration Route (DFS) from " << locationNames.at(start) << " (" << start << ") --- " << endl;
        cout << "Purpose: Following a visitor who chooses one path and continues exploring" << endl;
        cout << "the deepest connected attractions before backtracking." << endl;
        cout << "===========================================================================" << endl;

        // Create a stack and a vector
        stack<int> next;                            // Store all the vertices of the next level
        vector<bool> visited(SIZE, false);          // Store all the vertices and whether they were visited
        next.push(start);                           // Add the starting vertex into the queue

        // Iterate and display all the vertices
        while (!next.empty())
        {
            // Get the top element
            int vertex = next.top();

            // Pop the top element from the stack
            next.pop();

            // Skip if the vertex was already visited
            if (visited.at(vertex))
            {
                continue;
            }

            // Otherwise, display the vertex
            cout << "Arrived at: " << locationNames.at(vertex) << " (" << vertex << ")" << endl;
            visited.at(vertex) = true;           // Mark the vertex as visited
            
            // Iterate and get the next vertices
            for (int i = 0; i < adjList.at(vertex).size(); i++)
            {
                int neighbor = adjList.at(vertex).at(i).first;
                int distance = adjList.at(vertex).at(i).second;

                // Check whether the vertex was previously visited
                if (visited.at(neighbor))
                {
                    // Ignore and don't add to the stack
                    continue;
                }

                // Display the vertex
                cout << " --> Possible route to: ";
                cout << locationNames.at(neighbor) << " (" << neighbor << ") - (" << distance << "m)";
                cout << endl;

                // Otherwise, add the vertex to the end of the list
                next.push(neighbor);
            }
        }
    }

    /*
        djikstra()
        Find the shortest path from a source to a destination
        Arguments:
            - 
        Return: none
    */
    vector<int> djikstra(const vector<vector<Pair>>& adjList, int source, int destination)
    {
        // Create and use a priority queue to store the distances
        // The first argument stores the data type
        // The second argument is the container that stores all the elements
        // The third argument specify the comparison (i.e. greater, less)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    }
};