// COMSC-210 | Lab 34 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries and headers
#include <iostream>
#include <vector>
#include "Edge.h"
#include "Graph.h"
using namespace std;

// Constants
const int MIN_CHOICE = 0;
const int MAX_CHOICE = 5;

// Function prototypes
void displayMenu();

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

    // Create a loop for the operations
    while (true)
    {
        // Create a variable to hold the user's choice
        int choice = 0;

        // Display the menu
        displayMenu();

        // Prompt the user to enter their choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Validate the input
        while (choice < MIN_CHOICE || choice > MAX_CHOICE)
        {
            // Display an error message
            cout << "Invalid! Please enter a valid choice (0-5)!" << endl;

            // Display the menu again
            displayMenu();

            // Prompt the user to enter a new choice
            cout << "Enter your choice: ";
            cin >> choice;
        }

        // Create a starting vertex
        int start = 0;

        // Switch cases for the choice
        switch(choice)
        {
            // Display the adjacency list
            case 1: 
            {
                // Call the printGraph() function
                graph.printGraph();

                break;
            }

            // Implement BFS from vertex 0
            case 2:
            {
                // Call the bfs() function
                graph.bfs(start);
                cout << endl;

                break;
            }

            // Implement DFS from vertex 0
            case 3:
            {
                // Call the dfs() function
                graph.dfs(start);
                cout << endl;

                break;
            }

            // Shortest Paths from vertex 0
            case 4:
            {
                // Create a vector the store the shortest paths and call djikstra() function
                vector<int> shortestPaths = graph.djikstra(graph.adjList, start);

                // Display a message
                cout << "Shortest path from " << graph.locationNames[start] << "(" << start << "): ";
                cout << endl;

                // Display all the shortest paths
                for (int i = 0; i < shortestPaths.size(); i++)
                {
                    // Display the distances
                    cout << " --> " << graph.locationNames.at(i) << "(" << i << "): ";
                    cout << shortestPaths.at(i) << "m" << endl;
                }

                // Enter a new line
                cout << endl;

                break;
            }

            // Minimum Spanning Tree
            case 5:
            {
                // Create a new vector to store the minimum spanning tree
                vector<Edge> mst = graph.kruskal(edges);

                // Display the minimum spanning tree
                cout << "Jurassic Park Minimum Spanning Tree For All Locations:" << endl;
                for (int i = 0; i < mst.size(); i++)
                {
                    // Display the Edge
                    cout << " --> ";
                    cout << "From " << graph.locationNames.at(mst.at(i).src) << " (" << mst.at(i).src << ") ";
                    cout << "To " << graph.locationNames.at(mst.at(i).dest) << " (" << mst.at(i).dest << "): ";
                    cout << mst.at(i).weight << "m" << endl;
                }

                // Enter a new line
                cout << endl;

                break;
            }

            // Exit
            case 0:
            {
                // Display a message
                cout << "Thank you for using the program! Exiting..." << endl;

                // Exit the main function
                return 0;
            }
        }
    }

    return 0;
}

// Function implementations
/*
    displayMenu()
    Display the menu of operations on the Jurassic Park locations graph
    Arguments: none
    Return: none
*/
void displayMenu()
{
    // Display a header
    cout << "Jurassic Park Locations Network Menu:" << endl;

    // Display all the options
    cout << "[1] Jurassic Park Road Map" << endl;
    cout << "[2] Explore Park (BFS)" << endl;
    cout << "[3] Go On Deep Exploration (DFS)" << endl;
    cout << "[4] Calculate Shortest Paths From Main Gate" << endl;
    cout << "[5] Find Minimum Spanning Tree of All Locations" << endl;
    cout << "[0] Exit" << endl;
}