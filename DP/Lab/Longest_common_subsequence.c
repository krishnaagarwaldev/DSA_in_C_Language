// Problem 2 -> Longest Common Subsequence

#include <stdio.h>
#include <string.h>

#define Max 100

int Maximum(int a, int b){
    if (a > b) return a;
    return b;
}

int main(){
    char s[Max], t[Max];
    int mat[Max][Max];

    printf("Enter first string: ");
    scanf("%s", s);

    printf("Enter second string: ");
    scanf("%s", t);

    int n1 = strlen(s), n2 = strlen(t);

    for (int r = 0; r <= n1; r++){
        mat[r][0] = 0;
    }
    for (int c = 0; c <= n2; c++){
        mat[0][c] = 0;
    }

    for (int r = 1; r <= n1; r++){
        for (int c = 1; c <= n2; c++){
            if (s[r - 1] == t[c - 1]){
                mat[r][c] = mat[r - 1][c - 1] + 1;
            }
            else{
                mat[r][c] = Maximum(mat[r - 1][c], mat[r][c - 1]);
            }
        }
    }

    printf("\nTable:\n");
    for (int r = 0; r <= n1; r++){
        for (int c = 0; c <= n2; c++)
            printf("%2d ", mat[r][c]);
        printf("\n");
    }

    printf("\nLCS length: %d\n", mat[n1][n2]);

    char ans[Max];
    int r = n1, c = n2, k = mat[n1][n2];

    ans[k] = '\0';

    while (r > 0 && c > 0){
        if (s[r - 1] == t[c - 1]){
            ans[k - 1] = s[r - 1];
            r--;
            c--;
            k--;
        }
        else if (mat[r - 1][c] >= mat[r][c - 1]){
            r--;
        }
        else{
            c--;
        }
    }
    printf("LCS: %s\n", ans);

    return 0;
}
