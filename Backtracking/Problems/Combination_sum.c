#include <stdio.h>

int comb[100];  // to store current combination

/*
---------------------------------------------------------
PROBLEM STATEMENT:
Given an array of distinct integers and a target sum,
find all unique combinations such that the chosen
numbers sum to the target.

Each element can be used multiple times.

---------------------------------------------------------
IDEA:
We use backtracking to explore all possibilities.
At each step, we have 2 choices:
1. Take the current element (stay at same index)
2. Skip the current element (move to next index)

---------------------------------------------------------
LOGIC:
1. If target becomes 0 → valid combination → print
2. If target < 0 → invalid → stop
3. If index reaches n → stop

4. Take current element:
   - Add to comb[]
   - Reduce target
   - Call again with SAME index (reuse allowed)

5. Not take:
   - Move to next index

---------------------------------------------------------
RECURSION FLOW:
Example: arr = {2,3,5}, target = 5 Answer: {2,3}, {5}
eg. arr = {2,3,6,7}, target = 6 Answer: {2,2,2}, {3,3}, {6}

eg. arr = {2,3,6,7}, target = 7
Answer: {2,2,3}, {7}

---------------------------------------------------------
BACKTRACKING STEP:
After taking an element, we return and try next option
(no explicit removal needed due to index control)

---------------------------------------------------------
TIME COMPLEXITY:
Exponential (approx O(2^target))

SPACE COMPLEXITY:
O(target) recursion stack

---------------------------------------------------------
*/

void combinationSum(int arr[], int n, int target, int index, int size) {

    // Base case: if target becomes 0 → print combination
    if (target == 0) {
        printf("{");
        for (int i = 0; i < size; i++) {
            printf("%d,", comb[i]);
        }
        printf("}\n");
        return;
    }

    // If target becomes negative OR index out of bounds
    if (target < 0 || index == n) {
        return;
    }
    comb[size] = arr[index];  // TAKE current element
    combinationSum(arr, n, target - arr[index], index, size + 1); // Recur with same index to allow reuse
    combinationSum(arr, n, target, index + 1, size); //Not take, move to next index
}

int main() {
    int arr[] = {2, 3, 6, 7};
    int n = 4;
    int target = 6;

    combinationSum(arr, n, target, 0, 0);

    return 0;
}