// Kruskal Algorithm :- O(V + E)

#include<stdio.h>
#include<stdlib.h>

#define V 5
#define E 7

int nv;
int ne;

struct Edge {
    int u, v, w;
};

int cmp(const void *a, const void *b) {
    struct Edge* A = (struct Edge*)a;
    struct Edge* B = (struct Edge*)b;
    return A->w - B->w;
    
    // return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int find(int parent[], int i) {
    if(parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void join(int parent[], int x, int y) {
    int u = find(parent, x);
    int v = find(parent, y);
    parent[u] = v;
}

void kruskal(struct Edge edges[]) {
    qsort(edges, E, sizeof(edges[0]), cmp);

    int parent[V];
    for(int i = 0; i < V; i++)
        parent[i] = i;

    printf("Edge \tWeight\n");

    int c = 0;
    for(int i = 0; i < E && c < V-1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(parent, u);
        int set_v = find(parent, v);

        if(set_u != set_v) {
            printf("%d - %d -> %d\n", u, v, edges[i].w);
            join(parent, set_u, set_v);
            c++;
        }
    }
}

int main() {
    struct Edge edges[E];

    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    kruskal(edges);
    
    return 0;
}
