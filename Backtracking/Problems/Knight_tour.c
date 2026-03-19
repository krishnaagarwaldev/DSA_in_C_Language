/*
---------------------------------------------------------
PROBLEM STATEMENT:
Place a knight on an NxN chessboard such that it visits
every cell exactly once.

---------------------------------------------------------
IDEA:
Use backtracking:
Try all 8 possible knight moves from current position.
If a move is valid and not visited → move forward.
If stuck → backtrack.

---------------------------------------------------------
LOGIC:
1. Start from (0,0)
2. Mark current cell with move number
3. Try all 8 possible moves
4. Check if move is safe:
   - Inside board
   - Not already visited
5. If valid → recur for next move
6. If all moves fail → backtrack

---------------------------------------------------------
RECURSION FLOW:
At each cell:
Try move1 → valid? → go deeper
Try move2 → valid? → go deeper
...
If no move works → go back

---------------------------------------------------------
BACKTRACKING STEP:
If no solution from current path:
→ Unmark the cell (set to -1)

---------------------------------------------------------
TIME COMPLEXITY:
O(8^(N*N)) worst case (very high)

SPACE COMPLEXITY:
O(N*N) recursion stack

---------------------------------------------------------
*/

#include <stdio.h>

#define N 6   // Change board size here

// 8 possible moves of knight
int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Function to check if move is valid
int isSafe(int x, int y, int board[N][N]) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

// Recursive function for Knight Tour
int solveKnightTour(int x, int y, int stepCount, int board[N][N]) {
    
    // Base case: all cells visited
    if (stepCount == N * N)
        return 1;

    // Try all 8 moves
    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if (isSafe(nextX, nextY, board)) {
            board[nextX][nextY] = stepCount;
            if (solveKnightTour(nextX, nextY, stepCount + 1, board)) // Recursion returns true → solution found
                return 1;

            board[nextX][nextY] = -1; //Backtrack: unmark cell
        }
    }
    return 0;
}


int main() {
    int board[N][N];

    // Initialize board with -1 (unvisited)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    // Start from (0,0)
    board[0][0] = 0;

    // Call recursive function
    if (!solveKnightTour(0, 0, 1, board)) {
        printf("Solution does not exist\n");
        return 0;
    }

    // Print solution
    printf("Knight's Tour Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}