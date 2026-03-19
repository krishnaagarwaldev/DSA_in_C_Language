#include <stdio.h>
#define MAX 100
#define INF 99999

/*
PROBLEM STATEMENT:
Given a connected, weighted, undirected graph,
find its Minimum Spanning Tree (MST) using Prim’s Algorithm.

APPROACH:
1. Initialize:
   - key[] = INF (minimum edge weight to include in MST)
   - parent[] = -1 (store MST structure)
   - visited[] = 0
2. Start from any vertex (e.g., 0):
   - key[0] = 0
3. Repeat for all vertices:
   a. Pick unvisited vertex u with minimum key[u]
   b. Mark u as visited
   c. For all adjacent vertices v of u:
       - If v not visited and weight(u,v) < key[v]:
           - key[v] = weight(u,v)
           - parent[v] = u
4. After all vertices are included, parent[] describes MST.

INTUITION:
- Greedy approach → always pick **lightest edge** connecting MST to new vertex
- Ensures **minimum total weight**

TIME COMPLEXITY:
- O(V^2) using adjacency matrix
*/

int adj[MAX][MAX];
int key[MAX]; // Minimum edge weight to include vertex in MST
int parent[MAX];
int visited[MAX];

// Function to find vertex with minimum key value
int minKey(int n) {
    int min = INF, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Prim's MST function
void primMST(int n) {
    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    key[0] = 0; // start from vertex 0

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(n); // Pick vertex with minimum key
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    printf("Edges in MST:\n");
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d - %d : %d\n", parent[i], i, adj[i][parent[i]]);
            totalWeight += adj[i][parent[i]];
        }
    }
    printf("Total weight of MST = %d\n", totalWeight);
}

int main() {
    int n = 5;

    int input[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Copy adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    primMST(n);

    return 0;
}