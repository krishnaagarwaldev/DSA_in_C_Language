#include <stdio.h>
#define MAX 100
#define INF 99999

/*
PROBLEM STATEMENT:
Given a weighted directed graph (weights can be positive or negative, 
but no negative cycles), find the shortest distance between all pairs 
of vertices using Floyd-Warshall Algorithm.

APPROACH:
1. Initialize dist[i][j] = adj[i][j] (or INF if no edge)
2. Set dist[i][i] = 0 for all vertices i
3. For each intermediate vertex k:
   - For all pairs (i, j):
       if dist[i][k] + dist[k][j] < dist[i][j]:
           dist[i][j] = dist[i][k] + dist[k][j]
4. After completion, dist[i][j] has shortest distance from i to j

INTUITION:
- Consider each vertex as an intermediate point to improve paths
- Repeatedly update distances using intermediate vertices

TIME COMPLEXITY: O(V^3)
*/

int adj[MAX][MAX];
int dist[MAX][MAX];
int n;

int main() {
    n = 4;

    int input[4][4] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    // Initialize distance matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = input[i][j];

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Detect negative cycles (optional)
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    // Print shortest distances
    printf("All-pairs shortest distances:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}