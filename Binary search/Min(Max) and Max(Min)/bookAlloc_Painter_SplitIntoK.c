/*
def pagescheck(arr, pages):
    n = len(arr)  # size of array
    students = 1
    pagesStudent = 0
    for i in range(n):
        if pagesStudent + arr[i] <= pages:
            # add pages to current student
            pagesStudent += arr[i]
        else:
            # add pages to next student
            students += 1
            pagesStudent = arr[i]
    return students


def findPages(arr: list[int], n: int, m: int) -> int:
    # Write your code here
    if m > n:
        return -1

    low = max(arr)
    high = sum(arr)
    while low <= high:
        mid = (low + high) // 2
        count = pagescheck(arr, mid)
        if count > m:
            low = mid + 1
        else:
            high = mid - 1
    return low

# Link: https://www.codingninjas.com/studio/problems/allocate-books_1090540
*/

/*
Question:
You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.

Example:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output: 113
Explanation:
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.

Approach:
- We can use binary search to find the minimum number of pages that can be allocated to the student with the most pages.
- The range for binary search will be from the minimum number of pages in the array to the sum of all the pages in the array.
- For each mid value, we will check if it is possible to allocate the books in a way that the maximum number of pages for a student is less than or equal to mid.
- To check this, we iterate through the array of pages and keep track of the number of students and the sum of pages allocated to the current student.
- If at any point, the sum exceeds the mid value, we increment the number of students and reset the sum to the current page value.
- If the number of students exceeds the given M, it means we need more students to allocate the pages, so we return false.
- If at the end, the number of students is less than or equal to M, it means it is possible to allocate the pages within the given constraints, so we return true.
- Finally, we perform binary search and find the minimum mid value that returns true in the isPossible function.

Code:
*/

#include <stdio.h>
#include <stdlib.h>

int isPossible(int arr[], int n, int students, int maxPages) {
    int count = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + arr[i] > maxPages) {
            count++;
            sum = arr[i];
            if (count > students)
                return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int bookAllocation_PainterPartition_SplitIntoK(int arr[], int n, int students) {
    int low = arr[0], high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];  // low = maximum pages in a single book
        high += arr[i];    // high = sum of all pages
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, students, mid)) {
            ans = mid;
            high = mid - 1;   // minimize
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

/*
Time Complexity: O(N log S), where N is the number of books and S is the sum of all the pages in the array. The binary search takes log S iterations, and for each iteration, we check the validity of allocation in O(N) time.
Space Complexity: O(1), as we are using a constant amount of extra space.
*/

/*🔥 3️⃣ Painter’s Partition (Same as Book Allocation)
📌 Problem

Boards of length given.
Painters paint continuous boards.
Minimize maximum time.

Exactly SAME LOGIC as Book Allocation.*/

/*
Question: Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.

Example:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays. The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Approach:
- The problem can be solved using the binary search algorithm.
- We need to find the range of possible values for the minimized largest sum.
- The lower bound of the range is the maximum element in the array (as each subarray must contain at least one element).
- The upper bound of the range is the sum of all elements in the array (as the largest sum cannot exceed the total sum of the array).
- We perform binary search within this range to find the minimum largest sum that satisfies the given condition.
- In each iteration, we calculate the mid value of the range and check if it is a valid solution using a helper function.
- The helper function checks if it is possible to split the array into k subarrays with a maximum sum of mid.
- If it is possible, we update the answer and search the lower half of the range.
- If it is not possible, we search the upper half of the range.
- We continue this process until we find the optimal solution.

Time Complexity: O(n * log(sum of array))
Space Complexity: O(1)
*/

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int students = 2;

    int result = bookAllocation_PainterPartition_SplitIntoK(arr, n, students);
    printf("Minimum number of pages allocated to the student with the most pages: %d\n", result);

    int painters = 2;
    int painterResult = bookAllocation_PainterPartition_SplitIntoK(arr, n, painters);
    printf("Minimum time to paint all boards: %d\n", painterResult);

    int split_into_k = 2;
    int splitResult = bookAllocation_PainterPartition_SplitIntoK(arr, n, split_into_k);
    printf("Minimum time to paint all boards: %d\n", splitResult);

    return 0;
}


