#include <stdio.h>

void solve(char str[], int n, int curr, int left, int right, int *count){
    // If string length becomes 2*n, print it
    if(curr == 2*n){  //or if(right == n)
        str[curr] = '\0';
        printf("%s\n", str);
        (*count)++;
        return;
    }

    // Add '(' if left parentheses are still available
    if(left < n){
        str[curr] = '(';
        solve(str, n, curr+1, left+1, right, count);
    }

    // Add ')' only if right < left
    if(right < left){
        str[curr] = ')';
        solve(str, n, curr+1, left, right+1, count);
    }
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    char str[100];
    int count = 0;

    solve(str, n, 0, 0, 0, &count);
    printf("Total = %d\n",count);
    return 0;
}