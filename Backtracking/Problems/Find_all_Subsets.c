#include <stdio.h>

/*
PROBLEM STATEMENT:
Subsets (Power Set)

Given an array nums[], print all possible subsets (the power set).

Example:
nums = [1,2,3]

Output:
{}
{1}
{2}
{3}
{1,2}
{1,3}
{2,3}
{1,2,3}

--------------------------------------------------

APPROACH (BACKTRACKING - TAKE / NOT TAKE):

- At each index i, we have two choices:
    1) Include nums[i] in current subset
    2) Exclude nums[i]

- We explore all possibilities recursively

- Base case:
    if i == n → print current subset

- This generates all 2^n subsets

--------------------------------------------------
*/

void printSubset(int subset[], int size) {
    printf("{");
    for (int i = 0; i < size-1; i++) {
        printf("%d,", subset[i]);
    }
    if (size > 0) {
        printf("%d", subset[size-1]);
    }
    printf("}\n");
}

void subsets(int i, int nums[], int n, int subset[], int size) {
    // base case
    if (i == n) {
        printSubset(subset, size);
        return;
    }

    // take
    subset[size] = nums[i]; // include nums[i] in subset
    subsets(i + 1, nums, n, subset, size + 1);

    // not take
    subsets(i + 1, nums, n, subset, size);
}






void stored_subsets(int i, int nums[], int n, int subset[], int size, int all_subsets[][100], int subset_size[], int *count) {
    // base case
    if (i == n) {
        // store current subset in all_subsets
        for (int j = 0; j < size; j++) {
            all_subsets[*count][j] = subset[j];
        }
        subset_size[*count] = size;
        (*count)++;
        return;
    }

    // take
    subset[size] = nums[i]; // include nums[i] in subset
    stored_subsets(i + 1, nums, n, subset, size + 1, all_subsets, subset_size, count);

    // not take
    stored_subsets(i + 1, nums, n, subset, size, all_subsets, subset_size, count);
}


int main() {
    int nums[] = {1, 2, 3};
    int n = 3;

    int subset[100];
    //subsets(0, nums, n, subset, 0);




    int all_subsets[100][100];
    int subset_size[100];
    int count = 0;

    stored_subsets(0, nums, n, subset, 0, all_subsets, subset_size, &count);

    // for (int i = 0; i < count; i++) {
    //     printSubset(all_subsets[i], subset_size[i]);
    // }


    

    // PRINT AS 2D ARRAY FORMAT
    printf("{");
    for (int i = 0; i < count; i++) {
        printf("{");

        for (int j = 0; j < subset_size[i]; j++) {
            printf("%d", all_subsets[i][j]);
            if (j < subset_size[i] - 1) {
                printf(",");
            }
        }
        printf("}");

        if (i < count - 1) {
            printf(",");
        }
    }
    printf("}\n");


    return 0;
}