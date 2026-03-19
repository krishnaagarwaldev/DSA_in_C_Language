#include <stdio.h>
#define MAX 100

/*
PROBLEM STATEMENT:
Given a Directed Acyclic Graph (DAG) with V vertices and E edges,
perform Topological Sorting using Depth First Search (DFS).
Topological sorting gives a linear ordering of vertices such that
for every directed edge u → v, u comes before v.

APPROACH:
1. Use DFS traversal.
2. Maintain a visited array to track visited nodes.
3. Create a stack to store the result.
4. For each unvisited node:
   - Call DFS.
   - In DFS, visit all adjacent nodes first.
   - After visiting all neighbors, push current node into stack.
5. Finally, pop elements from stack → this gives topological order.

INTUITION:
- DFS goes deep first.
- Node is added AFTER visiting all dependencies.
- So stack stores nodes in reverse topological order.
*/

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }

    // push after visiting all neighbors
    push(v);
}

void topoSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    printf("Topological Order (DFS): ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    // int n;

    // printf("Enter number of vertices: ");
    // scanf("%d", &n);

    // printf("Enter adjacency matrix:\n");
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         scanf("%d", &adj[i][j]);

    int n = 4;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    adj[0][1] = 1; // 0 → 1
    adj[0][2] = 1; // 0 → 2 
    adj[1][3] = 1; // 1 → 3
    adj[2][3] = 1; // 2 → 3

    topoSort(n);

    return 0;
}