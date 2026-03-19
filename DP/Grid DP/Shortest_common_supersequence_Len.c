#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Shortest Common Supersequence (Length)

Find the length of shortest string that contains both s1 and s2.

--------------------------------------------------

APPROACH:

- First find LCS
- Then:
    SCS = n + m - LCS

--------------------------------------------------
*/

int dp[1000][1000];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(int i, int j, char s1[], char s2[], int n, int m) {
    if (i == n || j == m) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(i + 1, j + 1, s1, s2, n, m);

    return dp[i][j] = max(
        lcs(i + 1, j, s1, s2, n, m),
        lcs(i, j + 1, s1, s2, n, m)
    );
}

int main() {
    char s1[1000], s2[1000];
    scanf("%s %s", s1, s2);

    int n = strlen(s1);
    int m = strlen(s2);

    memset(dp, -1, sizeof(dp));

    int lcsLen = lcs(0, 0, s1, s2, n, m);

    int scsLen = n + m - lcsLen;

    printf("SCS Length: %d\n", scsLen);

    return 0;
}