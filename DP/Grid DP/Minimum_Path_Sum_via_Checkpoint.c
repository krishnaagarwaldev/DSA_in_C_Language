#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Minimum Path Sum Passing Through a Checkpoint

Given a matrix, find minimum path sum from (0,0) to (n-1,m-1)
such that the path MUST pass through (x,y).

Moves allowed:
    → Right
    → Down

--------------------------------------------------

APPROACH (INTUITION):

- Break into two parts:
    1) (0,0) → (x,y)
    2) (x,y) → (n-1,m-1)

- Compute both using same function

- Final answer:
    path1 + path2 - grid[x][y]

- Subtract because checkpoint counted twice
*/

int grid[100][100];
int dp[100][100];
int n, m;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minPath(int i, int j, int ei, int ej) {
    if (i > ei || j > ej) return 1000000;

    if (i == ei && j == ej)
        return grid[i][j];

    if (dp[i][j] != -1) return dp[i][j];

    int right = minPath(i, j + 1, ei, ej);
    int down  = minPath(i + 1, j, ei, ej);

    return dp[i][j] = grid[i][j] + min(right, down);
}

int main() {
    // int x, y; // checkpoint

    // scanf("%d %d", &n, &m);

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         scanf("%d", &grid[i][j]);

    // scanf("%d %d", &x, &y); // checkpoint

    n = 3, m = 3;
    grid[0][0] = 1; grid[0][1] = 2; grid[0][2] = 3; // {1, 2, 3}
    grid[1][0] = 4; grid[1][1] = 5; grid[1][2] = 6; // {4, 5, 6}
    grid[2][0] = 4; grid[2][1] = 5; grid[2][2] = 6; // {4, 5, 6}

    int x = 1, y = 1;

    memset(dp, -1, sizeof(dp));
    int part1 = minPath(0, 0, x, y);

    memset(dp, -1, sizeof(dp));
    int part2 = minPath(x, y, n - 1, m - 1);

    int ans = part1 + part2 - grid[x][y];

    printf("Minimum path passing checkpoint: %d\n", ans);

    return 0;
}