#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Unique Paths (Without Obstacles)

Given an m x n grid, you are at top-left cell (0,0).
You can move only:
    1) Right  (i, j+1)
    2) Down   (i+1, j)

Find total number of unique ways to reach bottom-right cell (m-1, n-1).

--------------------------------------------------

APPROACH (INTUITION):

- At each cell (i, j), we can come from:
    1) Right move → (i, j+1)
    2) Down move → (i+1, j)

- State:
    dp[i][j] = number of ways from (i, j) to destination

- Recurrence:
    dp[i][j] = dp[i+1][j] + dp[i][j+1]

- Base case:
    if (i == m-1 && j == n-1) → return 1

--------------------------------------------------
*/

int dp[100][100];

int uniquePaths(int i, int j, int m, int n) {
    // base case
    if (i == m - 1 && j == n - 1)
        return 1;

    // out of bounds
    if (i >= m || j >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = uniquePaths(i, j + 1, m, n);
    int down = uniquePaths(i + 1, j, m, n);

    return dp[i][j] = right + down;
}

int main() {
    int m = 3, n = 3;

    memset(dp, -1, sizeof(dp));

    printf("Ways (No Obstacle): %d\n", uniquePaths(0, 0, m, n));

    return 0;
}