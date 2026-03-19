#include <stdio.h>
#include <string.h>
#define MAX 100
#define INF 99999

/*
PROBLEM STATEMENT:
Given a weighted graph (non-negative weights),
find the shortest distance from a source vertex to all other vertices
using Dijkstra’s Algorithm.

APPROACH:
1. Initialize:
   - dist[source] = 0
   - all other distances = INF
   - visited[] = 0
2. Repeat for all vertices:
   a. Pick the unvisited vertex u with minimum distance
   b. Mark u as visited
   c. For all adjacent vertices v:
        If not visited and edge exists:
            If dist[v] > dist[u] + weight(u,v):
                Update dist[v]
3. After all iterations, dist[] contains shortest paths.

INTUITION:
- Always pick the closest unvisited node (greedy approach)
- Gradually expand shortest path tree

TIME COMPLEXITY:
- O(V^2) using adjacency matrix
*/

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];

// Function to find vertex with minimum distance
int findMin(int n) {
    int min = INF, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra function
void dijkstra(int source, int n) {
    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    // Do not use memset because dist[] is int array and we want to set to INF, not 0
    // memset(dist, INF, sizeof(dist)); // This would not work as expected
    // Use memset only when setting to 0 or -1, for other values we need a loop

    dist[source] = 0;

    // Loop for all vertices
    for (int i = 0; i < n - 1; i++) {
        int u = findMin(n);
        if (u == -1) break;

        visited[u] = 1;

        // Relaxation step
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] != 0) {
                if (dist[v] > dist[u] + adj[u][v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }
}

int main() {
    int n = 5, source = 0;

    // Example weighted graph
    int input[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    // Copy matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    dijkstra(source, n);

    // Output
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}