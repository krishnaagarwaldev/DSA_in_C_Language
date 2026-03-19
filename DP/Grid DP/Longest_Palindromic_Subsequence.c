#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Longest Palindromic Subsequence (LPS)

Given a string s, find:
1) Length of the longest subsequence which is a palindrome
2) Print that subsequence

Example:
s = "bbbab"
Output:
Length = 4
LPS = "bbbb"

--------------------------------------------------

APPROACH (INTUITION):

- LPS is same as LCS between:
    s and reverse(s)

- So:
    LPS(s) = LCS(s, reverse(s))

- First compute LCS using memoization
- Then reconstruct the string

- State:
    dp[i][j] = LCS length from s[i..] and rev[j..]

- Base case:
    if i == n OR j == n → return 0

--------------------------------------------------
*/

int dp[1000][1000];

int max(int a, int b) {
    return (a > b) ? a : b;
}

// LCS (memoization)
int lcs(int i, int j, char s1[], char s2[], int n) {
    if (i == n || j == n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + lcs(i + 1, j + 1, s1, s2, n);
    }

    return dp[i][j] = max(
        lcs(i + 1, j, s1, s2, n),
        lcs(i, j + 1, s1, s2, n)
    );
}

int main() {
    char s[] = "bbbab";
    int n = strlen(s);

    // reverse string
    char rev[1000];
    for (int i = 0; i < n; i++) {
        rev[i] = s[n - i - 1];
    }
    rev[n] = '\0';

    memset(dp, -1, sizeof(dp));

    int length = lcs(0, 0, s, rev, n);
    printf("LPS Length: %d\n", length);

    // reconstruct LPS string
    char lps[1000];
    int i = 0, j = 0, k = 0;

    while (i < n && j < n) {
        if (s[i] == rev[j]) {
            lps[k++] = s[i];
            i++;
            j++;
        } else {
            if (dp[i + 1][j] > dp[i][j + 1])
                i++;
            else
                j++;
        }
    }

    lps[k] = '\0';

    printf("LPS String: %s\n", lps);

    return 0;
}