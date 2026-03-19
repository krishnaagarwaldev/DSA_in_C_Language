#include <stdio.h>
#define size 10

void dfs(int graph[size][size], int visited[size], int start, int n) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        // If there's an edge and vertex not visited
        if (graph[start][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, i, n);
        }
    }
}
int main(){
    int n, edges, start;
    int graph[size][size];
    for (int i=0; i<size ; i++){
        for (int j=0; j<size; j++){
            graph[i][j] = 0;
        }
    }
    scanf("%d", &n);
    scanf("%d", &edges);
    for (int i=0; i<edges; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    scanf("%d", &start);
    int visited[size] = {0};
    dfs(graph,visited, start, n);
    return 0;
}
