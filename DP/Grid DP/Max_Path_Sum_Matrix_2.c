#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Maximum Path Sum in a Matrix (Down + Diagonal Moves)

Given a matrix mat[n][m], start at top row and move to bottom row.  
From cell (i,j), you can move:
1) Down → (i+1, j)
2) Diagonally right → (i+1, j+1)
3) Diagonally left → (i+1, j-1)

Find the maximum sum path from **any cell in top row** to **any cell in bottom row**.

--------------------------------------------------

APPROACH (INTUITION):

- Let maxPath(i,j) = maximum path sum starting from cell (i,j)
- Choices:
    1) Down → maxPath(i+1, j)
    2) Diagonal right → maxPath(i+1, j+1)
    3) Diagonal left → maxPath(i+1, j-1)
- Base case:
    if i == n-1 → return mat[i][j] (last row)
    if j < 0 or j >= m → return 0 (out of bounds)
- Memoize results in dp[i][j]
- Maximum path = max over all starting positions in top row
*/

int dp[100][100];
int mat[100][100];
int n, m;

int max(int a, int b) { return (a > b) ? a : b; }

int maxPath(int i, int j) {
    if (j < 0 || j >= m) return 0;       // out of bounds
    if (i == n - 1) return mat[i][j];    // last row

    if (dp[i][j] != -1) return dp[i][j];

    int down = maxPath(i + 1, j);
    int diagRight = maxPath(i + 1, j + 1);
    int diagLeft = maxPath(i + 1, j - 1);

    return dp[i][j] = mat[i][j] + max(down, max(diagRight, diagLeft));
}

int main() {
    // scanf("%d %d", &n, &m);

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         scanf("%d", &mat[i][j]);

    // Example matrix
    n = 4, m = 4;
    int example[4][4] = {
        {10, 10, 2, 0},
        {1, 0, 0, 30},
        {0, 10, 4, 0},
        {1, 0, 2, 20}
    };

    // Copy example into mat
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = example[i][j];

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int j = 0; j < m; j++) {
        int temp = maxPath(0, j);   // start from each cell in top row
        if (temp > ans) ans = temp;
    }

    printf("Maximum path sum: %d\n", ans); // 56 (2 -> 30 -> 4 -> 20)

    return 0;
}