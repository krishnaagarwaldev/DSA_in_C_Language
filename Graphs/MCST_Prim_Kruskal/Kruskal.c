#include <stdio.h>

#define MAX 100

/*
PROBLEM STATEMENT:
Given a weighted undirected graph, find the Minimum Spanning Tree (MST)
using Kruskal's Algorithm.

APPROACH:
1. Create a list of all edges with weights.
2. Sort edges in increasing order of weight.
3. Initialize a parent array for Union-Find (Disjoint Set):
   - parent[i] = i
4. For each edge (u, v):
   - If u and v belong to different sets (no cycle):
       - Include edge in MST
       - Union the sets of u and v
5. Repeat until MST has V-1 edges.

INTUITION:
- Always pick the **smallest edge** that does **not form a cycle**.
- Use Union-Find to check cycles efficiently.
- MST edges = V-1 edges with minimum total weight.

CYCLE DETECTION: Using Union-Find (Disjoint Set) data structure
- find(): Find parent/root of a vertex
- union(): Union two sets if they are from different components

TIME COMPLEXITY: O(E log E) for sorting + O(E α(V)) for union-find operations
SPACE COMPLEXITY: O(V + E)
*/


typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

// Find root of set (with path compression optional)
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union two sets
void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Simple bubble sort edges by weight
void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal's Algorithm
void kruskal(Edge edges[], int V, int E) {
    int mstWeight = 0;
    int edgeCount = 0;

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight
    sortEdges(edges, E);

    printf("Edges in MST:\n");

    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int setU = find(u);
        int setV = find(v);

        // If including this edge doesn't cause cycle
        if (setU != setV) {
            printf("%d - %d  weight: %d\n", u, v, w);
            mstWeight += w;
            unionSet(u, v);
            edgeCount++;
        }
    }

    printf("Total weight of MST = %d\n", mstWeight);
}

int main() {
    int V = 4, E = 5;

    Edge edges[5] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

    return 0;
}