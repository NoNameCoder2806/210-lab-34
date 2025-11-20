// COMSC-210 | Lab 34 | Dat Hoang Vien
// IDE used: Visual Studio Code

#pragma once

// Libraries
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include "Edge.h"
using namespace std;

// UnionFind class
class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor
    UnionFind(int n)
    {
        // Resize the parent and rank to hold the right size
        parent.resize(n);
        rank.resize(n, 0);          // Initialize all the first elements to be 0

        // Initialize all the parents
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    /*
        find()
        Find the root of the sequence / set of connected vertices
        Arguments:
            - x: the vertex
        Return: an integer representing the root of the vertex
    */
    int find(int x)
    {
        // Check whether the parent is itself (the starting vertex)
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);          // Recursively find the root of the root
        }

        return parent[x];
    }
    
    /*
        unionFind()
        Attach the vertices together
        Arguments:
            - x: vertex x (or the sequence with root x)
            - y: vertex y (or the sequence with root y)
        Return: none
    */
    void unionFind(int x, int y)
    {
        // Find the roots of the x and y vertices
        int rootX = find(x);
        int rootY = find(y);

        // Check whether they have the same value
        if (rootX == rootY)
        {
            // If they do, it means that they are already in the same set
            return;          // Exit the function, no merge needed
        }

        // Union by rank: attach smaller tree under larger tree
        if (rank[rootX] < rank[rootY])
        {
            // If the rank is smaller we let y root be the parent / root of the x root vertex
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            // Otherwise if rank is larger, we let x root be the parent of y root
            parent[rootY] = rootX;
        }
        else
        {
            // If same rank, we can pick either and increase the rank of the chosen new root
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
