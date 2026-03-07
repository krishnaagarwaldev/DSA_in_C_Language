#include <stdio.h>
#include <string.h>

// Swap function
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(char arr[], int low, int high){
    char pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){   // ascending order{
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(char arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function required by GFG
char* sort(char *S){
    int n = strlen(S);
    quickSort(S, 0, n - 1);
    return S;
}

int main(){
    char str[] = "geeksforgeeks";
    printf("Sorted String: %s\n", sort(str));
    return 0;
}