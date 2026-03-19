#include <stdio.h>
#define MAX 100
#define INF 99999

/*
PROBLEM STATEMENT:
Given a weighted directed graph (weights may be negative), 
find the shortest path from a source vertex to all other vertices
using Bellman-Ford Algorithm. Detect negative weight cycles.

APPROACH:
1. Initialize:
   - dist[source] = 0, all others = INF
   - parent[] = -1 (to store path)
2. Relax all edges (n-1) times:
   - For every edge u->v with weight w:
       if dist[u] + w < dist[v]:
           dist[v] = dist[u] + w
           parent[v] = u
3. Check for negative cycles:
   - If any edge u->v can still be relaxed, negative cycle exists
4. Use parent[] to reconstruct shortest path from source to any destination

INTUITION:
- Repeated relaxation ensures shortest paths (even with negative weights)
- Detecting extra relaxation shows negative cycles

TIME COMPLEXITY: O(V^3) for adjacency matrix (O(V*E) in adjacency list)
*/

int adj[MAX][MAX];
int dist[MAX];
int parent[MAX];
int n;

// Print path from source to destination
void printPath(int dest) {
    if (dest == -1)
        return;
    printPath(parent[dest]);
    printf("%d ", dest);
}

int bellmanFord(int source) {
    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;

    // Relax all edges (n-1) times
    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (adj[u][v] != 0 && dist[u] != INF) {
                    if (dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                        parent[v] = u;
                    }
                }
            }
        }
    }

    // Check for negative weight cycles -> Means after n-1 relaxations, if we can still relax, then negative cycle exists
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && dist[u] != INF) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    return 0; // negative cycle detected
                }
            }
        }
    }

    return 1; // no negative cycle
}

int main() {
    n = 5;
    int source = 0, dest = 4;

    int input[5][5] = {
        {0, 6, 0, 7, 0},
        {0, 0, 5, 8, -4},
        {0, -2, 0, 0, 0},
        {0, 0, -3, 0, 9},
        {2, 0, 7, 0, 0}
    };

    // Copy adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    if (bellmanFord(source)) {
        printf("Shortest Distance from %d to %d = %d\n", source, dest, dist[dest]);
        printf("Path: ");
        printPath(dest);
    } else {
        printf("Graph contains a negative weight cycle\n");
    }

    return 0;
}