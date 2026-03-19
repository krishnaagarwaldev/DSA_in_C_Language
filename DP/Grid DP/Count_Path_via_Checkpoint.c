#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Count number of paths from (0,0) to (n-1,m-1) such that the path
must pass through two checkpoints (x1,y1) and (x2,y2).

Moves allowed:
    → Right
    → Down

--------------------------------------------------

APPROACH (INTUITION):

- Break into 3 parts:
    1) Start → checkpoint1
    2) checkpoint1 → checkpoint2
    3) checkpoint2 → End

- Total paths = a × b × c

- Use recursion + memoization to count paths

- Base case:
    if reached destination → return 1
    if out of bounds → return 0
*/

int dp[100][100];
int grid[100][100];
int n, m;

int countPaths(int i, int j, int ei, int ej) {
    if (i > ei || j > ej) return 0;

    if (i == ei && j == ej) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    int right = countPaths(i, j + 1, ei, ej);
    int down  = countPaths(i + 1, j, ei, ej);

    return dp[i][j] = right + down;
}

int main() {
    int x1, y1, x2, y2;

    // scanf("%d %d", &n, &m);

    // // input grid
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         scanf("%d", &grid[i][j]);

    // // checkpoints
    // scanf("%d %d", &x1, &y1);
    // scanf("%d %d", &x2, &y2);

    n = 3, m = 3;
    grid[0][0] = 1; grid[0][1] = 1; grid[0][2] = 1; // {1, 1, 1}
    grid[1][0] = 1; grid[1][1] = 1; grid[1][2] = 1; // {1, 1, 1}
    grid[2][0] = 1; grid[2][1] = 1; grid[2][2] = 1; // {1, 1, 1}
    grid[0][0] = 1; grid[0][1] = 1; grid[0][2] = 1; // {1, 1, 1}

    x1 = 0, y1 = 1;
    x2 = 1, y2 = 1;

    // check if checkpoints are valid
    if (grid[0][0] == 0 || grid[x1][y1] == 0 || grid[x2][y2] == 0 || grid[n-1][m-1] == 0) {
        printf("Total paths: 0\n");
        return 0;
    }

    // order check (must be top-left to bottom-right)
    if (x1 > x2 || y1 > y2) {
        printf("Total paths: 0\n");
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    int a = countPaths(0, 0, x1, y1);

    memset(dp, -1, sizeof(dp));
    int b = countPaths(x1, y1, x2, y2);

    memset(dp, -1, sizeof(dp));
    int c = countPaths(x2, y2, n - 1, m - 1);

    int total = a * b * c;

    printf("Total paths: %d\n", total);

    return 0;
}