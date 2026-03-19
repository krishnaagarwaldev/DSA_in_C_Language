#include <stdio.h>
#define MAX 100
#define INF 99999

/*
PROBLEM STATEMENT:
Given a weighted graph (non-negative weights),
find the shortest path from a given source vertex to a destination vertex
using Dijkstra’s Algorithm. Also print the actual path.

APPROACH:
1. Initialize:
   - dist[source] = 0, others = INF
   - visited[] = 0
   - parent[] = -1 (to store path)
2. Repeat:
   a. Pick unvisited node u with minimum dist
   b. Mark u visited
   c. For all adjacent vertices v:
        If dist[v] > dist[u] + weight(u,v):
            Update dist[v]
            parent[v] = u
3. After completion:
   - dist[dest] gives shortest distance
   - Use parent[] to reconstruct path (backtrack)

INTUITION:
- Same as Dijkstra, but store parent to rebuild path

TIME COMPLEXITY: O(V^2)
*/

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];

// Find minimum distance vertex
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

// Print path from source to destination
void printPath(int dest) {
    if (dest == -1)
        return;

    printPath(parent[dest]);
    printf("%d ", dest);
}

// Dijkstra function
void dijkstra(int source, int n) {
    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = findMin(n);
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] != 0) {
                if (dist[v] > dist[u] + adj[u][v]) {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;  // store path
                }
            }
        }
    }
}

int main() {
    int n = 5, source = 0, dest = 4;

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

    printf("Shortest Distance from %d to %d = %d\n", source, dest, dist[dest]);

    printf("Path: ");
    printPath(dest);

    return 0;
}