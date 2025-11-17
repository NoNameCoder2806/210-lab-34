// COMSC-210 | Lab 34 | Dat Hoang Vien
// IDE used: Visual Studio Code

#pragma once

// Libraries
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Edge.h"
using namespace std;

// Constants
const int SIZE = 7;

// Creates alias 'Pair' for the pair<int, int> data type
typedef pair<int, int> Pair;          // Adjacent vertex, weight

// Graph class
class Graph
{
public:
    // Create a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;          // The list of adjacent vertices of the vertices

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
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < adjList.size(); i++)
        {
            cout << i << " --> ";
            for (Pair v : adjList[i])
                cout << "(" << v.first << ", " << v.second << ") ";
            cout << endl;
        }
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
        // Create 2 queues to store all the vertices of the next level
        queue<int> next;           // Store all the vertices of the next level
        next.push(start);          // Add the starting vertex into the queue

       // Iterate and display all the vertices
        while (next.size() > 0)
        {
            // Get the front element
            int vertex = next.front();

            // Iterate and find all the next level vertices of the current vertex
            for (int i = 0; i < adjList.at(vertex).size(); i++)
            {
                next.push(adjList.at(vertex).);
            }
        }

        // Display all the neighbors of start
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
        // 
    }
};