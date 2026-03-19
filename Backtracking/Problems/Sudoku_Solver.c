#include <stdio.h>

#define N 9

/*
---------------------------------------------------------
PROBLEM STATEMENT:
Solve a 9x9 Sudoku puzzle using backtracking.
Empty cells are represented by 0.

---------------------------------------------------------
IDEA:
We try placing numbers from 1 to 9 in empty cells.
If placing a number is valid, we move forward.
If not, we try next number.
If no number works → backtrack.

---------------------------------------------------------
LOGIC:
1. Find an empty cell (value 0)
2. Try numbers from 1 to 9
3. Check if placing number is valid:
   - Row check
   - Column check
   - 3x3 grid check
4. If valid → place number and recur
5. If recursion fails → reset cell (backtrack)

---------------------------------------------------------
RECURSION FLOW:
At each empty cell:
Try 1 → valid? → go next cell
Try 2 → valid? → go next cell
...
If stuck → go back and try next number

---------------------------------------------------------
BACKTRACKING STEP:
If a number doesn't lead to solution:
→ Reset cell to 0 (undo choice)

---------------------------------------------------------
TIME COMPLEXITY:
O(9^(n*n)) worst case (very high but optimized by constraints)

SPACE COMPLEXITY:
O(n*n) recursion stack

---------------------------------------------------------
*/

// Function to print Sudoku
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Check if it's safe to place number
int isSafe(int grid[N][N], int row, int col, int num) {

    // Row check
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num) // number already present in same row
            return 0;

    // Column check
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num) // number already present in same column
            return 0;

    // 3x3 subgrid check
    int startRow = row - row % 3; // eg. row=5 → startRow=3, row=8 → startRow=6
    int startCol = col - col % 3; // eg. col=7 → startCol=6, col=2 → startCol=0

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num) // number already present in 3x3 subgrid
                return 0;

    return 1; // safe to place
}

// Main Sudoku Solver function
int solveSudoku(int grid[N][N]) {

    int row, col;
    int found = 0;

    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    // If no empty cell → solution found
    if (!found)
        return 1;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; //Place number
            if (solveSudoku(grid)) // If recursion returns true, solution found
                return 1;

            grid[row][col] = 0; //Backtrack : reset cell to empty
        }
    }
    return 0; // trigger backtracking
}

int main() {

    int grid[N][N] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    if (solveSudoku(grid)) {
        printf("Solved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("No solution exists\n");
    }

    return 0;
}