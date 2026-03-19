#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Shortest Common Supersequence (Length)

Given two strings s1 and s2, find the length of the shortest string
which contains both as subsequences.

--------------------------------------------------

APPROACH (INTUITION):

- If characters match:
    → take once → 1 + solve(i-1, j-1)

- If not match:
    → take either from s1 OR s2:
        1 + min(
            solve(i-1, j),   // take from s1
            solve(i, j-1)    // take from s2
        )

- Base cases:
    if i < 0 → return j+1
    if j < 0 → return i+1

- Same as LCS but using MIN instead of MAX
*/

int dp[100][100];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int scs(int i, int j, char s1[], char s2[]) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + scs(i - 1, j - 1, s1, s2);
    }

    int take1 = 1 + scs(i - 1, j, s1, s2);
    int take2 = 1 + scs(i, j - 1, s1, s2);

    return dp[i][j] = min(take1, take2);
}

int main() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);

    int n = strlen(s1), m = strlen(s2);

    memset(dp, -1, sizeof(dp));

    printf("Length of SCS: %d\n", scs(n - 1, m - 1, s1, s2));

    return 0;
}