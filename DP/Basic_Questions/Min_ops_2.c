#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Minimum Number of Operations to Reduce n to 1

Given a number n, you can perform these operations:
1) Subtract 1
2) If divisible by 2 → divide by 2
3) If divisible by 3 → divide by 3

Find the minimum number of operations required to reduce n to 1.

--------------------------------------------------

APPROACH (INTUITION):

- Let minOps(n) = minimum operations to reduce n to 1
- Choices:
    1) Subtract 1 → 1 + minOps(n-1)
    2) If n % 2 == 0 → 1 + minOps(n/2)
    3) If n % 3 == 0 → 1 + minOps(n/3)
- Take minimum of all valid choices
- Base case: n == 1 → 0 operations
- Use memoization to avoid recomputation
*/

int dp[1000];

int minOperations(int n) {
    if (n == 1) return 0;

    if (dp[n] != -1) return dp[n];

    int op1 = 1 + minOperations(n - 1);
    int op2 = (n % 2 == 0) ? 1 + minOperations(n / 2) : 1000000;
    int op3 = (n % 3 == 0) ? 1 + minOperations(n / 3) : 1000000;

    int min = (op1 < op2) ? op1 : op2;
    min = (min < op3) ? min : op3;

    return dp[n] = min;
}

int main() {
    int n;
    scanf("%d", &n);

    memset(dp, -1, sizeof(dp));

    printf("Minimum operations to reduce %d to 1: %d\n", n, minOperations(n));

    return 0;
}