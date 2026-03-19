#include <stdio.h>
#include <string.h>

/*
PROBLEM STATEMENT:
Print Optimal Parenthesization (MCM)

Along with minimum cost, print the optimal way to parenthesize matrices.

--------------------------------------------------

APPROACH (INTUITION):

- Same as MCM, but also store split index k

- Use another table:
    split[i][j] = index k where optimal split occurs

- After computing dp, reconstruct answer using split table

--------------------------------------------------
*/

int dp2[100][100];
int split[100][100];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int mcmPrint(int i, int j, int arr[]) {
    if (i == j)
        return 0;

    if (dp2[i][j] != -1)
        return dp2[i][j];

    int ans = 1e9;

    for (int k = i; k < j; k++) {
        int cost =
            mcmPrint(i, k, arr) +
            mcmPrint(k + 1, j, arr) +
            arr[i - 1] * arr[k] * arr[j];

        if (cost < ans) {
            ans = cost;
            split[i][j] = k; // store partition
        }
    }

    return dp2[i][j] = ans;
}

// function to print parenthesis
void printOrder(int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }

    printf("(");
    printOrder(i, split[i][j]);
    printOrder(split[i][j] + 1, j);
    printf(")");
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = 4;

    memset(dp2, -1, sizeof(dp2));

    int cost = mcmPrint(1, n - 1, arr);

    printf("Minimum Cost: %d\n", cost);

    printf("Optimal Parenthesization: ");
    printOrder(1, n - 1);
    printf("\n");

    return 0;
}