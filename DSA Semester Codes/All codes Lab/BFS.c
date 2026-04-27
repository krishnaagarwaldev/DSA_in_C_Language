#include<stdio.h>
#include<stdlib.h> 
#define size 5

int queue[size];
int front = -1, rear = -1;

void enqueue(int value){
    if (rear == size-1){
        return;
    }
    if (front == -1){
        front = 0;
    }
    queue[++rear] = value;
}

int dequeue(){
    if (front == -1 || front>rear){
        return -1;
    }
    return queue[front++];
}

void bfs(int graph[size][size], int visited[size], int start, int n){
    int i;
    enqueue(start);
    visited[start] = 1;
    
    while (front<=rear){
        int current = dequeue();
        printf("%d ", current);
        
        for (i=0 ; i<n; i++){
            if (graph[current][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
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
    bfs(graph,visited, start, n);
    return 0;
}