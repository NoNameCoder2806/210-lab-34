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
}

