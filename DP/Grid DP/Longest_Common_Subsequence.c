#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Longest Common Subsequence (LCS)

Given two strings s1 and s2, find:
1) Length of longest common subsequence
2) Print the LCS string

--------------------------------------------------

APPROACH (INTUITION):

- First compute LCS length using memoization

- Then reconstruct the LCS string:
    Start from (0,0)
    
    If s1[i] == s2[j]:
        → include this character in answer
        → move (i+1, j+1)

    Else:
        → move in direction of maximum value:
            if dp[i+1][j] > dp[i][j+1] → i++
            else → j++

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

// LCS with memoization
int lcs(int i, int j, char s1[], char s2[], int n, int m) {
    if (i == n || j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + lcs(i + 1, j + 1, s1, s2, n, m);
    }

    return dp[i][j] = max(
        lcs(i + 1, j, s1, s2, n, m),
        lcs(i, j + 1, s1, s2, n, m)
    );
}

int main() {
    char s1[] = "abcde";
    char s2[] = "ace";

    int n = strlen(s1);
    int m = strlen(s2);

    memset(dp, -1, sizeof(dp));

    int length = lcs(0, 0, s1, s2, n, m);
    printf("LCS Length: %d\n", length);

    // reconstruct LCS string
    char lcs_str[1000];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (s1[i] == s2[j]) {
            lcs_str[k++] = s1[i];
            i++;
            j++;
        } 
        else {
            if (dp[i + 1][j] > dp[i][j + 1])
                i++;
            else
                j++;
        }
    }

    lcs_str[k] = '\0';

    printf("LCS String: %s\n", lcs_str);

    return 0;
}

/* DP Grid 
DP -> Longest Common Subsequence (LCS) Length
eg. s1 = "abcde", s2 = "ace"
Grid:
   a  c  e
a  1  1  1
b  1  1  1
c  1  2  2
d  1  2  2
e  1  2  3

Here, dp[i][j] = length of LCS from s1[i..] and s2[j..]
If s1[i] == s2[j] → 1 + LCS(i+1, j+1) eg. at a,a (0,0) → 1 + LCS(1,1) = 1 + 1 = 2
Else → max(LCS(i+1, j), LCS(i, j+1)) eg. at b,c (1,1) → max(1, 1) = 1
*/