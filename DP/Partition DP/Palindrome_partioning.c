#include <stdio.h>
#include <string.h>

char str[20];
int n;

/*
PROBLEM STATEMENT:
Palindrome Partitioning

Given a string, print all possible partitions such that every substring is a palindrome.

--------------------------------------------------

APPROACH (INTUITION):

- Start from index i
- Try all possible substrings from i to j
- If substring (i → j) is palindrome:
    → include it in current partition
    → recurse for remaining string (j+1)
- Base case:
    if i == n → print current partition

- Use a helper function to check palindrome
*/

int isPalindrome(int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) return 0;
        start++;
        end--;
    }
    return 1;
}

void partition(int i, char result[20][20], int len) {
    if (i == n) {
        for (int k = 0; k < len; k++)
            printf("%s ", result[k]);
        printf("\n");
        return;
    }

    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j)) {
            int idx = 0;
            for (int k = i; k <= j; k++)
                result[len][idx++] = str[k];
            result[len][idx] = '\0';

            partition(j + 1, result, len + 1);
        }
    }
}

int main() {
    scanf("%s", str);
    n = strlen(str);

    char result[20][20];

    printf("Palindrome partitions:\n");
    partition(0, result, 0);

    return 0;
}