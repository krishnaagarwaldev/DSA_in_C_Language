#include <stdio.h>

#define N 4

/*
---------------------------------------------------------
PROBLEM STATEMENT:
Given a NxN maze, print all possible paths from (0,0)
to (N-1,N-1) in the form of a string (D, R, U, L).

---------------------------------------------------------
IDEA:
Use backtracking and store path in a string.
At each step, try all 4 directions and append
corresponding character.

---------------------------------------------------------
LOGIC:
1. Start from (0,0)
2. Maintain a string path[]
3. At each step:
   - Mark cell visited
   - Try all directions (D, R, U, L)
   - Append move to path
4. If destination reached → print path
5. After recursion → remove last character (backtrack)

---------------------------------------------------------
RECURSION FLOW:
At each cell:
Try D → valid? → go deeper
Try R → valid? → go deeper
Try U → valid? → go deeper
Try L → valid? → go deeper

---------------------------------------------------------
BACKTRACKING STEP:
1. Remove last character from path
2. Mark cell as unvisited

---------------------------------------------------------
TIME COMPLEXITY:
O(4^(N*N)) worst case

SPACE COMPLEXITY:
O(N*N)

---------------------------------------------------------
*/

// Check if safe to move
int isSafe(int maze[N][N], int x, int y, int visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            maze[x][y] == 1 && visited[x][y] == 0);
}

// Backtracking function
void solveMazeUtil(int maze[N][N], int x, int y, int visited[N][N], char path[], int index) {

    if (x == N - 1 && y == N - 1) {  //Base case: destination reached
        path[index] = '\0';  // end string
        printf("%s\n", path);
        return;
    }
    visited[x][y] = 1; //Mark cell as visited

    if (isSafe(maze, x + 1, y, visited)) {  //Move down
        path[index] = 'D';
        solveMazeUtil(maze, x + 1, y, visited, path, index + 1);
    }
    if (isSafe(maze, x, y + 1, visited)) { //Move right
        path[index] = 'R';
        solveMazeUtil(maze, x, y + 1, visited, path, index + 1);
    }
    if (isSafe(maze, x - 1, y, visited)) { //Move up
        path[index] = 'U';
        solveMazeUtil(maze, x - 1, y, visited, path, index + 1);
    }
    if (isSafe(maze, x, y - 1, visited)) {  //Move left
        path[index] = 'L';
        solveMazeUtil(maze, x, y - 1, visited, path, index + 1);
    }
    visited[x][y] = 0; //Backtrack: unmark cell
}

// Main function
void solveMaze(int maze[N][N]) {
    // IMPORTANT CHECK
    if (maze[0][0] == 0) {
        printf("No path exists\n");
        return;
    }
    int visited[N][N] = {0};
    char path[N * N];  // max path length

    solveMazeUtil(maze, 0, 0, visited, path, 0);
}

int main() {

    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}