#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Count Square Submatrices with All Ones

Given a binary matrix (0/1), count all square submatrices that have all 1s.

--------------------------------------------------

APPROACH (INTUITION):

- Let dp[i][j] = size of largest square ending at (i,j)
- If grid[i][j] == 1:
    dp[i][j] = 1 + min(
        top      → solve(i-1, j)
        left     → solve(i, j-1)
        diagonal → solve(i-1, j-1)
    )
- If grid[i][j] == 0 → dp[i][j] = 0

- Each dp[i][j] contributes that many squares

- Base case:
    if i < 0 or j < 0 → return 0

- Final answer = sum of all dp[i][j]
*/

int grid[100][100];
int dp[100][100];
int n, m;

int min(int a, int b) { return (a < b) ? a : b; }

int countSquares(int i, int j) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (grid[i][j] == 0)
        return dp[i][j] = 0;

    int top = countSquares(i - 1, j);
    int left = countSquares(i, j - 1);
    int diag = countSquares(i - 1, j - 1);

    return dp[i][j] = 1 + min(top, min(left, diag));
}

int main() {
    // scanf("%d %d", &n, &m);

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         scanf("%d", &grid[i][j]);

    n = 3, m = 3;
    grid[0][0] = 1; grid[0][1] = 1; grid[0][2] = 1; // {1, 1, 1}
    grid[1][0] = 1; grid[1][1] = 1; grid[1][2] = 1; // {1, 1, 1}
    grid[2][0] = 1; grid[2][1] = 1; grid[2][2] = 1; // {1, 1, 1}

    memset(dp, -1, sizeof(dp));

    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            total += countSquares(i, j);
        }
    }

    printf("Total square submatrices: %d\n", total);

    return 0;
}