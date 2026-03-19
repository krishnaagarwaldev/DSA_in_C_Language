#include <stdio.h>

#define N 4

/*
---------------------------------------------------------
PROBLEM STATEMENT:
Given a NxN maze, find a path for a rat from (0,0)
to (N-1, N-1). Cells with 1 are open, 0 are blocked.

---------------------------------------------------------
IDEA:
Use backtracking:
At each cell, try moving in allowed directions.
If path leads to solution → print it.
If blocked or visited → backtrack.

---------------------------------------------------------
LOGIC:
1. Start from (0,0)
2. Check if current cell is safe:
   - Inside bounds
   - Value is 1
   - Not visited
3. Mark current cell as part of path
4. Try moving:
   - Down
   - Right
   (can also include Up, Left if required)
5. If destination reached → print solution
6. If no move works → backtrack

---------------------------------------------------------
RECURSION FLOW:
From each cell:
Try Down → valid? → go deeper
Try Right → valid? → go deeper
If both fail → go back

---------------------------------------------------------
BACKTRACKING STEP:
If path doesn't work:
→ Unmark cell (set to 0 in solution matrix)

---------------------------------------------------------
TIME COMPLEXITY:
O(2^(N*N)) worst case

SPACE COMPLEXITY:
O(N*N)

---------------------------------------------------------
*/

// Function to print solution path
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

// Check if cell is safe
int isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Backtracking function
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    
    if (x == N - 1 && y == N - 1) { //Base case: destination reached
        sol[x][y] = 1;
        return 1;
    }
    if (isSafe(maze, x, y)) {
        sol[x][y] = 1; // Mark current cell as part of solution path

        if (solveMazeUtil(maze, x + 1, y, sol)) // Move down
            return 1;
        if (solveMazeUtil(maze, x, y + 1, sol)) // Move right
            return 1;

        sol[x][y] = 0; // Backtrack - unmark cell
        return 0;
    }
    return 0;
}

// Main function
int solveMaze(int maze[N][N]) {
    
    int sol[N][N];
    for (int i = 0; i < N; i++)     //Initialize solution matrix with 0s
        for (int j = 0; j < N; j++)
            sol[i][j] = 0;

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        printf("No solution exists\n");
        return 0;
    }
    printSolution(sol);
    return 1;
}

int main() {

    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);

    return 0;
}