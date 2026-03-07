#include <stdio.h>
#include <string.h>

int main(){
    char arr[][100] = {"banana", "apple", "dog", "cat"};
    int n = 4;
    char temp[100];
    // Bubble Sort
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(strcmp(arr[j], arr[j+1]) > 0){
                // swap strings
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
    printf("Sorted Strings:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    return 0;
}