// C Program to right rotate the array by d positions
// by rotating one element at a time

#include <stdio.h>

// Function to right rotate array by d positions
void rotateArr(int arr[], int n, int d) {
    
    // Repeat the rotation d times
    for (int i = 0; i < d; i++) {
      
        // Right rotate the array by one position
        int last = arr[n - 1];
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;      
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    rotateArr(arr, n, d);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}