#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Longest Common Substring

Given two strings s1 and s2, find the length of the
longest substring (continuous) common in both.

Example:
s1 = "abcde"
s2 = "abfce"
Output = 2 ("ab")

--------------------------------------------------

APPROACH (INTUITION):

- If characters match:
    → 1 + solve(i-1, j-1)
- If not match:
    → substring breaks → return 0

- We try all (i,j) and take maximum

- dp[i][j] stores length of longest common substring ending at i,j
*/

int dp[100][100];
int maxLen = 0;

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Same as LCS but reset to 0 if characters do not match
int lcsSubstring(int i, int j, char s1[], char s2[]) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) {
        dp[i][j] = 1 + lcsSubstring(i - 1, j - 1, s1, s2);
        // if (dp[i][j] > maxLen){
        //     maxLen = dp[i][j];
        // }
        maxLen = max(maxLen, dp[i][j]);
    }
    else{
        dp[i][j] = 0;
    }

    // Important: explore all possibilities
    lcsSubstring(i - 1, j, s1, s2);
    lcsSubstring(i, j - 1, s1, s2);

    return dp[i][j];
}

int main() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);

    int n = strlen(s1), m = strlen(s2);

    memset(dp, -1, sizeof(dp));

    lcsSubstring(n - 1, m - 1, s1, s2);

    printf("Longest Common Substring length: %d\n", maxLen);

    return 0;
}