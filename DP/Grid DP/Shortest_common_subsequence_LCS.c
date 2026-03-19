#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Shortest Common Supersequence (Print String)

Using LCS, build the shortest string that contains both s1 and s2.

--------------------------------------------------

APPROACH:

- First compute LCS dp table
- Then build answer:

    If s1[i] == s2[j]:
        → add once, move both

    Else:
        → take from side with larger LCS
*/

int dp[100][100];

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
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);

    int n = strlen(s1), m = strlen(s2);

    memset(dp, -1, sizeof(dp));
    lcs(0, 0, s1, s2, n, m); // fill dp

    int i = 0, j = 0;
    char ans[200];
    int k = 0;

    // build SCS
    while (i < n && j < m) {
        if (s1[i] == s2[j]) {
            ans[k++] = s1[i];
            i++; j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1]) {
            ans[k++] = s1[i];
            i++;
        }
        else {
            ans[k++] = s2[j];
            j++;
        }
    }

    // add remaining characters
    while (i < n) ans[k++] = s1[i++];
    while (j < m) ans[k++] = s2[j++];

    ans[k] = '\0';

    printf("SCS String: %s\n", ans);

    return 0;
}