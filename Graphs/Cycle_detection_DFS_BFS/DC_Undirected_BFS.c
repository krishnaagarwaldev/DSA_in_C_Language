#include <stdio.h>
#define MAX 100

/*
PROBLEM STATEMENT:
Detect if an undirected graph contains a cycle using BFS.

APPROACH:
1. Use BFS traversal starting from every unvisited vertex.
2. Maintain a visited[] array and a parent[] array.
3. For BFS(u):
   - Enqueue u and mark visited.
   - For each adjacent vertex v of u:
       - If not visited:
           - Mark visited, set parent[v] = u, enqueue v
       - Else if v is visited and v != parent[u]:
           - Cycle detected
4. Repeat for all disconnected components.

INTUITION:
- In undirected graph, if during BFS we find an already visited node that is **not the parent** → cycle exists.
- Parent check avoids counting the immediate back edge as a cycle.

TIME COMPLEXITY: O(V^2) for adjacency matrix
*/

int adj[MAX][MAX];
int visited[MAX];
int parent[MAX];
int queue[MAX];
int front, rear;
int n; // number of vertices

void enqueue(int x) { queue[rear++] = x; }
int dequeue() { return queue[front++]; }


// eg. 
// 0 - 1
// 1 - 0 2 4
// 2 - 1 3
// 3 - 2 4
// 4 - 1 3

// v = 0, u=1 -> parent[1] = 0, therefore when we visit 0 again from 1, we ignore it as it is the parent of 1.

int bfs(int start) {
    front = rear = 0;
    enqueue(start);
    visited[start] = 1;
    parent[start] = -1;

    while (front < rear) {
        int u = dequeue();

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                if (!visited[v]) {
                    visited[v] = 1;
                    parent[v] = u;
                    enqueue(v);
                } 
                else if (v != parent[u]) { // means v is visited and not parent of u → cycle
                    return 1; // cycle detected
                }
            }
        }
    }

    return 0; // no cycle
}

int isCycle() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && bfs(i)) {
            return 1;
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

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    if (isCycle())
        printf("Graph contains a cycle\n");
    else
        printf("Graph does not contain a cycle\n");

    return 0;
}