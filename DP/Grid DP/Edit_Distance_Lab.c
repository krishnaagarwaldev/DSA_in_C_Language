#include<stdio.h>
#include<string.h>

int dp[101][101];

// Problem 1 -> Min Cost (solution 1 from first)
// Given two strings word1 and word2, find the minimum number of operations
// required to convert word1 into word2.

// Allowed operations:
// 1) Insert -> Cost = 1
// 2) Delete -> Cost = 1
// 3) Replace -> Cost = 2


int min(int a, int b){
    return (a < b) ? a : b;
}

int MinCost(char str1[], char str2[], int i, int j){
    if (i == strlen(str1)){
        return strlen(str2) - j;
    }
    if (j == strlen(str2)){
        return strlen(str1) - i;
    }
    
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    
    if (str1[i]==str2[j]){
        return dp[i][j] = MinCost(str1, str2, i+1, j+1);
    }
    else{
        int insert = 1 + MinCost(str1, str2, i, j+1);
        int del = 1 + MinCost(str1, str2, i+1, j);
        int replace = 2 + MinCost(str1, str2, i+1, j+1);
        
        int minimum = insert;
        if (del < minimum){
            minimum = del;
        }
        if (replace < minimum){
            minimum = replace;
        }
        return dp[i][j] = minimum;
        // return dp[i][j] = min(min(insert, del), replace);
    }
}

int main(){
    
    // char str1[100];
    // char str2[100];
    // scanf("%s", str1);
    // scanf("%s", str2);
    
    // printf("%s %s",str1, str2);
    
    // int n1 = 0;
    // while(str1 != '\0'){
    //     n1++;
    // }
    
    // int n2 = 0;
    // while(str2 != '\0'){
    //     n2++;
    // }
    char str1[] = "horse";;
    char str2[] = "ros";
    
    memset(dp, -1, sizeof(dp));
    
    int ans = MinCost(str1,str2,0,0);
    printf("Min Cost is %d\n", ans);
    
    
    for (int i=0; i<strlen(str1); i++){
        for (int j=0; j<strlen(str2); j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}

