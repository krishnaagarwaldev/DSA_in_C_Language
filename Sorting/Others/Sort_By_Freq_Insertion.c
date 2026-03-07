#include <stdio.h>
#include <string.h>

int main(){
    char arr[][100] = {"banana", "apple", "dog", "cat"};
    int n = 4;
    char key[100];

    // Insertion Sort
    for(int i = 1; i < n; i++){
        strcpy(key, arr[i]);
        int j = i - 1;

        while(j >= 0 && strcmp(arr[j], key) > 0){
            strcpy(arr[j+1], arr[j]);
            j--;
        }
        strcpy(arr[j+1], key);
    }
    printf("Sorted Strings:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return 0;
}