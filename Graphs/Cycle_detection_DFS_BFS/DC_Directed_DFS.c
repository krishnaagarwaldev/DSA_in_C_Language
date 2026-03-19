#include <stdio.h>
#define MAX 100

/*
PROBLEM STATEMENT:
Detect if a directed graph contains a cycle using DFS.

APPROACH:
1. Use DFS traversal with two arrays:
   - visited[] → marks nodes visited in any DFS
   - recStack[] → marks nodes in current recursion stack
2. For each vertex v:
   - If v is not visited, call DFS(v)
3. In DFS(u):
   - Mark visited[u] = 1
   - Mark recStack[u] = 1
   - For all adjacent vertices v:
       - If v not visited → DFS(v)
       - If v is in recStack → cycle exists
   - After exploring all neighbors → recStack[u] = 0
4. If any DFS returns true → cycle exists

INTUITION:
- In directed graph, a **back edge to a node in the recursion stack** indicates a cycle.

TIME COMPLEXITY: O(V^2) for adjacency matrix
*/

int adj[MAX][MAX];
int visited[MAX], recStack[MAX];
int n; // number of vertices

int dfs(int u) {
    visited[u] = 1;
    recStack[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1) {
            if (!visited[v] && dfs(v))
                return 1;
            else if (recStack[v])
                return 1; // back edge → cycle
        }
    }
    recStack[u] = 0;
    return 0;
}

int isCycle() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    n = 4;

    int input[4][4] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0} // back edge creates cycle
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    if (isCycle())
        printf("Graph contains a cycle\n");
    else
        printf("Graph does not contain a cycle\n");

    return 0;
}