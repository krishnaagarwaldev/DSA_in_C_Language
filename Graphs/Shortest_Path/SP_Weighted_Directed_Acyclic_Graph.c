#include <stdio.h>
#define MAX 100
#define INF 99999

/*
PROBLEM STATEMENT:
Given a Directed Acyclic Graph (DAG) with weighted edges,
find the shortest path from a given source vertex to all other vertices.

APPROACH:
1. Perform Topological Sort of the graph.
2. Initialize distance array:
   - dist[source] = 0
   - all others = INF
3. Process vertices in topological order:
   - For each vertex u:
       If dist[u] != INF:
           For every adjacent vertex v:
               If dist[v] > dist[u] + weight(u,v):
                   Update dist[v]
4. After processing all vertices, dist[] contains shortest paths.

INTUITION:
- Topological order ensures that we process a node
  only after all its dependencies are processed.
- This avoids repeated relaxation like in Bellman-Ford.

TIME COMPLEXITY: O(V + E)
*/

int adj[MAX][MAX];   // stores weights (0 means no edge)
int visited[MAX];
int stack[MAX];
int top = -1;
int dist[MAX];

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS for Topological Sort
void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] != 0 && !visited[i]) {
            dfs(i, n);
        }
    }

    push(v);
}

// Topological Sort
void topoSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }
}

// Shortest Path in DAG
void shortestPath(int source, int n) {
    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Process vertices in topological order
    while (top != -1) {
        int u = stack[top--];

        if (dist[u] != INF) {
            for (int v = 0; v < n; v++) {
                if (adj[u][v] != 0) {
                    if (dist[v] > dist[u] + adj[u][v]) {
                        dist[v] = dist[u] + adj[u][v];
                    }
                }
            }
        }
    }
}

int main() {
    int n = 6, source = 0;

    // Example DAG (weighted)
    int input[6][6] = {
        {0, 2, 4, 0, 0, 0},
        {0, 0, 1, 7, 0, 0},
        {0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 1, 5},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0}
    };

    // Copy matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    // Step 1: Topological Sort
    topoSort(n);

    // Step 2: Shortest Path
    shortestPath(source, n);

    // Output
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("To %d = INF\n", i);
        else
            printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}