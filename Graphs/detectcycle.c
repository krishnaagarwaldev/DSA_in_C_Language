// Time complexity = O(n*m)
#include<stdio.h>

int graph[100][100];
int visited[100];
int n, m;

int dfs(int v, int parent){
    visited[v] = 1;
    for (int i=0; i<n; i++){
        if (graph[v][i]){
            if (!visited[i]){
                if (dfs(i,v)){
                    return 1;
                }
            }
            else if (i != parent){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++){
        visited[i] = 0;
        for (int j=0; j<n; j++){
            graph[i][j] = 0;
        }
    }
    int u,v;
    for (int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    int hascycle = 0;
    for (int i=0 ; i<n ; i++){
        if (!visited[i]){
          if ( dfs(i, -1)){
              hascycle = 1;
              break;
          }
        }
    }
    if (hascycle){
        printf("Yes");
    }
    else{
        printf("No");
    }
}