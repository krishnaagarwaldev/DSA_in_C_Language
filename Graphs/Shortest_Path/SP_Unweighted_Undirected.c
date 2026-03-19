#include <stdio.h>
#include <string.h>

#define MAX 100

/*
PROBLEM STATEMENT:
Find the shortest path in an unweighted undirected graph
using BFS (Breadth First Search).

Given an adjacency matrix and a source vertex,
compute the shortest distance from source to all vertices.

APPROACH:
1. Use BFS traversal (level order).
2. Maintain:
   - visited[] array
   - dist[] array (initialize with -1)
   - queue for BFS
3. Steps:
   a. Mark source visited and dist[source] = 0
   b. Enqueue source
   c. While queue not empty:
       - Dequeue node u
       - Traverse all adjacent vertices v
       - If v not visited:
            visited[v] = 1
            dist[v] = dist[u] + 1
            enqueue(v)
4. dist[] gives shortest path in unweighted graph.

TIME COMPLEXITY: O(V^2) (Adjacency Matrix)
*/

int adj[MAX][MAX];
int visited[MAX];
int dist[MAX];

// Queue variables
int queue[MAX];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

// Dequeue function
int dequeue() {
    if (front == -1) return -1;

    int val = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return val;
}

// BFS function
void bfs(int source, int n) {
    // initialize arrays
    // for (int i = 0; i < n; i++) {
    //     visited[i] = 0;
    //     dist[i] = -1;
    // }
    memset(visited, 0, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    // start BFS
    enqueue(source);
    visited[source] = 1;
    dist[source] = 0;

    while (front != -1) {
        int u = dequeue();

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                enqueue(v);
            }
        }
    }
}

int main() {
    // int n, source; 
    // printf("Enter number of vertices: "); 
    // scanf("%d", &n); 

    // printf("Enter adjacency matrix:\n"); 
    // for (int i = 0; i < n; i++) 
    //     for (int j = 0; j < n; j++) 
    //         scanf("%d", &adj[i][j]); 
            
    // printf("Enter source vertex: "); 
    // scanf("%d", &source);

    int n = 4, source = 0;

    int input[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    // copy input to adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = input[i][j];

    bfs(source, n);

    // print result
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}