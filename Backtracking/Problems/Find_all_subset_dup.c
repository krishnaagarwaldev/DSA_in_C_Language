#include <stdio.h>
#include <stdlib.h>

/*
PROBLEM:
Print all UNIQUE subsets (array may contain duplicates)

APPROACH:
1. Sort array
2. Use backtracking
3. Skip duplicates:
   if (i > index && nums[i] == nums[i-1]) → skip
*/

void printSubset(int subset[], int size) {
    printf("{");
    for (int i = 0; i < size - 1; i++) {
        printf("%d,", subset[i]);
    }
    if (size > 0) printf("%d", subset[size - 1]);
    printf("}\n");
}

// comparison function for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void subsetsUnique(int index, int nums[], int n, int subset[], int size) {
    // print every state (not just base case)
    printSubset(subset, size); // Here, base case is when index == n, but we want to print all subsets including empty set

    for (int i = index; i < n; i++) {
        if (i > index && nums[i] == nums[i - 1]) // skip duplicates
            continue;

        subset[size] = nums[i];
        subsetsUnique(i + 1, nums, n, subset, size + 1); // take, here not take is handled by skipping duplicates
    }
}

int main() {
    int nums[] = {1, 2, 2};
    int n = 3;

    // step 1: sort
    qsort(nums, n, sizeof(int), cmp);

    int subset[100];

    subsetsUnique(0, nums, n, subset, 0);

    return 0;
}