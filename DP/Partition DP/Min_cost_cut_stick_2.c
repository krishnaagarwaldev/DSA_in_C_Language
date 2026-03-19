#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
PROBLEM STATEMENT:
Minimum Cost to Cut a Stick

--------------------------------------------------

APPROACH (MCM STYLE):

- Sort cuts and add 0 and n
- Now think like partition DP:

    solve(i, j) → cost to cut from cuts[i] to cuts[j]

- Try every cut k between i and j:

    cost = (cuts[j+1] - cuts[i-1])
           + solve(i, k-1)
           + solve(k+1, j)

- Base case:
    if i > j → no cuts → cost = 0
*/

int dp[100][100];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solve(int i, int j, int cuts[]) {
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 1000000;

    for (int k = i; k <= j; k++) {
        int cost = (cuts[j + 1] - cuts[i - 1])
                   + solve(i, k - 1, cuts)
                   + solve(k + 1, j, cuts);

        if (cost < ans) ans = cost;
    }
    return dp[i][j] = ans;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, c;
    scanf("%d", &n);
    scanf("%d", &c);

    int cuts[100];

    for (int i = 1; i <= c; i++)
        scanf("%d", &cuts[i]);

    // add boundaries
    cuts[0] = 0;
    cuts[c + 1] = n;

    // sort
    qsort(cuts, c + 2, sizeof(int), compare);

    memset(dp, -1, sizeof(dp));

    printf("Minimum cost: %d\n", solve(1, c, cuts));

    return 0;
}