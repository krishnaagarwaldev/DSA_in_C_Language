#include <stdio.h>

#define V 4   // number of vertices

/*
---------------------------------------------------------
PROBLEM STATEMENT:
Given a graph and m colors, assign colors to all vertices
such that no two adjacent vertices have the same color.

---------------------------------------------------------
IDEA:
Use backtracking:
Try assigning colors (1 to m) to each vertex.
If assignment is safe → move to next vertex.
If not → try next color.
If no color works → backtrack.

---------------------------------------------------------
LOGIC:
1. Start with vertex 0
2. Try colors from 1 to m
3. Check if color is safe:
   - Adjacent vertices should not have same color
4. If safe → assign color and recur for next vertex
5. If all vertices are colored → solution found
6. If no color works → backtrack

---------------------------------------------------------
RECURSION FLOW:
For each vertex:
Try color 1 → valid? → go next
Try color 2 → valid? → go next
...
If no color works → backtrack

---------------------------------------------------------
BACKTRACKING STEP:
If coloring fails:
→ Reset color to 0

---------------------------------------------------------
TIME COMPLEXITY:
O(m^V)

SPACE COMPLEXITY:
O(V)

---------------------------------------------------------
*/

// Check if it's safe to assign color
int isSafe(int graph[V][V], int color[], int v, int c) {

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

// Backtracking function
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) // Base case: all vertices colored
        return 1;

    // Try all colors
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c; //Assign color

            if (graphColoringUtil(graph, m, color, v + 1)) //Recursion returns true → solution found
                return 1;
            color[v] = 0; // Backtrack: reset color and try next color
        }
    }
    return 0;
}

// Main function
int graphColoring(int graph[V][V], int m) {

    int color[V] = {0};  // no vertex colored initially

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return 0;
    }
    printf("Vertex Colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
    return 1;
}

int main() {

    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;  // number of colors

    graphColoring(graph, m);

    return 0;
}