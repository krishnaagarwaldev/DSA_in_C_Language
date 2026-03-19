#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Longest Common Subsequence (LCS)

Given two strings s1 and s2, find the length of the longest subsequence
that is common in both strings.

A subsequence is a sequence derived by deleting some or no elements
without changing the order.

Example:
s1 = "abcde"
s2 = "ace"
Answer = 3 ("ace")

--------------------------------------------------

APPROACH (INTUITION):

- At indices (i, j) in s1 and s2:

    If s1[i] == s2[j]:
        → take it and move both
        → 1 + LCS(i+1, j+1)

    Else:
        → skip one character
        → max(
              LCS(i+1, j),   // skip s1[i]
              LCS(i, j+1)    // skip s2[j]
          )

- State:
    dp[i][j] = LCS length from s1[i..] and s2[j..]

- Base case:
    if i == n OR j == m → return 0

--------------------------------------------------
*/

int dp[1000][1000];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(int i, int j, char s1[], char s2[], int n, int m) {
    // base case
    if (i == n || j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    // match
    if (s1[i] == s2[j]) {
        ans = 1 + lcs(i + 1, j + 1, s1, s2, n, m);
    }

    // not match -> skip one character
    else{
        ans = max(
            lcs(i + 1, j, s1, s2, n, m),
            lcs(i, j + 1, s1, s2, n, m)
        );
    }
    return dp[i][j] = ans;
}

int main() {
    char s1[] = "abcde";
    char s2[] = "ace";

    int n = strlen(s1);
    int m = strlen(s2);

    memset(dp, -1, sizeof(dp));

    printf("LCS Length: %d\n", lcs(0, 0, s1, s2, n, m));

    return 0;
}