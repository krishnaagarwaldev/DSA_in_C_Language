#include <stdio.h>

#define N 4

// Function to rotate the matrix by 90 degrees clockwise
void rotate90(int mat[N][N]) {
    int res[N][N] = {0}; 

    // Flip the matrix clockwise using nested loops
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[j][N - i - 1] = mat[i][j];
        }
    }

    // Copy result back to mat
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = res[i][j];
        }
    }
}

int main() {
    int mat[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotate90(mat);

    // Print the rotated matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}