#include <stdio.h>
#define MAX 100

/*
PROBLEM STATEMENT:
Traverse a graph using Depth-First Search (DFS) starting from a given vertex.

APPROACH:
1. Maintain visited[] array.
2. For DFS(u):
   - Mark u visited
   - Print u
   - For all adjacent vertices v:
       - If v not visited → DFS(v)
3. Repeat for disconnected components if needed.

TIME COMPLEXITY: O(V^2) for adjacency matrix
*/

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v])
            dfs(v);
    }
}

int main() {
    n = 4;
    int input[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    return 0;
}