#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main() {

// Function to print a 2D array
void print2DArray(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
// Function to initialize a 2D array with random values
void initialize2DArray(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100; // Random values between 0 and 99
        }
    }
}

int arr[2][3] = {2,5,4,4,7,8}; // Declare a 2D array with 2 rows and 3 columns
int arr9[2][3] = {{1,2,3},{4,5,6}}; // Another 2D array for demonstration
int arr3[][3] = {{1,2,3},{4,5,6}}; // Another 2D array for demonstration

//addition of two matrices
int arr2[2][3] = {1,2,3,4,5,6}; // Another 2D array for addition
int result[2][3]; // Resultant array for addition
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        result[i][j] = arr[i][j] + arr2[i][j]; // Adding corresponding elements
    }
}

//Sum of two matrices without using extra array
int sum = 0; // Variable to store the sum of elements
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        arr[i][j] += arr2[i][j]; // Adding directly to the first array
        sum = sum + arr[i][j]; // Calculate the sum of elements
    }
}

// Print the original and resultant arrays
printf("Resultant Array after Addition:\n");
print2DArray(2, 3, result);

//max row sum
int maxRowSum = 0; // Variable to store the maximum row sum
for (int i = 0; i < 2; i++) {   
    int rowSum = 0; // Variable to store the sum of the current row
    for (int j = 0; j < 3; j++) {
        rowSum += arr[i][j]; // Calculate the sum of the current row
    }   
    if (rowSum > maxRowSum) {
        maxRowSum = rowSum; // Update the maximum row sum if current row sum is greater
    }
}
printf("Maximum Row Sum: %d\n", maxRowSum);

    return 0;
}
