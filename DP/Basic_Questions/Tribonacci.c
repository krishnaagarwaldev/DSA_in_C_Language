// Tribonacci number 

#include <stdio.h>
#include <string.h>

int dp[100];

int tribonacci(int n){
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main(){
    int n = 10; // 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149
    memset(dp, -1, sizeof(dp));

    printf("Tribonacci: %d", tribonacci(n));
    return 0;
}