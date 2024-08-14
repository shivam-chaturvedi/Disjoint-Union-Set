# Disjoint Set Union (DSU) with Path Compression and Union by Rank in C++

This repository contains an implementation of the Disjoint Set Union (DSU) data structure, also known as Union-Find, with optimizations such as **Path Compression** and **Union by Rank**. This data structure is fundamental in computer science, especially in the fields of graph theory and network connectivity.

## Table of Contents
- [Introduction](#introduction)
- [Theory](#theory)
- [Features](#features)
- [Usage](#usage)
- [Code Snippets](#code-snippets)
- [Applications](#applications)
- [How to Run](#how-to-run)
- [Contributing](#contributing)


## Introduction

The Disjoint Set Union (DSU) is a data structure that keeps track of a partition of a set into disjoint (non-overlapping) subsets. It supports two primary operations:

1. **Find:** Determine the representative (or root) of the set containing a particular element.
2. **Union:** Merge two sets into a single set.

These operations are extremely efficient when using optimizations like **Path Compression** and **Union by Rank**, making DSU a powerful tool for solving problems involving connected components, cycle detection, and minimum spanning trees in graphs.

## Theory

### Disjoint Set
A Disjoint Set is a collection of non-overlapping sets. Each set is identified by a unique representative or root. The two primary operations of a Disjoint Set are:

- **Find:** Identify the set to which a particular element belongs.
- **Union:** Merge two different sets into a single set.

### Path Compression
Path Compression is an optimization technique used in the `find` operation. When a node is queried for its root, all nodes along the path from the node to the root are connected directly to the root. This reduces the depth of the tree, making subsequent operations faster.

### Union by Rank
Union by Rank is an optimization used in the `union` operation. When merging two sets, the root of the set with the smaller rank (tree height) is made a child of the root with the larger rank. This ensures that the tree remains balanced, keeping the operations efficient.

## Features

- **Path Compression:** Optimizes the `find` operation to speed up future queries.
- **Union by Rank:** Keeps the tree structure balanced during the `union` operation.
- **Check Connectivity:** Determine if two elements are in the same set.
- **Template-Based:** The class is templated, allowing you to define the size of the set at compile time.

## Usage

To use this DSU implementation, include the `DisjointSetUnion` class in your C++ project. The class provides methods for creating unions, finding roots, and checking connectivity between elements.

### Example

```cpp
#include "DisjointSetUnion.h"

int main() {
    DisjointSetUnion<5> dsu;

    dsu.union_set(0, 2);
    dsu.union_set(1, 2);
    dsu.union_set(3, 4);

    cout << "Is 0 and 4 connected? " << (dsu.isConnected(0, 4) ? "Yes" : "No") << endl;
    cout << "Is 0 and 1 connected? " << (dsu.isConnected(0, 1) ? "Yes" : "No") << endl;

    return 0;
}
```

## Code Snippets

### Find with Path Compression

```cpp
int find(int n) {
    if (parent[n] != n) {
        parent[n] = find(parent[n]); // Path Compression
    }
    return parent[n];
}
```

### Union by Rank

```cpp
void union_set(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_v] > rank[root_u]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}
```

### Check Connectivity

```cpp
bool isConnected(int u, int v) {
    return find(u) == find(v);
}
```

## Applications

The DSU data structure is widely used in algorithms that involve partitioning a set into subsets. Some key applications include:

- **Minimum Spanning Tree (MST):** Used in Kruskal's algorithm to determine the MST of a graph.
- **Cycle Detection:** Detects cycles in an undirected graph.
- **Network Connectivity:** Determines if there is a path between any two nodes in a network.
- **Dynamic Connectivity:** Supports dynamic queries to determine if two nodes are in the same connected component.

## How to Run

To compile and run the code, follow these steps:

1. Save the code in a file named `main.cpp`.
2. Use a C++ compiler to compile the code:
   ```bash
   g++ -o dsu main.cpp
   ```
3. Run the compiled program:
   ```bash
   ./dsu
   ```

## Contributing

Contributions are welcome! If you have any suggestions, improvements, or new features to add, feel free to fork the repository and submit a pull request.
