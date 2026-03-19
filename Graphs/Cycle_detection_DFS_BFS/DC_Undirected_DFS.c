#include <stdio.h>
#include <string.h>
#define MAX 100

/*
PROBLEM STATEMENT:
Given an undirected graph (adjacency matrix), detect if there is a cycle
using DFS.

APPROACH:
1. Use DFS traversal.
2. Maintain a visited[] array.
3. For each vertex v:
   - If not visited, call DFS(v, -1)
4. In DFS(u, parent):
   - Mark u as visited
   - For all adjacent vertices v:
       - If v is not visited → DFS(v, u)
       - If v is visited and v != parent → cycle exists
5. If any DFS call returns true → graph contains a cycle.

INTUITION:
- In undirected graph, back edge to a visited node other than parent indicates a cycle.
- Parent check avoids counting the immediate edge back as a cycle.

TIME COMPLEXITY: O(V^2) for adjacency matrix
*/

int adj[MAX][MAX];
int visited[MAX];
int n; // number of vertices

int dfs(int u, int parent) {
    visited[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1) {  // edge exists
            if (!visited[v]) {
                if (dfs(v, u))
                    return 1;  // cycle found
            }
            else if (v != parent) {
                return 1; // visited and not parent → cycle
            }
        }
    }

    return 0;
}

int isCycle() {
    // for (int i = 0; i < n; i++)
    //     visited[i] = 0;
    memset(visited, 0, sizeof(visited)); // initialize visited array

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, -1)) {
            return 1; // cycle found
        }
    }
    return 0;
}

int main() {
    n = 4;

    int input[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };

    // copy matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    if (isCycle())
        printf("Graph contains a cycle\n");
    else
        printf("Graph does not contain a cycle\n");

    return 0;
}