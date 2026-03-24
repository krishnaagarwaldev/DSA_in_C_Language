#include <stdio.h>
#include <limits.h>
// int n;

int mindist(int dist[], int visited[], int n){
    int min = INT_MAX, min_index = -1;
    
    for (int i = 0; i < n; i++){
        if (visited[i] == 0 && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// void prims(int adj[n][n], int n);{ // n is used before being passed → not valid in C (for parameters like this)
void prims(int n, int adj[n][n]){
    int parent[n];
    int dist[n];
    int visited[n];
    
    for (int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    
    dist[0] = 0;
    parent[0] = -1;
    
    for (int c = 0; c < n - 1; c++){
        int v = mindist(dist, visited, n);
        
        if (v == -1) break;  // safety
        
        visited[v] = 1;
        
        for (int u = 0; u < n; u++){
            if (adj[v][u] && visited[u] == 0 && adj[v][u] < dist[u]){
                parent[u] = v;
                dist[u] = adj[v][u];
            }
        }
    }
    
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < n; i++){
        printf("%d - %d \t%d\n", parent[i], i, adj[i][parent[i]]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    int adj[n][n];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            adj[i][j] = 0;
        }
    }
    
    int ne;
    scanf("%d", &ne);
    
    int u, v, w;
    for (int i = 0; i < ne; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }
    
    prims(n, adj);
    
    return 0;
}