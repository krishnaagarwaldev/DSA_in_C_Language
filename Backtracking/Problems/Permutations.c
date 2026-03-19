#include <stdio.h>

// swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to generate permutations
void generatePermutations(int arr[], int n, int index) {
    
    // Base case: if index reaches end, print permutation
    if (index == n) {
        printf("{");
        for (int i = 0; i < n; i++) {
            printf("%d,", arr[i]);
        }
        printf("}\n");
        return;
    }

    // try placing each element at current position
    for (int i = index; i < n; i++) {
        swap(&arr[index], &arr[i]); // Choose: swap current element with element at index
        generatePermutations(arr, n, index + 1); // Explore: recursively generate permutations for next index
        
        swap(&arr[index], &arr[i]); // Backtrack: undo swap, Not choose: swap back to restore original array
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;

    generatePermutations(arr, n, 0);

    return 0;
}