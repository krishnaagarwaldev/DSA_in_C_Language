// Problem 1 -> Min Cost (solution 2 from last)

#include <stdio.h>
#include <string.h>

#define Max 100

int DP[Max][Max];

int Minimum(int p, int q, int r){
    int t = p;
    if (q < t) t = q;
    if (r < t) t = r;
    return t;
}

int MinCost(char x[], char y[], int a, int b){
    if (a == 0) return b;
    if (b == 0) return a;

    if (DP[a][b] != -1){
        return DP[a][b];
    }

    if (x[a - 1] == y[b - 1]){
        return DP[a][b] = LCS(x, y, a - 1, b - 1);
    }

    int i1 = MinCost(x, y, a, b - 1) + 1;
    int i2 = MinCost(x, y, a - 1, b) + 1;
    int i3 = MinCost(x, y, a - 1, b - 1) + 2;

    return DP[a][b] = Minimum(i1, i2, i3);
}


int main(){
    char str1[Max], str2[Max];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int l1 = strlen(str1), l2 = strlen(str2);

    for (int p = 0; p <= l1; p++)
        for (int q = 0; q <= l2; q++)
            DP[p][q] = -1;

    int ans = MinCost(str1, str2, l1, l2);

    printf("\nDP Table:\n");
    for (int p = 0; p <= l1; p++){
        for (int q = 0; q <= l2; q++)
            printf("%2d ", DP[p][q]);
        printf("\n");
    }

    printf("\nDistance: %d\n", ans);
    int p = l1, q = l2;
    printf("\nOps:\n");

    return 0;
}