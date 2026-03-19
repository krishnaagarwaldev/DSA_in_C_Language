#include <stdio.h>
#define MAX 100

/*
PROBLEM STATEMENT:
Detect if a directed graph contains a cycle using BFS (Kahn's Algorithm).

APPROACH:
1. Compute in-degree of all vertices.
2. Enqueue all vertices with in-degree 0.
3. While queue is not empty:
   - Dequeue vertex u
   - For each adjacent vertex v:
       - Decrease in-degree[v] by 1
       - If in-degree[v] becomes 0 → enqueue v
4. Keep count of visited vertices.
5. If count < total vertices → graph has a cycle, in topological sort of a DAG, all vertices are visited, if not, it means there is a cycle that prevents some vertices from being visited, as there in-degree never becomes 0.

INTUITION:
- A cycle prevents at least one vertex from having in-degree 0
- If we cannot process all vertices → cycle exists

We apply Kahn's algorithm to detect cycles in a directed graph, which is based on the concept of topological sorting. If we can perform a topological sort of the graph, it means there are no cycles. If we cannot, it means there is at least one cycle in the graph.

TIME COMPLEXITY: O(V^2) for adjacency matrix
*/

int adj[MAX][MAX];
int n; // number of vertices
int queue[MAX];
int front, rear;
int indegree[MAX];

void enqueue(int x) { queue[rear++] = x; }
int dequeue() { return queue[front++]; }

int isCycle() {
    // Compute in-degree
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            if (adj[u][v])
                indegree[v]++;

    front = rear = 0;
    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            enqueue(i);

    int count = 0;

    while (front < rear) {
        int u = dequeue();
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(v);
            }
        }
    }

    // If count < n → cycle exists
    return (count < n);
}

int main() {
    n = 4;

    int input[4][4] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0} // cycle
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