#include <stdio.h>

int board[100][100];  // chessboard
int found = 0;  // flag to check if at least one solution exists

/*
---------------------------------------------------------
PROBLEM STATEMENT:
Place N queens on an N×N chessboard such that no two
queens attack each other.

---------------------------------------------------------
IDEA:
We place queens row by row using backtracking.

For each row:
Try placing a queen in every column.
If it's safe → place and move to next row.
If not safe → try next column.

---------------------------------------------------------
LOGIC:
1. Start from row = 0
2. For each column:
   - Check if safe
   - If safe → place queen
   - Recur for next row
   - Backtrack (remove queen)

---------------------------------------------------------
RECURSION FLOW:
Row 0 → try all columns
Row 1 → try all columns (based on previous placements)
...
Continue until row == N → solution found

---------------------------------------------------------
BACKTRACKING STEP:
After recursion, remove the queen (important!)

---------------------------------------------------------
TIME COMPLEXITY:
O(N!) (approx)

SPACE COMPLEXITY:
O(N^2) board + recursion stack

---------------------------------------------------------
*/

// Function to check if it's safe to place queen
int isSafe(int n, int row, int col) {

    // Check same column (above rows)
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) // queen already placed in same column
            return 0;
    }
    // Not need to check same row as we are placing one queen per row

    // Check left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) // queen already placed in left diagonal
            return 0;
    }
    // Check right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) // queen already placed in right diagonal
            return 0;
    }
    return 1; // safe
}

// Backtracking function
void solveNQueens(int n, int row) {

    // Base case: all queens placed
    if (row == n) {
        found = 1; // mark that we found at least one solution

        // print solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    // Try placing queen in each column
    for (int col = 0; col < n; col++) {
        // Check if safe
        if (isSafe(n, row, col)) {
            board[row][col] = 1; // Place queen
            solveNQueens(n, row + 1); // Recur for next row

            board[row][col] = 0; // Backtrack (remove queen)
        }
    }
}

int main() {
    int n = 4;
    solveNQueens(n, 0);

    if (!found)
        printf("No solution exists.\n");

    return 0;
}