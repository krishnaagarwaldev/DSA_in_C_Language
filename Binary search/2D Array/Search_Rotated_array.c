/*
QUESTION:-
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:
Input:  matrix = [[1,3,5,7]
                [10,11,16,20]
                [23,30,34,60]]
        target = 3
Output: true
*/

/*
APPROACH:-
-> Since the array is sorted we can use binary search low = 0 and high = n*m-1 i.e. total number of elements
-> Value at mid position could be accessed by matrix[mid/m][mid%m]
-> Then, follow the traditional binary search
*/

// TIME COMPLEXITY = O(log(M * N))
// SPACE COMPLEXITY = O(0)

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int matrix[][100], int n, int m, int target){
    int low = 0;
    int high = n * m - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        int row = mid / m; //m is number of columns
        int col = mid % m;

        int value = matrix[row][col];

        if(value == target)
            return true;
        else if(value > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

int main()
{
    int matrix[3][100] = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int n = 3;
    int m = 4;
    int target = 3;

    if(searchMatrix(matrix, n, m, target))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}