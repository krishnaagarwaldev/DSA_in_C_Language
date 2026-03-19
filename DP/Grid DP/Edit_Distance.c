#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Edit Distance (LeetCode 72)

Given two strings word1 and word2, find the minimum number of operations
required to convert word1 into word2.

Allowed operations:
1) Insert
2) Delete
3) Replace

--------------------------------------------------

APPROACH (INTUITION):

At (i, j):

- If characters match:
    → no operation needed → move both
    → solve(i+1, j+1)

- If not match:
    → try all 3 operations:

    1) Insert → solve(i, j+1)
    2) Delete → solve(i+1, j)
    3) Replace → solve(i+1, j+1)

    → take minimum + 1

- Base cases:
    if i == n → insert remaining (m - j)
    if j == m → delete remaining (n - i)

--------------------------------------------------
*/

int dp[1000][1000];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int editDistance(int i, int j, char s1[], char s2[], int n, int m) {
    // base cases
    if (i == n) return m - j;
    if (j == m) return n - i;

    if (dp[i][j] != -1) return dp[i][j];

    // characters match
    if (s1[i] == s2[j]) {
        return dp[i][j] = editDistance(i + 1, j + 1, s1, s2, n, m);
    }

    // operations
    int insert = editDistance(i, j + 1, s1, s2, n, m);
    int del    = editDistance(i + 1, j, s1, s2, n, m);
    int replace= editDistance(i + 1, j + 1, s1, s2, n, m);

    return dp[i][j] = 1 + min(insert, min(del, replace));
}

int main() {
    char s1[1000], s2[1000];
    scanf("%s %s", s1, s2);

    int n = strlen(s1);
    int m = strlen(s2);

    memset(dp, -1, sizeof(dp));

    printf("Edit Distance: %d\n", editDistance(0, 0, s1, s2, n, m));

    return 0;
}