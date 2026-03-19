#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Minimum Number of Operations to Reach n from 1

Starting from 1, you can perform:
1) Add 1 → x + 1
2) Multiply by 2 → x * 2

Find the minimum number of operations to reach n.

--------------------------------------------------

APPROACH (INTUITION):

- Let minOps(n) = minimum operations to reach n from 1
- Choices (working backwards):
    1) If n is even → could have come from n/2 → 1 + minOps(n/2)
    2) Could have come from n-1 → 1 + minOps(n-1)
- Take minimum of both options
- Base case: n == 1 → 0 operations (already at 1)
- Use memoization to avoid recomputation
*/

int dp[1000];

int minOperations(int n) {
    if (n == 1) return 0;

    if (dp[n] != -1) return dp[n];

    int op1 = 1 + minOperations(n - 1);
    int op2 = (n % 2 == 0) ? 1 + minOperations(n / 2) : 1000000;

    int min = (op1 < op2) ? op1 : op2;

    return dp[n] = min;
}




int minOperations_2(int x, int n) {
    if (x==n) return 0; 
    if (x>n) return 1000000;

    if (dp[x] != -1) return dp[x];
    int op1 = 1 + minOperations_2(x + 1, n);
    int op2 = 1 + minOperations_2(x * 2, n);
    int min = (op1 < op2) ? op1 : op2;
    return dp[x] = min;
}
    


int main() {
    int n;
    scanf("%d", &n);

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    // Print the minimum number of operations required to reach n from 1
    //printf("Minimum operations to reach %d from 1: %d\n", n, minOperations(n));

    int x = 1; // Starting point
    printf("Minimum operations to reach %d from %d: %d\n", n, x, minOperations_2(x, n));

    return 0;
}