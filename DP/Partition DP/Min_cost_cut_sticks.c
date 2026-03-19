#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
PROBLEM STATEMENT:
Minimum Cost to Cut a Stick

Given a stick of length n and an array cuts[],
find minimum cost to perform all cuts.

Cost of each cut = length of current stick.

--------------------------------------------------

APPROACH (INTUITION):

- Sort cuts and add boundaries:
    0 and n

- Now problem becomes:
    solve(i, j) → min cost to cut between cuts[i] and cuts[j]

- Try all possible cuts k between i and j:
    cost = (cuts[j] - cuts[i])
           + solve(i, k)
           + solve(k, j)

- Take minimum

- Base case:
    if no cut between i and j → return 0
*/

int dp[100][100];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int Min_stick(int i, int j, int cuts[]) {
    if (j - i <= 1) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 1000000;

    for (int k = i + 1; k < j; k++) {
        int cost = (cuts[j] - cuts[i])
                   + Min_stick(i, k, cuts)
                   + Min_stick(k, j, cuts);

        if (cost < ans) ans = cost;
    }

    return dp[i][j] = ans;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, c;
    scanf("%d", &n);   // stick length
    scanf("%d", &c);   // number of cuts

    int cuts[100];

    for (int i = 1; i <= c; i++)
        scanf("%d", &cuts[i]);

    cuts[0] = 0;
    cuts[c + 1] = n;

    // sort cuts
    qsort(cuts, c + 2, sizeof(int), compare);

    memset(dp, -1, sizeof(dp));

    printf("Minimum cost: %d\n", Min_stick(0, c + 1, cuts));

    return 0;
}