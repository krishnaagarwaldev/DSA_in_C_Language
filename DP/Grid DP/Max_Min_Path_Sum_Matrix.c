#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Maximum Path Sum in a Matrix

Given a matrix mat[n][m], start at top-left (0,0) and reach bottom-right (n-1,m-1).  
At each step, you can move **right** or **down**. Find the maximum sum along any path.

--------------------------------------------------

APPROACH (INTUITION):

- At cell (i,j), two choices:
    1) Move right → solve(i, j+1)
    2) Move down  → solve(i+1, j)
- Add current cell value mat[i][j] to max of these two options
- Base case:
    if i == n-1 and j == m-1 → return mat[i][j] (destination)
    if i >= n or j >= m → return 0 (out of bounds)
- Memoize results in dp[i][j] to avoid recomputation
*/

int dp[100][100];
int mat[100][100];

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int maxPath(int i, int j, int n, int m) {
    if (i >= n || j >= m) return 0;             // out of bounds
    if (i == n - 1 && j == m - 1) return mat[i][j]; // destination

    if (dp[i][j] != -1) return dp[i][j];

    int right = maxPath(i, j + 1, n, m);
    int down = maxPath(i + 1, j, n, m);

    return dp[i][j] = mat[i][j] + max(right, down);
}


int minPath(int i, int j, int n, int m) {
    if (i >= n || j >= m) return 1000000; // out of bounds
    if (i == n - 1 && j == m - 1) return mat[i][j]; // destination

    if (dp[i][j] != -1) return dp[i][j];

    int right = minPath(i, j + 1, n, m);
    int down = minPath(i + 1, j, n, m);

    return dp[i][j] = mat[i][j] + min(right, down);
}

int main() {
    // int n, m;
    // scanf("%d %d", &n, &m);

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         scanf("%d", &mat[i][j]);

    // Example matrix
    int n = 3, m = 3;
    int example[3][3] = {
        {5, 3, 2},
        {1, 4, 1},
        {1, 5, 1}
    };

    // Copy example into mat
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = example[i][j];
            
    // mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3; // {1, 2, 3}
    // mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6; // {4, 5, 6}
    // mat[2][0] = 4; mat[2][1] = 8; mat[2][2] = 9; // {4, 8, 9}

    memset(dp, -1, sizeof(dp));

    //printf("Maximum path sum: %d\n", maxPath(0, 0, n, m)); 
    printf("Minimum path sum: %d\n", minPath(0, 0, n, m));
    return 0;
}