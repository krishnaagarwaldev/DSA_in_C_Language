#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function
int compare(const void *a, const void *b)
{
    char *str1 = (char *)a;
    char *str2 = (char *)b;

    return strcmp(str1, str2);  // lexicographic compare
}

int main()
{
    char arr[][100] = {"banana", "apple", "dog", "cat"};
    int n = 4;

    qsort(arr, n, sizeof(arr[0]), compare);

    printf("Sorted Strings:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return 0;
}