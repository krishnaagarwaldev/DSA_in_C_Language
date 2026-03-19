#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Unique Paths II (With Obstacles)

Given an m x n grid where:
    0 → empty cell
    1 → obstacle

You start at (0,0) and want to reach (m-1,n-1).
You can move only right or down.

Return number of unique paths avoiding obstacles.

--------------------------------------------------

APPROACH (INTUITION):

- Same as previous problem, but:
    If cell has obstacle → no path through it

- State:
    dp[i][j] = number of ways from (i, j) to destination

- Recurrence:
    if obstacle → return 0
    else → dp[i][j] = dp[i+1][j] + dp[i][j+1]

- Base case:
    if (i == m-1 && j == n-1) → return 1 (if not obstacle)

--------------------------------------------------
*/

int dp2[100][100];

int uniquePathsWithObstacles(int grid[][100], int i, int j, int m, int n) {
    // out of bounds
    if (i >= m || j >= n)
        return 0;

    // obstacle
    if (grid[i][j] == 1) // if current cell has obstacle, no path through it
        return 0;

    // destination
    if (i == m - 1 && j == n - 1)
        return 1;

    if (dp2[i][j] != -1)
        return dp2[i][j];

    int right = uniquePathsWithObstacles(grid, i, j + 1, m, n);
    int down = uniquePathsWithObstacles(grid, i + 1, j, m, n);

    return dp2[i][j] = right + down;
}

int main() {
    int grid[100][100] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int m = 3, n = 3;

    memset(dp2, -1, sizeof(dp2));

    printf("Ways (With Obstacle): %d\n", uniquePathsWithObstacles(grid, 0, 0, m, n));

    return 0;
}