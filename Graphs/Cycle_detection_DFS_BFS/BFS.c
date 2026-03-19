#include <stdio.h>
#define MAX 100

/*
PROBLEM STATEMENT:
Traverse a graph using Breadth-First Search (BFS) starting from a given vertex.

APPROACH:
1. Maintain visited[] array and a queue.
2. Enqueue source vertex and mark visited.
3. While queue not empty:
   - Dequeue vertex u
   - Print u
   - For all adjacent vertices v:
       - If not visited → mark visited, enqueue v

TIME COMPLEXITY: O(V^2) for adjacency matrix
*/

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;
int n;

// Enqueue
void enqueue(int x) {
    queue[rear++] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

void bfs(int start) {
    visited[start] = 1;
    enqueue(start);

    while (front < rear) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
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

    printf("BFS Traversal: ");
    for (int i = 0; i < n; i++)
        if (!visited[i])
            bfs(i);

    return 0;
}