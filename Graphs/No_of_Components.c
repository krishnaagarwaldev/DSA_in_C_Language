// // Time complexity = O(n*m)

#include<stdio.h>

int graph[100][100];
int visited[100];
int n, m;

void dfs(int v){
    visited[v] = 1;
    printf("%d ", v);
    
    for (int i=0; i<n; i++){
        if (graph[v][i] && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    
    scanf("%d %d", &n, &m); //n = no. of vertices, m = no. of edges
    int u,v;
    for (int i=0; i<n; i++){
        visited[i] = 0;
        for (int j=0; j<n; j++){
            graph[i][j] =0;
        }
    }
    
    for (int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int components = 0;
    for (int i=0; i<n ; i++){
        if (!visited[i]){
            dfs(i);
            printf("\n");
            components++;
        }
    }
    printf("%d", components);
    return 0;
}
