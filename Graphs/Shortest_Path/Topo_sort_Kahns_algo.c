#include <stdio.h>
#define MAX 100

/*
PROBLEM STATEMENT:
Given a Directed Acyclic Graph (DAG), perform Topological Sorting
using Kahn’s Algorithm (BFS approach).

APPROACH:
1. Compute indegree of all vertices.
2. Insert all vertices with indegree = 0 into a queue.
3. While queue is not empty:
   - Remove vertex from queue.
   - Print it.
   - For all its adjacent vertices:
       - Reduce their indegree by 1.
       - If indegree becomes 0 → add to queue.
4. If all vertices are processed → valid topo sort.

INTUITION:
- Nodes with no incoming edges come first.
- Remove them and reduce dependency of others.
- Repeat → level-wise processing (like BFS).
*/

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1) return -1;
    int val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return val;
}

void kahnTopo(int n) {
    // Step 1: Calculate indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i] == 1)
                indegree[i]++;
        }
    }
    // Step 2: Add nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }
    printf("Topological Order (Kahn's): ");

    int count = 0; // To count visited vertices

    // Step 3: Process queue
    while (front != -1) { 
        int node = dequeue();
        count++;
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--; 
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }
    if (count < n) {
        printf("\nGraph has a cycle, topological sort not possible.\n");
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
    // adj[2][0] = 1; // Detect cycle, 2 → 0

    kahnTopo(n);

    return 0;
}