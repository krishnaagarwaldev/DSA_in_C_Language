#include <stdio.h>

int comb[100];  // to store current combination

/*
---------------------------------------------------------
PROBLEM STATEMENT:
Given an array of n elements, generate all possible
combinations of size k using backtracking.

---------------------------------------------------------
IDEA:
We use backtracking to generate combinations.
At each step, we choose an element and move forward.

---------------------------------------------------------
LOGIC:
1. Start from index 'start'
2. Pick elements one by one
3. Store them in comb[]
4. When size becomes k → print combination
5. Move forward (i+1) to avoid repetition

---------------------------------------------------------
RECURSION FLOW:
Example: arr = {1,2,3}, k = 2

Start from 0:
Pick 1 → Pick 2 → print {1,2}
         Pick 3 → print {1,3}

Pick 2 → Pick 3 → print {2,3}

---------------------------------------------------------
BACKTRACKING STEP:
After recursion, we simply return and try next element
(no explicit undo needed as we overwrite values)

---------------------------------------------------------
TIME COMPLEXITY:
O(nCk) → number of combinations

SPACE COMPLEXITY:
O(k) → recursion stack + array

---------------------------------------------------------
*/

void generateCombinations(int arr[], int n, int k, int start, int index) {

    // Base case: if combination size becomes k
    if (index == k) {
        printf("{");
        for (int i = 0; i < k; i++) {
            printf("%d,", comb[i]);
        }
        printf("}\n");
        return;
    }

    // Try all elements starting from 'start'
    for (int i = start; i < n; i++) {
        comb[index] = arr[i];  // Choose element

        // Recur for next index (i+1 ensures no repetition)
        generateCombinations(arr, n, k, i + 1, index + 1);

        // Backtrack happens automatically
        // (no explicit undo needed)
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;
    int k = 2;

    generateCombinations(arr, n, k, 0, 0);

    return 0;
}