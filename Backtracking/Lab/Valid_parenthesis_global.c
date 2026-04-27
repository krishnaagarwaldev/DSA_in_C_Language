#include <stdio.h>

char str[100];
int count = 0;
int n;

void solve(int curr, int left, int right){
    // If string length becomes 2*n, print it
    if(curr == 2*n){  //or if(right == n)
        str[curr] = '\0';
        printf("%s\n", str);
        count++;
        return;
    }

    // Add '(' if left parentheses are still available
    if(left < n){
        str[curr] = '(';
        solve(curr+1, left+1, right);
    }

    // Add ')' only if right < left
    if(right < left){
        str[curr] = ')';
        solve(curr+1, left, right+1);
    }
}

int main(){
    scanf("%d",&n);

    solve(0, 0, 0);
    printf("Total = %d\n",count);
    return 0;
}