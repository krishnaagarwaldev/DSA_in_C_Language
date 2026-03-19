#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Palindrome Partitioning (Minimum Cuts)

Given a string s, partition it such that every substring is a palindrome.  
Return the minimum number of cuts needed.

Example:
"geek" → "g | ee | k" → Output: 2

--------------------------------------------------

APPROACH (INTUITION):

- At index i, try all possible partitions (i → j)
- If substring s[i..j] is palindrome:
    → make 1 cut + solve for remaining (j+1)
- Take minimum over all possible cuts

- Base case:
    if i == n → return -1 (no cut needed after last partition)

- Why return -1?
    → because last partition does not need a cut

- Memoize results in dp[i]
*/

char str[100];
int dp[100];
int n;

int isPalindrome(int l, int r) {
    while (l < r) {
        if (str[l] != str[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

int minCuts(int i) {
    if (i == n) return -1;  // no cut needed at end

    if (dp[i] != -1) return dp[i];

    int min = 1000000;

    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j)) {
            int cuts = 1 + minCuts(j + 1);
            if (cuts < min) min = cuts;
        }
    }

    return dp[i] = min;
}

int main() {
    scanf("%s", str);
    n = strlen(str);

    memset(dp, -1, sizeof(dp));

    printf("Minimum cuts: %d\n", minCuts(0));

    return 0;
}