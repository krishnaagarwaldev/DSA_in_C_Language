#include <stdio.h>

int count = 0;

void solve(char str[], int n, int curr, int open, int close){
    // If all closing brackets are used
    if(close == n){  //or if(curr == 2*n)
        str[curr] = '\0';
        printf("%s\n", str);
        count++;
        return;
    }

    // Add '(' if we still have open brackets
    if(open < n){
        str[curr] = '(';
        solve(str, n, curr+1, open+1, close);
    }

    // Add ')' if valid
    if(close < open){
        str[curr] = ')';
        solve(str, n, curr+1, open, close+1);
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    char str[100];

    solve(str, n, 0, 0, 0);
    printf("Total = %d\n", count);
    return 0;
}